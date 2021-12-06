#pragma once

#ifndef BMP280_H
#define BMP280_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

/*      REGISTER DEFINES          */
#define BMP280_TEMP_XLSB     (UINT8_C) 0xFC

#define BMP280_TEMP_LSB      (UINT8_C) 0xFB
#define BMP280_TEMP_MSB      (UINT8_C) 0xFA

#define BMP280_PRESS_XLSB    (UINT8_C) 0xF9

#define BMP280_PRESS_LSB     (UINT8_C) 0xF8
#define BMP280_PRESS_MSB     (UINT8_C) 0xF7

#define BMP280_CONFIG        (UINT8_C) 0xF5
#define BMP280_CTRL_MEAS     (UINT8_C) 0xF4
#define BMP280_STATUS        (UINT8_C) 0xF3
#define BMP280_RESET         (UINT8_C) 0xE0
#define BMP280_ID            (UINT8_C) 0xD0

#define BMP280_CALIB_DIG_T1_LSB     (UINT8_C) 0x88
#define BMP280_CALIB_DIG_T1_MSB     (UINT8_C) 0x89

#define BMP280_CALIB_DIG_T2_LSB     (UINT8_C) 0x8A
#define BMP280_CALIB_DIG_T2_MSB     (UINT8_C) 0x8B

#define BMP280_CALIB_DIG_T3_LSB     (UINT8_C) 0x8C
#define BMP280_CALIB_DIG_T3_MSB     (UINT8_C) 0x8D

#define BMP280_CALIB_DIG_P1_LSB     (UINT8_C) 0x8E
#define BMP280_CALIB_DIG_P1_MSB     (UINT8_C) 0x8F

#define BMP280_CALIB_DIG_P2_LSB     (UINT8_C) 0x90
#define BMP280_CALIB_DIG_P2_MSB     (UINT8_C) 0x91

#define BMP280_CALIB_DIG_P3_LSB     (UINT8_C) 0x92
#define BMP280_CALIB_DIG_P3_MSB     (UINT8_C) 0x93

#define BMP280_CALIB_DIG_P4_LSB     (UINT8_C) 0x94
#define BMP280_CALIB_DIG_P4_MSB     (UINT8_C) 0x95

#define BMP280_CALIB_DIG_P5_LSB     (UINT8_C) 0x96
#define BMP280_CALIB_DIG_P5_MSB     (UINT8_C) 0x97

#define BMP280_CALIB_DIG_P6_LSB     (UINT8_C) 0x98
#define BMP280_CALIB_DIG_P6_MSB     (UINT8_C) 0x99

#define BMP280_CALIB_DIG_P7_LSB     (UINT8_C) 0x9A
#define BMP280_CALIB_DIG_P7_MSB     (UINT8_C) 0x9B

#define BMP280_CALIB_DIG_P8_LSB     (UINT8_C) 0x9C
#define BMP280_CALIB_DIG_P8_MSB     (UINT8_C) 0x9D

#define BMP280_CALIB_DIG_P9_LSB     (UINT8_C) 0x9E
#define BMP280_CALIB_DIG_P9_MSB     (UINT8_C) 0x9F

#define BMP280_CALIB_RESERVED_LSB   (UINT8_C) 0xA0
#define BMP280_CALIB_RESERVED_MSB   (UINT8_C) 0xA1

#endif