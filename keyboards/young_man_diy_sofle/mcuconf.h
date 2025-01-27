#pragma once

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART2
#define STM32_SERIAL_USE_USART2 TRUE

// #undef STM32_SPI_USE_SPI2
// #define STM32_SPI_USE_SPI2 TRUE

// #undef STM32_I2C_USE_I2C2
// #define STM32_I2C_USE_I2C2 TRUE

// #define STM32_I2C_BUSY_TIMEOUT 50
// #define STM32_I2C_USE_DMA TRUE
