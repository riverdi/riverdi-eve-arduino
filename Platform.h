/*
 * Copyright (c) Riverdi Sp. z o.o. sp. k. <riverdi@riverdi.com>
 * Copyright (c) Skalski Embedded Technologies <contact@lukasz-skalski.com>
 */

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

/*****************************************************************************/

//#define EVE_1                 1
//#define EVE_2                 1
//#define EVE_3                 1
#define EVE_4                 1

#define EVE_4_INTERNAL_OSC    1
//#define EVE_4_EXTERNAL_OSC    1

//#define NTP_35                1
//#define RTP_35                1
//#define CTP_35                1
//#define NTP_43                1
//#define RTP_43                1
//#define CTP_43                1
//#define NTP_50                1
//#define RTP_50                1
//#define CTP_50                1
//#define NTP_70                1
//#define RTP_70                1
//#define CTP_70                1
//#define IPS_35                1
//#define IPS_43                1
//#define IPS_50                1
//#define IPS_70                1
#define IPS_101               1

/*****************************************************************************/

#define ARDUINO_PLATFORM
#define ARDUINO_PLATFORM_COCMD_BURST

#ifdef __AVR__
#define GPIO_CS     10
#define GPIO_PD     8
#endif

#ifdef ESP32 /* Riverdi IoT Display */
#define GPIO_CS     4
#define GPIO_PD     33
#endif

/* Standard C libraries */
#include <stdio.h>

/* Standard Arduino libraries */
#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>

#ifdef __AVR__
#include <avr/pgmspace.h>
#endif

/*****************************************************************************/

/* type definitions for EVE HAL library */

#define TRUE		(1)
#define FALSE		(0)

typedef char		bool_t;
typedef char		char8_t;
typedef unsigned char	uchar8_t;
typedef signed char	schar8_t;
typedef float		float_t;

#ifdef ESP32 /* Riverdi IoT Display */
typedef PROGMEM const unsigned char  prog_uchar8_t;
#endif

#ifdef __AVR__
typedef PROGMEM const unsigned char  prog_uchar8_t;
typedef PROGMEM const char           prog_char8_t;
typedef PROGMEM const uint8_t        prog_uint8_t;
typedef PROGMEM const int8_t         prog_int8_t;
typedef PROGMEM const uint16_t       prog_uint16_t;
typedef PROGMEM const int16_t        prog_int16_t;
typedef PROGMEM const uint32_t       prog_uint32_t;
typedef PROGMEM const int32_t        prog_int32_t;
#endif

/* Predefined Riverdi modules */
#include "Riverdi_Modules.h"

/* EVE inclusions */
#include "Gpu_Hal.h"
#include "Gpu.h"
#include "CoPro_Cmds.h"
#include "Hal_Utils.h"

#endif /*_PLATFORM_H_*/
