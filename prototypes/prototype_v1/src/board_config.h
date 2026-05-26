/****************************************************************************
 *
 *   Copyright (c) 2016-2022 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file board_config.h
 *
 * AbsoluteEdge FC prototype V1 internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <px4_platform_common/px4_config.h>
#include <nuttx/compiler.h>
#include <stdint.h>


#include <stm32_gpio.h>

/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/

#undef TRACE_PINS

/* PX4IO connection configuration */

#define BOARD_USES_PX4IO_VERSION       0


/* Configuration ************************************************************************************/

#define BOARD_HAS_LTC44XX_VALIDS      0 //  N Bricks
#define BOARD_HAS_USB_VALID           0 // LTC Has USB valid


/* PX4FMU GPIOs ***********************************************************************************/

/* Trace Clock and D0-D3 are available on the trace connector
 *
 * TRACECLK PE2  - Dedicated       - Trace Connector Pin 1
 * TRACED0  PE3  - nLED_RED        - Trace Connector Pin 3
 * TRACED1  PE4  - nLED_GREEN      - Trace Connector Pin 5
 * TRACED2  PE5  - nLED_BLUE       - Trace Connector Pin 7
 * TRACED3  PE6  - nARMED          - Trace Connector Pin 8

 */

/* LEDs are driven with push open drain to support Anode to 5V or 3.3V or used as TRACE0-2 */

#if !defined(TRACE_PINS)
#  define GPIO_nLED_RED        /* PE3 */  (GPIO_OUTPUT|GPIO_OPENDRAIN|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN5)
#  define GPIO_nLED_GREEN      /* PE4 */  (GPIO_OUTPUT|GPIO_OPENDRAIN|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN6)
#  define GPIO_nLED_BLUE       /* PE5 */  (GPIO_OUTPUT|GPIO_OPENDRAIN|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN4)

#  define BOARD_HAS_CONTROL_STATUS_LEDS      1
#  define BOARD_OVERLOAD_LED     LED_RED
#  define BOARD_ARMED_STATE_LED  LED_BLUE

#endif

/* USART1, telemetry radio */
#undef GPIO_USART1_TX
#undef GPIO_USART1_RX
#define GPIO_USART1_TX     GPIO_USART1_TX_2 // PA9
#define GPIO_USART1_RX     GPIO_USART1_RX_2 // PA10

/* USART3, GPS */
#undef GPIO_USART3_TX
#undef GPIO_USART3_RX
#define GPIO_USART3_TX     GPIO_USART3_TX_3 // PD8
#define GPIO_USART3_RX     GPIO_USART3_RX_3 // PD9

/* UART4, lidar */
#undef GPIO_UART4_TX
#undef GPIO_UART4_RX
#define GPIO_UART4_TX      GPIO_UART4_TX_1  // PA0
#define GPIO_UART4_RX      GPIO_UART4_RX_1  // PA1

/* USART6, RC receiver */
#undef GPIO_USART6_TX
#undef GPIO_USART6_RX
#define GPIO_USART6_TX     GPIO_USART6_TX_1 // PC6
#define GPIO_USART6_RX     GPIO_USART6_RX_1 // PC7

/* UART7 RX only, ESC telemetry */
#undef GPIO_UART7_RX
#define GPIO_UART7_RX      GPIO_UART7_RX_1  // PE7

/* UART8, companion computer */
#undef GPIO_UART8_TX
#undef GPIO_UART8_RX
#define GPIO_UART8_TX      GPIO_UART8_TX_1  // PE1
#define GPIO_UART8_RX      GPIO_UART8_RX_1  // PE0

/* SPI2 for IMUs */
#undef GPIO_SPI2_SCK
#undef GPIO_SPI2_MISO
#undef GPIO_SPI2_MOSI
#define GPIO_SPI2_SCK      GPIO_SPI2_SCK_2  // PD3
#define GPIO_SPI2_MISO     GPIO_SPI2_MISO_1 // PC2
#define GPIO_SPI2_MOSI     GPIO_SPI2_MOSI_1 // PC3

/* Chip Selects for SPI2 (Push-pull, default high) */
#define GPIO_SPI2_CS1_BMI270     (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTA|GPIO_PIN15)
#define GPIO_SPI2_CS2_BMI088_A   (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN4)
#define GPIO_SPI2_CS3_BMI088_G   (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN5)

/* I2C busses */
#define HRT_TIMER               8
#define HRT_TIMER_CHANNEL       3

#define BOARD_NUM_SPI_CFG_HW_VERSIONS 1
/* Devices on the onboard buses.
 *
 * Note that these are unshifted addresses.
 */
/* I2C2 */

#undef GPIO_I2C2_SCL
#undef GPIO_I2C2_SDA
#define GPIO_I2C2_SCL      GPIO_I2C2_SCL_1  // PB10
#define GPIO_I2C2_SDA      GPIO_I2C2_SDA_1  // PB11

/*
 * ADC channels
 *
 * These are the channel numbers of the ADCs of the microcontroller that
 * can be used by the Px4 Firmware in the adc driver
 */

/* We are only use ADC3 for REV/VER.
 * ADC3_6V6 and ADC3_3V3 are mapped back to ADC1
 * To do this We are relying on PC2_C, PC3_C being connected to PC2, PC3
 * respectively by the SYSCFG_PMCR default of setting for PC3SO PC2SO PA1SO
 * PA0SO of 0.
 *
 *  0 Analog switch closed (pads are connected through the analog switch)
 *
 * So ADC3_INP0 is GPIO_ADC123_INP12
 *    ADC3_INP1 is GPIO_ADC12_INP13
 */

/* Define GPIO pins used as ADC N.B. Channel numbers must match below  */


/* Define Channel numbers must match above GPIO pin IN(n)*/
#define PX4_ADC_GPIO  \
        /* PC0  */  GPIO_ADC123_INP10, \
        /* PC1  */  GPIO_ADC123_INP11

#define ADC_BATTERY_CURRENT_CHANNEL    10
#define ADC_BATTERY_VOLTAGE_CHANNEL    11

#define ADC_CHANNELS \
        ((1 << ADC_BATTERY_CURRENT_CHANNEL) | \
         (1 << ADC_BATTERY_VOLTAGE_CHANNEL))

#define SYSTEM_ADC_BASE STM32_ADC1_BASE

/* HW has to large of R termination on ADC todo:change when HW value is chosen */


/* PWM
 */
#define DIRECT_PWM_OUTPUT_CHANNELS   4

/* motors on TIM1 (PE9, PE11, PE13, PE14) */
#define GPIO_TIM1_CH1OUT   GPIO_TIM1_CH1OUT_2 // PE9
#define GPIO_TIM1_CH2OUT   GPIO_TIM1_CH2OUT_2 // PE11
#define GPIO_TIM1_CH3OUT   GPIO_TIM1_CH3OUT_2 // PE13
#define GPIO_TIM1_CH4OUT   GPIO_TIM1_CH4OUT_2 // PE14

/* USB OTG FS
 *
 * PA9  OTG_FS_VBUS VBUS sensing
 */
#define GPIO_OTGFS_VBUS (GPIO_INPUT | GPIO_FLOAT | GPIO_PORTB | GPIO_PIN2)
/*
 * FMUv6X has a separate RC_IN
 *
 * GPIO PPM_IN on PI5 T8CH1
 * SPEKTRUM_RX (it's TX or RX in Bind) on UART6 PC7
 *   Inversion is possible in the UART and can drive  GPIO PPM_IN as an output
 */

#define SDIO_SLOTNO                    0  /* Only one slot */
#define SDIO_MINOR                     0

#if defined(CONFIG_BOARD_INITIALIZE) && !defined(CONFIG_BOARDCTL) && \
   !defined(CONFIG_BOARD_INITTHREAD)
#  warning SDIO initialization cannot be perfomed on the IDLE thread
#endif

/* By Providing BOARD_ADC_USB_CONNECTED (using the px4_arch abstraction)
 * this board support the ADC system_power interface, and therefore
 * provides the true logic GPIO BOARD_ADC_xxxx macros.
 */


/* FMUv6X never powers off the Servo rail */

#define BOARD_ADC_USB_CONNECTED (1)
#define BOARD_ADC_USB_VALID     (1)
#define BOARD_ADC_SERVO_VALID   (1)
#define BOARD_ADC_BRICK1_VALID  (1)
#define BOARD_ADC_BRICK2_VALID  (0)
#define BOARD_ADC_PERIPH_5V_OC  (0)
#define BOARD_ADC_HIPOWER_5V_OC (0)

#define VDD_5V_PERIPH_EN(on_true)
#define VDD_5V_HIPOWER_EN(on_true)
#define VDD_3V3_SENSORS_EN(on_true)
#define VDD_3V3_SPEKTRUM_POWER_EN(on_true)
#define READ_VDD_3V3_SPEKTRUM_POWER_EN()   (1)
#define VDD_3V3_SD_CARD_EN(on_true)
#define VDD_3V3_ETH_POWER_EN(on_true)


/* This board provides a DMA pool and APIs */
#define BOARD_DMA_ALLOC_POOL_SIZE 5120

/* This board provides the board_on_reset interface */

#define BOARD_HAS_ON_RESET 1
#define BOARD_NUM_IO_TIMERS 4


#define PX4_GPIO_INIT_LIST { \
                GPIO_SPI2_CS1_BMI270,   \
                GPIO_SPI2_CS2_BMI088_A, \
                GPIO_SPI2_CS3_BMI088_G  \
        }

#define BOARD_ENABLE_CONSOLE_BUFFER
#define BOARD_NUM_IO_TIMERS 4

__BEGIN_DECLS

/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/****************************************************************************
 * Name: stm32_sdio_initialize
 *
 * Description:
 *   Initialize SDIO-based MMC/SD card support
 *
 ****************************************************************************/

int stm32_sdio_initialize(void);

/****************************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PX4FMU board.
 *
 ****************************************************************************************************/

extern void stm32_spiinitialize(void);

extern void stm32_usbinitialize(void);

extern void board_peripheral_reset(int ms);

#include <px4_platform_common/board_common.h>

#endif /* __ASSEMBLY__ */

__END_DECLS
