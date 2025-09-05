/*
 * sht31d.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Jonghwan Park
 */
#include "sht31d.h"

extern I2C_HandleTypeDef hi2c1;
#define SHT31D_I2C &hi2c1

int SHT31_ReadTempHum(float *temperature, float *humidity) {
    uint8_t cmd[2] = {0x24, 0x00};   // high repeatability, no clock stretching
    uint8_t data[6];

    if (HAL_I2C_Master_Transmit(&hi2c1, SHT31D_I2C_ADDR, cmd, 2, HAL_MAX_DELAY) != HAL_OK)
        return -1;

    HAL_Delay(20); // wait ≥15ms per datasheet

    if (HAL_I2C_Master_Receive(&hi2c1, SHT31D_I2C_ADDR, data, 6, HAL_MAX_DELAY) != HAL_OK)
        return -2;

    if (SHT31_CRC8(data, 2) != data[2] || SHT31_CRC8(data+3, 2) != data[5])
        return -3;

    uint16_t rawT  = (data[0] << 8) | data[1];
    uint16_t rawRH = (data[3] << 8) | data[4];

    *temperature = -45.0f + 175.0f * ((float) rawT / 65535.0f);
    *humidity    = 100.0f * ((float) rawRH / 65535.0f);

    return 0; // success
}

uint8_t SHT31_CRC8(const uint8_t *data, int len) {
    uint8_t crc = 0xFF;
    for (int i = 0; i < len; i++) {
        crc ^= data[i];
        for (int b = 0; b < 8; b++) {
            crc = (crc & 0x80) ? (crc << 1) ^ 0x31 : (crc << 1);
        }
    }
    return crc;
}


