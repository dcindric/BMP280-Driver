#pragma once

#ifndef BMP280_H
#define BMP280_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

/*************** REGISTER DEFINES START ***************/

/*************** Temperature raw data registers. ***************/
#define BMP280_REG_TEMP_MSB             (UINT8_C) 0xFA      //temp_msb[7:0],  MSBs [19:12]
#define BMP280_REG_TEMP_LSB             (UINT8_C) 0xFB      //temp_lsb[7:0],  LSBs [11:4]
#define BMP280_REG_TEMP_XLSB            (UINT8_C) 0xFC      //temp_xlsb[7:0], LSBs [3:0]

/*************** Pressure raw data registers. ***************/
#define BMP280_REG_PRESS_MSB            (UINT8_C) 0xF7      //press_msb[7:0],  MSBs [19:12]
#define BMP280_REG_PRESS_LSB            (UINT8_C) 0xF8      //press_lsb[7:0],  LSBs [11:4]
#define BMP280_REG_PRESS_XLSB           (UINT8_C) 0xF9      //press_xlsb[7:0], LSBs [3:0]


#define BMP280_REG_CONFIG               (UINT8_C) 0xF5
#define BMP280_REG_CTRL_MEAS            (UINT8_C) 0xF4
#define BMP280_REG_STATUS               (UINT8_C) 0xF3
#define BMP280_REG_RESET                (UINT8_C) 0xE0
#define BMP280_REG_ID                   (UINT8_C) 0xD0

#define BMP280_REG_CALIB_DIG_T1_LSB     (UINT8_C) 0x88
#define BMP280_REG_CALIB_DIG_T1_MSB     (UINT8_C) 0x89
#define BMP280_REG_CALIB_DIG_T2_LSB     (UINT8_C) 0x8A
#define BMP280_REG_CALIB_DIG_T2_MSB     (UINT8_C) 0x8B
#define BMP280_REG_CALIB_DIG_T3_LSB     (UINT8_C) 0x8C
#define BMP280_REG_CALIB_DIG_T3_MSB     (UINT8_C) 0x8D

#define BMP280_REG_CALIB_DIG_P1_LSB     (UINT8_C) 0x8E
#define BMP280_REG_CALIB_DIG_P1_MSB     (UINT8_C) 0x8F
#define BMP280_REG_CALIB_DIG_P2_LSB     (UINT8_C) 0x90
#define BMP280_REG_CALIB_DIG_P2_MSB     (UINT8_C) 0x91
#define BMP280_REG_CALIB_DIG_P3_LSB     (UINT8_C) 0x92
#define BMP280_REG_CALIB_DIG_P3_MSB     (UINT8_C) 0x93
#define BMP280_REG_CALIB_DIG_P4_LSB     (UINT8_C) 0x94
#define BMP280_REG_CALIB_DIG_P4_MSB     (UINT8_C) 0x95
#define BMP280_REG_CALIB_DIG_P5_LSB     (UINT8_C) 0x96
#define BMP280_REG_CALIB_DIG_P5_MSB     (UINT8_C) 0x97
#define BMP280_REG_CALIB_DIG_P6_LSB     (UINT8_C) 0x98
#define BMP280_REG_CALIB_DIG_P6_MSB     (UINT8_C) 0x99
#define BMP280_REG_CALIB_DIG_P7_LSB     (UINT8_C) 0x9A
#define BMP280_REG_CALIB_DIG_P7_MSB     (UINT8_C) 0x9B
#define BMP280_REG_CALIB_DIG_P8_LSB     (UINT8_C) 0x9C
#define BMP280_REG_CALIB_DIG_P8_MSB     (UINT8_C) 0x9D
#define BMP280_REG_CALIB_DIG_P9_LSB     (UINT8_C) 0x9E
#define BMP280_REG_CALIB_DIG_P9_MSB     (UINT8_C) 0x9F

#define BMP280_REG_CALIB_RESERVED_LSB   (UINT8_C) 0xA0
#define BMP280_REG_CALIB_RESERVED_MSB   (UINT8_C) 0xA1
/*************** REGISTER DEFINES END ***************/


/*************** SENSOR-SPECIFIC DEFINES (ID NUMBER, RESET COMMAND, ETC.) START ***************/

/*BMP280 ID number, can be read after power-on-reset is finished*/
#define BMP280_ID_NUMBER                (UINT8_C) 0x58  

/*Last 4 LSBs of temperature and pressure raw data are stored in the _XLSB register, on bits [7:4], while the rest
of the bits, [3:0], is not needed, hence this mask definition*/
#define BMP280_EXTRACT_XLSB_DATA_MASK   0xF0


/*************** RESET REGISTER DEFINES START ***************/
/*If this value is written to the reset register, the device is reset using the complete power-on-reset procedure*/
#define BMP280_RESET_CMD        (UINT8_C) 0xB6   
/*************** RESET REGISTER DEFINES END ***************/


/*************** STATUS REGISTER DEFINES START***************/
/*Mask for isolating bit 3 in status register, '1' -> conversion is running, '0' -> result ready in data registers*/
#define BMP280_MEAS_STATUS      (UINT8_C) 0x04

/*Mask for isolating bit 0 in status register, '1' -> NVM data is being copied to image registers, '0' -> copying is done */
#define BMP280_IM_UPDATE_STATUS (UINT8_C) 0x01
/*************** STATUS REGISTER DEFINES END***************/


/*************** CONTROL_MEAS REGISTER DEFINES START***************/
/*Oversampling commands for temperature data, osrs_t[2:0] -> bits 7,6,5 in CTRL_MEAS register*/
#define BMP280_OVERSAMPL_TEMP_X1        0b00100000  
#define BMP280_OVERSAMPL_TEMP_X2        0b01000000
#define BMP280_OVERSAMPL_TEMP_X4        0b01100000
#define BMP280_OVERSAMPL_TEMP_X8        0b10000000
#define BMP280_OVERSAMPL_TEMP_X16       0b11100000
#define BMP280_OVERASAMPL_TEMP_SKIP     0b00000000  //Skipped, output set to 0x80000

/*Oversampling commands for pressure data, osrs_p[2:0] -> bits 4,3,2 in CTLR_MEAS register*/
#define BMP280_OVERSAMPL_PRESS_X1       0b00000100          
#define BMP280_OVERSAMPL_PRESS_X2       0b00001000
#define BMP280_OVERSAMPL_PRESS_X4       0b00001100
#define BMP280_OVERSAMPL_PRESS_X8       0b00010000
#define BMP280_OVERSAMPL_PRESS_X16      0b00010100
#define BMP280_OVERSAMPL_PRESS_SKIP     0b00000000 //Skipped, output set to 0x80000

/*Power mode control of the device, mode[1:0] -> bits 1,0 in CTRL_MEAS register*/
#define BMP280_POWER_MODE_SLEEP         0b00000000
#define BMP280_POWER_MODE_FORCED        0b00000010
#define BMP280_POWER_MODE_NORMAL        0b00000011
/*************** CONTROL_MEAS REGISTER DEFINES END***************/


/*************** CONFIG REGISTER DEFINES START***************/
/*The standby time, t_sb[2:0] -> bits 7,6,5 in CONFIG register*/
#define BMP280_STANDBY_TIME_500_US      0b00000000  //0.5 ms
#define BMP280_STANDBY_TIME_62500_US    0b00100000  //62.5 ms
#define BMP280_STANDBY_TIME_125_MS      0b01000000  //125 ms
#define BMP280_STANDBY_TIME_250_MS      0b01100000  //250 ms
#define BMP280_STANDBY_TIME_500_MS      0b10000000  //500 ms
#define BMP280_STANDBY_TIME_1000_MS     0b10100000  //1000 ms
#define BMP280_STANDBY_TIME_2000_MS     0b11000000  //2000 ms
#define BMP280_STANDBY_TIME_4000_MS     0b11100000  //4000 ms

/*Controls the time constant of the internal IIR filter, filter[2:0] -> bits 4,3,2 in CONFIG register*/
//TODO: datasheet pg. 13,14,26

/*Enables 3-wire SPI interface, spi3w_en[0] -> bit 0 in CONFIG register*/
#define BMP280_SPI_3WIRE_ENABLE         1

/*Disable 3-wire SPI interface, spi3w_en[0] -> bit 0 in CONFIG register*/
#define BMP280_SPI_3WIRE_DISABLE        0
/*************** CONFIG REGISTER DEFINES END***************/


#endif