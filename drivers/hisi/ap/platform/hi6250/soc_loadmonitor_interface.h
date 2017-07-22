#ifndef __SOC_LOADMONITOR_INTERFACE_H__
#define __SOC_LOADMONITOR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_ADDR(base) ((base) + (0x000))
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_ADDR(base) ((base) + (0x004))
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_ADDR(base) ((base) + (0x008))
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_ADDR(base) ((base) + (0x00C))
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_ADDR(base) ((base) + (0x010))
#define SOC_LOADMONITOR_MONITOR_LOAD0_ADDR(base) ((base) + (0x014))
#define SOC_LOADMONITOR_MONITOR_LOAD1_ADDR(base) ((base) + (0x018))
#define SOC_LOADMONITOR_MONITOR_LOAD2_ADDR(base) ((base) + (0x01C))
#define SOC_LOADMONITOR_MONITOR_LOAD3_ADDR(base) ((base) + (0x020))
#define SOC_LOADMONITOR_MONITOR_LOAD4_ADDR(base) ((base) + (0x024))
#define SOC_LOADMONITOR_MONITOR_LOAD5_ADDR(base) ((base) + (0x028))
#define SOC_LOADMONITOR_MONITOR_LOAD6_ADDR(base) ((base) + (0x02C))
#define SOC_LOADMONITOR_MONITOR_LOAD7_ADDR(base) ((base) + (0x030))
#define SOC_LOADMONITOR_MONITOR_LOAD8_ADDR(base) ((base) + (0x034))
#define SOC_LOADMONITOR_MONITOR_LOAD9_ADDR(base) ((base) + (0x038))
#define SOC_LOADMONITOR_MONITOR_LOAD10_ADDR(base) ((base) + (0x03C))
#define SOC_LOADMONITOR_MONITOR_LOAD11_ADDR(base) ((base) + (0x040))
#define SOC_LOADMONITOR_MONITOR_LOAD12_ADDR(base) ((base) + (0x044))
#define SOC_LOADMONITOR_MONITOR_LOAD13_ADDR(base) ((base) + (0x048))
#define SOC_LOADMONITOR_MONITOR_LOAD14_ADDR(base) ((base) + (0x04C))
#define SOC_LOADMONITOR_MONITOR_LOAD15_ADDR(base) ((base) + (0x050))
#define SOC_LOADMONITOR_MONITOR_LOAD16_ADDR(base) ((base) + (0x054))
#define SOC_LOADMONITOR_MONITOR_LOAD17_ADDR(base) ((base) + (0x058))
#define SOC_LOADMONITOR_MONITOR_LOAD18_ADDR(base) ((base) + (0x05C))
#define SOC_LOADMONITOR_MONITOR_LOAD19_ADDR(base) ((base) + (0x060))
#define SOC_LOADMONITOR_MONITOR_LOAD20_ADDR(base) ((base) + (0x064))
#define SOC_LOADMONITOR_MONITOR_LOAD21_ADDR(base) ((base) + (0x068))
#define SOC_LOADMONITOR_MONITOR_LOAD22_ADDR(base) ((base) + (0x06C))
#define SOC_LOADMONITOR_MONITOR_LOAD23_ADDR(base) ((base) + (0x070))
#define SOC_LOADMONITOR_MONITOR_LOAD24_ADDR(base) ((base) + (0x074))
#define SOC_LOADMONITOR_MONITOR_LOAD25_ADDR(base) ((base) + (0x078))
#define SOC_LOADMONITOR_MONITOR_LOAD26_ADDR(base) ((base) + (0x07C))
#define SOC_LOADMONITOR_MONITOR_LOAD27_ADDR(base) ((base) + (0x080))
#define SOC_LOADMONITOR_MONITOR_LOAD28_ADDR(base) ((base) + (0x084))
#define SOC_LOADMONITOR_MONITOR_LOAD29_ADDR(base) ((base) + (0x088))
#define SOC_LOADMONITOR_MONITOR_LOAD30_ADDR(base) ((base) + (0x08C))
#define SOC_LOADMONITOR_MONITOR_LOAD31_ADDR(base) ((base) + (0x090))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_ctrl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LOADMONITOR_MONITOR_CTRL_EN_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_monitor_ctrl_en_START (0)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_monitor_ctrl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cfg_time : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_CFG_TIME_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_monitor_cfg_time_START (0)
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_monitor_cfg_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_en : 1;
        unsigned int monitor_sensor1_en : 1;
        unsigned int monitor_sensor2_en : 1;
        unsigned int monitor_sensor3_en : 1;
        unsigned int monitor_sensor4_en : 1;
        unsigned int monitor_sensor5_en : 1;
        unsigned int monitor_sensor6_en : 1;
        unsigned int monitor_sensor7_en : 1;
        unsigned int monitor_sensor8_en : 1;
        unsigned int monitor_sensor9_en : 1;
        unsigned int monitor_sensor10_en : 1;
        unsigned int monitor_sensor11_en : 1;
        unsigned int monitor_sensor12_en : 1;
        unsigned int monitor_sensor13_en : 1;
        unsigned int monitor_sensor14_en : 1;
        unsigned int monitor_sensor15_en : 1;
        unsigned int monitor_sensor16_en : 1;
        unsigned int monitor_sensor17_en : 1;
        unsigned int monitor_sensor18_en : 1;
        unsigned int monitor_sensor19_en : 1;
        unsigned int monitor_sensor20_en : 1;
        unsigned int monitor_sensor21_en : 1;
        unsigned int monitor_sensor22_en : 1;
        unsigned int monitor_sensor23_en : 1;
        unsigned int monitor_sensor24_en : 1;
        unsigned int monitor_sensor25_en : 1;
        unsigned int monitor_sensor26_en : 1;
        unsigned int monitor_sensor27_en : 1;
        unsigned int monitor_sensor28_en : 1;
        unsigned int monitor_sensor29_en : 1;
        unsigned int monitor_sensor30_en : 1;
        unsigned int monitor_sensor31_en : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_EN_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor0_en_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor0_en_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor1_en_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor1_en_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor2_en_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor2_en_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor3_en_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor3_en_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor4_en_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor4_en_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor5_en_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor5_en_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor6_en_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor6_en_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor7_en_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor7_en_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor8_en_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor8_en_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor9_en_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor9_en_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor10_en_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor10_en_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor11_en_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor11_en_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor12_en_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor12_en_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor13_en_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor13_en_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor14_en_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor14_en_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor15_en_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor15_en_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor16_en_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor16_en_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor17_en_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor17_en_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor18_en_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor18_en_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor19_en_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor19_en_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor20_en_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor20_en_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor21_en_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor21_en_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor22_en_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor22_en_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor23_en_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor23_en_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor24_en_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor24_en_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor25_en_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor25_en_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor26_en_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor26_en_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor27_en_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor27_en_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor28_en_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor28_en_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor29_en_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor29_en_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor30_en_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor30_en_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor31_en_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor31_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_dis : 1;
        unsigned int monitor_sensor1_dis : 1;
        unsigned int monitor_sensor2_dis : 1;
        unsigned int monitor_sensor3_dis : 1;
        unsigned int monitor_sensor4_dis : 1;
        unsigned int monitor_sensor5_dis : 1;
        unsigned int monitor_sensor6_dis : 1;
        unsigned int monitor_sensor7_dis : 1;
        unsigned int monitor_sensor8_dis : 1;
        unsigned int monitor_sensor9_dis : 1;
        unsigned int monitor_sensor10_dis : 1;
        unsigned int monitor_sensor11_dis : 1;
        unsigned int monitor_sensor12_dis : 1;
        unsigned int monitor_sensor13_dis : 1;
        unsigned int monitor_sensor14_dis : 1;
        unsigned int monitor_sensor15_dis : 1;
        unsigned int monitor_sensor16_dis : 1;
        unsigned int monitor_sensor17_dis : 1;
        unsigned int monitor_sensor18_dis : 1;
        unsigned int monitor_sensor19_dis : 1;
        unsigned int monitor_sensor20_dis : 1;
        unsigned int monitor_sensor21_dis : 1;
        unsigned int monitor_sensor22_dis : 1;
        unsigned int monitor_sensor23_dis : 1;
        unsigned int monitor_sensor24_dis : 1;
        unsigned int monitor_sensor25_dis : 1;
        unsigned int monitor_sensor26_dis : 1;
        unsigned int monitor_sensor27_dis : 1;
        unsigned int monitor_sensor28_dis : 1;
        unsigned int monitor_sensor29_dis : 1;
        unsigned int monitor_sensor30_dis : 1;
        unsigned int monitor_sensor31_dis : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_DIS_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor0_dis_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor0_dis_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor1_dis_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor1_dis_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor2_dis_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor2_dis_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor3_dis_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor3_dis_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor4_dis_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor4_dis_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor5_dis_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor5_dis_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor6_dis_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor6_dis_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor7_dis_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor7_dis_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor8_dis_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor8_dis_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor9_dis_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor9_dis_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor10_dis_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor10_dis_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor11_dis_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor11_dis_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor12_dis_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor12_dis_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor13_dis_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor13_dis_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor14_dis_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor14_dis_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor15_dis_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor15_dis_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor16_dis_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor16_dis_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor17_dis_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor17_dis_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor18_dis_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor18_dis_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor19_dis_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor19_dis_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor20_dis_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor20_dis_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor21_dis_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor21_dis_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor22_dis_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor22_dis_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor23_dis_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor23_dis_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor24_dis_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor24_dis_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor25_dis_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor25_dis_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor26_dis_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor26_dis_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor27_dis_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor27_dis_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor28_dis_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor28_dis_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor29_dis_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor29_dis_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor30_dis_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor30_dis_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor31_dis_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor31_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_stat : 1;
        unsigned int monitor_sensor1_stat : 1;
        unsigned int monitor_sensor2_stat : 1;
        unsigned int monitor_sensor3_stat : 1;
        unsigned int monitor_sensor4_stat : 1;
        unsigned int monitor_sensor5_stat : 1;
        unsigned int monitor_sensor6_stat : 1;
        unsigned int monitor_sensor7_stat : 1;
        unsigned int monitor_sensor8_stat : 1;
        unsigned int monitor_sensor9_stat : 1;
        unsigned int monitor_sensor10_stat : 1;
        unsigned int monitor_sensor11_stat : 1;
        unsigned int monitor_sensor12_stat : 1;
        unsigned int monitor_sensor13_stat : 1;
        unsigned int monitor_sensor14_stat : 1;
        unsigned int monitor_sensor15_stat : 1;
        unsigned int monitor_sensor16_stat : 1;
        unsigned int monitor_sensor17_stat : 1;
        unsigned int monitor_sensor18_stat : 1;
        unsigned int monitor_sensor19_stat : 1;
        unsigned int monitor_sensor20_stat : 1;
        unsigned int monitor_sensor21_stat : 1;
        unsigned int monitor_sensor22_stat : 1;
        unsigned int monitor_sensor23_stat : 1;
        unsigned int monitor_sensor24_stat : 1;
        unsigned int monitor_sensor25_stat : 1;
        unsigned int monitor_sensor26_stat : 1;
        unsigned int monitor_sensor27_stat : 1;
        unsigned int monitor_sensor28_stat : 1;
        unsigned int monitor_sensor29_stat : 1;
        unsigned int monitor_sensor30_stat : 1;
        unsigned int monitor_sensor31_stat : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_STAT_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor0_stat_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor0_stat_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor1_stat_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor1_stat_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor2_stat_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor2_stat_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor3_stat_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor3_stat_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor4_stat_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor4_stat_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor5_stat_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor5_stat_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor6_stat_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor6_stat_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor7_stat_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor7_stat_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor8_stat_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor8_stat_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor9_stat_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor9_stat_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor10_stat_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor10_stat_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor11_stat_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor11_stat_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor12_stat_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor12_stat_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor13_stat_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor13_stat_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor14_stat_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor14_stat_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor15_stat_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor15_stat_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor16_stat_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor16_stat_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor17_stat_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor17_stat_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor18_stat_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor18_stat_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor19_stat_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor19_stat_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor20_stat_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor20_stat_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor21_stat_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor21_stat_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor22_stat_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor22_stat_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor23_stat_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor23_stat_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor24_stat_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor24_stat_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor25_stat_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor25_stat_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor26_stat_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor26_stat_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor27_stat_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor27_stat_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor28_stat_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor28_stat_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor29_stat_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor29_stat_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor30_stat_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor30_stat_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor31_stat_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor31_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load0 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD0_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD0_monitor_cnt_load0_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD0_monitor_cnt_load0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load1 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD1_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD1_monitor_cnt_load1_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD1_monitor_cnt_load1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load2 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD2_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD2_monitor_cnt_load2_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD2_monitor_cnt_load2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load3 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD3_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD3_monitor_cnt_load3_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD3_monitor_cnt_load3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load4 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD4_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD4_monitor_cnt_load4_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD4_monitor_cnt_load4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load5 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD5_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD5_monitor_cnt_load5_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD5_monitor_cnt_load5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load6 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD6_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD6_monitor_cnt_load6_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD6_monitor_cnt_load6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load7 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD7_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD7_monitor_cnt_load7_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD7_monitor_cnt_load7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load8 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD8_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD8_monitor_cnt_load8_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD8_monitor_cnt_load8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load9 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD9_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD9_monitor_cnt_load9_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD9_monitor_cnt_load9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load10 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD10_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD10_monitor_cnt_load10_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD10_monitor_cnt_load10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load11 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD11_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD11_monitor_cnt_load11_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD11_monitor_cnt_load11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load12 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD12_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD12_monitor_cnt_load12_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD12_monitor_cnt_load12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load13 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD13_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD13_monitor_cnt_load13_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD13_monitor_cnt_load13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load14 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD14_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD14_monitor_cnt_load14_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD14_monitor_cnt_load14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load15 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD15_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD15_monitor_cnt_load15_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD15_monitor_cnt_load15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load16 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD16_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD16_monitor_cnt_load16_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD16_monitor_cnt_load16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load17 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD17_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD17_monitor_cnt_load17_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD17_monitor_cnt_load17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load18 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD18_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD18_monitor_cnt_load18_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD18_monitor_cnt_load18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load19 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD19_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD19_monitor_cnt_load19_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD19_monitor_cnt_load19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load20 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD20_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD20_monitor_cnt_load20_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD20_monitor_cnt_load20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load21 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD21_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD21_monitor_cnt_load21_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD21_monitor_cnt_load21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load22 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD22_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD22_monitor_cnt_load22_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD22_monitor_cnt_load22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load23 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD23_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD23_monitor_cnt_load23_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD23_monitor_cnt_load23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load24 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD24_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD24_monitor_cnt_load24_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD24_monitor_cnt_load24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load25 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD25_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD25_monitor_cnt_load25_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD25_monitor_cnt_load25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load26 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD26_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD26_monitor_cnt_load26_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD26_monitor_cnt_load26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load27 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD27_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD27_monitor_cnt_load27_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD27_monitor_cnt_load27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load28 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD28_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD28_monitor_cnt_load28_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD28_monitor_cnt_load28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load29 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD29_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD29_monitor_cnt_load29_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD29_monitor_cnt_load29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load30 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD30_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD30_monitor_cnt_load30_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD30_monitor_cnt_load30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_load31 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_LOAD31_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_LOAD31_monitor_cnt_load31_START (0)
#define SOC_LOADMONITOR_MONITOR_LOAD31_monitor_cnt_load31_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
