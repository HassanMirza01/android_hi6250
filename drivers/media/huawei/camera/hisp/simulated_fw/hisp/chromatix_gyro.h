

#ifndef _CHROMATIX_GYRO_H
#define _CHROMATIX_GYRO_H

typedef struct _gyro_sensor_data_t
{
    long long timestamp;
    float gyro_dx;
    float gyro_dy;
    float gyro_dz;
    float reserved;
}gyro_sensor_data_t;

#define GYRO_SENSOR_DATA_CNT 20

#define GYRO_MEP_WR_ENABLE 0xa5
#define GYRO_MEP_WR_DISABLE 0x5a

typedef struct _gyro_map_buffer_t
{
    unsigned char write_flag;
    unsigned char read_flag;
    unsigned char reserved[6];
    long long timestamp_offset;
    gyro_sensor_data_t gyro_data[GYRO_SENSOR_DATA_CNT];
}gyro_map_buffer_t;

#endif
