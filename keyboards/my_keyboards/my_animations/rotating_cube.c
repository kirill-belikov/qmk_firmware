#include "quantum.h"

// A 64-step sine table in Q7 keeps the OLED task integer-only and lightweight.
static const int8_t sin_q7[64] PROGMEM = {
    0, 12, 25, 37, 49, 60, 71, 81, 90, 98, 106, 112, 117, 122, 125, 126,
    127, 126, 125, 122, 117, 112, 106, 98, 90, 81, 71, 60, 49, 37, 25, 12,
    0, -12, -25, -37, -49, -60, -71, -81, -90, -98, -106, -112, -117, -122, -125, -126,
    -127, -126, -125, -122, -117, -112, -106, -98, -90, -81, -71, -60, -49, -37, -25, -12,
};

static uint8_t animation_frame;
static uint32_t last_frame_time;

static int16_t sin_at(uint8_t phase) {
    return (int8_t)pgm_read_byte(&sin_q7[phase & 0x3F]);
}

static void draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
    int16_t dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int16_t dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int16_t error = dx + dy;
    while (true) {
        if (x0 >= 0 && x0 < OLED_DISPLAY_WIDTH && y0 >= 0 && y0 < OLED_DISPLAY_HEIGHT)
            oled_write_pixel((uint8_t)x0, (uint8_t)y0, true);
        if (x0 == x1 && y0 == y1) break;
        int16_t twice_error = 2 * error;
        if (twice_error >= dy) { error += dy; x0 += sx; }
        if (twice_error <= dx) { error += dx; y0 += sy; }
    }
}

void draw_rotating_cube(void) {
    if (timer_elapsed32(last_frame_time) < 75) return;
    last_frame_time = timer_read32();

    // Rotate around Y, with a smaller fixed X tilt to reveal the top face.
    int16_t sy = sin_at(animation_frame);
    int16_t cy = sin_at(animation_frame + 16);
    const int16_t sx = 64;  // sin(30 degrees), Q7
    const int16_t cx = 111; // cos(30 degrees), Q7
    int16_t px[8], py[8];

    for (uint8_t i = 0; i < 8; i++) {
        int16_t x = (i & 1) ? 1 : -1;
        int16_t y = (i & 2) ? 1 : -1;
        int16_t z = (i & 4) ? 1 : -1;
        // Keep coordinates in Q7 through both rotations. Dividing to whole
        // units here would collapse the vertical coordinates to zero.
        int16_t rx_q7 = x * cy + z * sy;
        int16_t rz_q7 = z * cy - x * sy;
        int16_t ry_q7 = y * cx - (rz_q7 * sx) / 127;
        int16_t depth_q7 = y * sx + (rz_q7 * cx) / 127;

        // Leave a few pixels of margin on the narrow, vertically mounted OLED.
        int16_t scale = 9 - (depth_q7 * 2) / 127;
        // Turn the projected image 90 degrees clockwise on the OLED.
        px[i] = 64 - (ry_q7 * scale) / 127;
        py[i] = 16 + (rx_q7 * scale) / 127;
    }

    oled_clear();
    for (uint8_t i = 0; i < 8; i++) {
        for (uint8_t axis = 0; axis < 3; axis++) {
            uint8_t neighbor = i ^ (1 << axis);
            if (neighbor > i) draw_line(px[i], py[i], px[neighbor], py[neighbor]);
        }
    }
    animation_frame = (animation_frame + 1) & 0x3F;
}
