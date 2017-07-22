#ifndef __SOC_CTF_INTERFACE_H__
#define __SOC_CTF_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CTF_VSCAN_ADDR(base) ((base) + (0x000))
#define SOC_CTF_PTN0_ADDR(base) ((base) + (0x010))
#define SOC_CTF_PTN1_ADDR(base) ((base) + (0x014))
#define SOC_CTF_PTN2_ADDR(base) ((base) + (0x018))
#define SOC_CTF_PTN3_ADDR(base) ((base) + (0x01C))
#define SOC_CTF_PTN4_ADDR(base) ((base) + (0x020))
#define SOC_CTF_PTN5_ADDR(base) ((base) + (0x024))
#define SOC_CTF_PTN6_ADDR(base) ((base) + (0x028))
#define SOC_CTF_PTN7_ADDR(base) ((base) + (0x02C))
#define SOC_CTF_SGIMASK_ADDR(base) ((base) + (0x040))
#define SOC_CTF_PPIMASK_ADDR(base) ((base) + (0x044))
#define SOC_CTF_SPIMASK_ADDR(base) ((base) + (0x048))
#define SOC_CTF_SGIGROUP_ADDR(base) ((base) + (0x04C))
#define SOC_CTF_PPIGROUP_ADDR(base) ((base) + (0x050))
#define SOC_CTF_SPIGROUP_ADDR(base) ((base) + (0x054))
#define SOC_CTF_APB_WR_ERR_ADDR(base) ((base) + (0x058))
#define SOC_CTF_SPI_INT_EN_ADDR(base) ((base) + (0x060))
#define SOC_CTF_SPI_INT_CLR_ADDR(base) ((base) + (0x064))
#define SOC_CTF_SPI_RAWSTAT_ADDR(base) ((base) + (0x068))
#define SOC_CTF_SPITARG0_ADDR(base) ((base) + (0x070))
#define SOC_CTF_SPITARG1_ADDR(base) ((base) + (0x0074))
#define SOC_CTF_SPITARG2_ADDR(base) ((base) + (0x078))
#define SOC_CTF_SPITARG3_ADDR(base) ((base) + (0x07C))
#define SOC_CTF_SGIG_ADDR(base,N) ((base) + (0x000 + 0x400 + 0x80*(N)))
#define SOC_CTF_SGIPSTAT0_ADDR(base,N) ((base) + (0x004 + 0x400 + 0x80*(N)))
#define SOC_CTF_SGIPSTAT1_ADDR(base,N) ((base) + (0x008 + 0x400 + 0x80*(N)))
#define SOC_CTF_PPIPSTAT_ADDR(base,N) ((base) + (0x00C + 0x400 + 0x80*(N)))
#define SOC_CTF_SPIPSTAT_ADDR(base,N) ((base) + (0x010 + 0x400 + 0x80*(N)))
#define SOC_CTF_IAR_ADDR(base,N) ((base) + (0x040 + 0x400 + 0x80*(N)))
#define SOC_CTF_EOIR_ADDR(base,N) ((base) + (0x044 + 0x400 + 0x80*(N)))
#define SOC_CTF_OUTSTAT_ADDR(base,N) ((base) + (0x048 + 0x400 + 0x80*(N)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctf_vscan_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CTF_VSCAN_UNION;
#endif
#define SOC_CTF_VSCAN_ctf_vscan_en_START (0)
#define SOC_CTF_VSCAN_ctf_vscan_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten0 : 32;
    } reg;
} SOC_CTF_PTN0_UNION;
#endif
#define SOC_CTF_PTN0_patten0_START (0)
#define SOC_CTF_PTN0_patten0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten1 : 32;
    } reg;
} SOC_CTF_PTN1_UNION;
#endif
#define SOC_CTF_PTN1_patten1_START (0)
#define SOC_CTF_PTN1_patten1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten2 : 32;
    } reg;
} SOC_CTF_PTN2_UNION;
#endif
#define SOC_CTF_PTN2_patten2_START (0)
#define SOC_CTF_PTN2_patten2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten3 : 32;
    } reg;
} SOC_CTF_PTN3_UNION;
#endif
#define SOC_CTF_PTN3_patten3_START (0)
#define SOC_CTF_PTN3_patten3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten4 : 32;
    } reg;
} SOC_CTF_PTN4_UNION;
#endif
#define SOC_CTF_PTN4_patten4_START (0)
#define SOC_CTF_PTN4_patten4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten5 : 32;
    } reg;
} SOC_CTF_PTN5_UNION;
#endif
#define SOC_CTF_PTN5_patten5_START (0)
#define SOC_CTF_PTN5_patten5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten6 : 32;
    } reg;
} SOC_CTF_PTN6_UNION;
#endif
#define SOC_CTF_PTN6_patten6_START (0)
#define SOC_CTF_PTN6_patten6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int patten7 : 32;
    } reg;
} SOC_CTF_PTN7_UNION;
#endif
#define SOC_CTF_PTN7_patten7_START (0)
#define SOC_CTF_PTN7_patten7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgimask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CTF_SGIMASK_UNION;
#endif
#define SOC_CTF_SGIMASK_sgimask_START (0)
#define SOC_CTF_SGIMASK_sgimask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 29;
        unsigned int ppimask : 2;
        unsigned int reserved_1: 1;
    } reg;
} SOC_CTF_PPIMASK_UNION;
#endif
#define SOC_CTF_PPIMASK_ppimask_START (29)
#define SOC_CTF_PPIMASK_ppimask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spimask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPIMASK_UNION;
#endif
#define SOC_CTF_SPIMASK_spimask_START (0)
#define SOC_CTF_SPIMASK_spimask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgigroup : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CTF_SGIGROUP_UNION;
#endif
#define SOC_CTF_SGIGROUP_sgigroup_START (0)
#define SOC_CTF_SGIGROUP_sgigroup_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 29;
        unsigned int ppigroup : 2;
        unsigned int reserved_1: 1;
    } reg;
} SOC_CTF_PPIGROUP_UNION;
#endif
#define SOC_CTF_PPIGROUP_ppigroup_START (29)
#define SOC_CTF_PPIGROUP_ppigroup_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spigroup : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPIGROUP_UNION;
#endif
#define SOC_CTF_SPIGROUP_spigroup_START (0)
#define SOC_CTF_SPIGROUP_spigroup_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_wr_err : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CTF_APB_WR_ERR_UNION;
#endif
#define SOC_CTF_APB_WR_ERR_apb_wr_err_START (0)
#define SOC_CTF_APB_WR_ERR_apb_wr_err_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu2acpu_raw_int_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPI_INT_EN_UNION;
#endif
#define SOC_CTF_SPI_INT_EN_mcu2acpu_raw_int_en_START (0)
#define SOC_CTF_SPI_INT_EN_mcu2acpu_raw_int_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu2acpu_raw_int_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPI_INT_CLR_UNION;
#endif
#define SOC_CTF_SPI_INT_CLR_mcu2acpu_raw_int_clr_START (0)
#define SOC_CTF_SPI_INT_CLR_mcu2acpu_raw_int_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu2acpu_raw_status : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPI_RAWSTAT_UNION;
#endif
#define SOC_CTF_SPI_RAWSTAT_mcu2acpu_raw_status_START (0)
#define SOC_CTF_SPI_RAWSTAT_mcu2acpu_raw_status_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cputargets_byte_offset0 : 8;
        unsigned int cputargets_byte_offset1 : 8;
        unsigned int cputargets_byte_offset2 : 8;
        unsigned int cputargets_byte_offset3 : 8;
    } reg;
} SOC_CTF_SPITARG0_UNION;
#endif
#define SOC_CTF_SPITARG0_cputargets_byte_offset0_START (0)
#define SOC_CTF_SPITARG0_cputargets_byte_offset0_END (7)
#define SOC_CTF_SPITARG0_cputargets_byte_offset1_START (8)
#define SOC_CTF_SPITARG0_cputargets_byte_offset1_END (15)
#define SOC_CTF_SPITARG0_cputargets_byte_offset2_START (16)
#define SOC_CTF_SPITARG0_cputargets_byte_offset2_END (23)
#define SOC_CTF_SPITARG0_cputargets_byte_offset3_START (24)
#define SOC_CTF_SPITARG0_cputargets_byte_offset3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cputargets_byte_offset0 : 8;
        unsigned int cputargets_byte_offset1 : 8;
        unsigned int cputargets_byte_offset2 : 8;
        unsigned int cputargets_byte_offset3 : 8;
    } reg;
} SOC_CTF_SPITARG1_UNION;
#endif
#define SOC_CTF_SPITARG1_cputargets_byte_offset0_START (0)
#define SOC_CTF_SPITARG1_cputargets_byte_offset0_END (7)
#define SOC_CTF_SPITARG1_cputargets_byte_offset1_START (8)
#define SOC_CTF_SPITARG1_cputargets_byte_offset1_END (15)
#define SOC_CTF_SPITARG1_cputargets_byte_offset2_START (16)
#define SOC_CTF_SPITARG1_cputargets_byte_offset2_END (23)
#define SOC_CTF_SPITARG1_cputargets_byte_offset3_START (24)
#define SOC_CTF_SPITARG1_cputargets_byte_offset3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cputargets_byte_offset0 : 8;
        unsigned int cputargets_byte_offset1 : 8;
        unsigned int cputargets_byte_offset2 : 8;
        unsigned int cputargets_byte_offset3 : 8;
    } reg;
} SOC_CTF_SPITARG2_UNION;
#endif
#define SOC_CTF_SPITARG2_cputargets_byte_offset0_START (0)
#define SOC_CTF_SPITARG2_cputargets_byte_offset0_END (7)
#define SOC_CTF_SPITARG2_cputargets_byte_offset1_START (8)
#define SOC_CTF_SPITARG2_cputargets_byte_offset1_END (15)
#define SOC_CTF_SPITARG2_cputargets_byte_offset2_START (16)
#define SOC_CTF_SPITARG2_cputargets_byte_offset2_END (23)
#define SOC_CTF_SPITARG2_cputargets_byte_offset3_START (24)
#define SOC_CTF_SPITARG2_cputargets_byte_offset3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cputargets_byte_offset0 : 8;
        unsigned int cputargets_byte_offset1 : 8;
        unsigned int cputargets_byte_offset2 : 8;
        unsigned int cputargets_byte_offset3 : 8;
    } reg;
} SOC_CTF_SPITARG3_UNION;
#endif
#define SOC_CTF_SPITARG3_cputargets_byte_offset0_START (0)
#define SOC_CTF_SPITARG3_cputargets_byte_offset0_END (7)
#define SOC_CTF_SPITARG3_cputargets_byte_offset1_START (8)
#define SOC_CTF_SPITARG3_cputargets_byte_offset1_END (15)
#define SOC_CTF_SPITARG3_cputargets_byte_offset2_START (16)
#define SOC_CTF_SPITARG3_cputargets_byte_offset2_END (23)
#define SOC_CTF_SPITARG3_cputargets_byte_offset3_START (24)
#define SOC_CTF_SPITARG3_cputargets_byte_offset3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgig_id : 3;
        unsigned int reserved_0 : 13;
        unsigned int sgi_cputargetlist : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CTF_SGIG_UNION;
#endif
#define SOC_CTF_SGIG_sgig_id_START (0)
#define SOC_CTF_SGIG_sgig_id_END (2)
#define SOC_CTF_SGIG_sgi_cputargetlist_START (16)
#define SOC_CTF_SGIG_sgi_cputargetlist_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgid0_status : 8;
        unsigned int sgid1_status : 8;
        unsigned int sgid2_status : 8;
        unsigned int sgid3_status : 8;
    } reg;
} SOC_CTF_SGIPSTAT0_UNION;
#endif
#define SOC_CTF_SGIPSTAT0_sgid0_status_START (0)
#define SOC_CTF_SGIPSTAT0_sgid0_status_END (7)
#define SOC_CTF_SGIPSTAT0_sgid1_status_START (8)
#define SOC_CTF_SGIPSTAT0_sgid1_status_END (15)
#define SOC_CTF_SGIPSTAT0_sgid2_status_START (16)
#define SOC_CTF_SGIPSTAT0_sgid2_status_END (23)
#define SOC_CTF_SGIPSTAT0_sgid3_status_START (24)
#define SOC_CTF_SGIPSTAT0_sgid3_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgid4_status : 8;
        unsigned int sgid5_status : 8;
        unsigned int sgid6_status : 8;
        unsigned int sgid7_status : 8;
    } reg;
} SOC_CTF_SGIPSTAT1_UNION;
#endif
#define SOC_CTF_SGIPSTAT1_sgid4_status_START (0)
#define SOC_CTF_SGIPSTAT1_sgid4_status_END (7)
#define SOC_CTF_SGIPSTAT1_sgid5_status_START (8)
#define SOC_CTF_SGIPSTAT1_sgid5_status_END (15)
#define SOC_CTF_SGIPSTAT1_sgid6_status_START (16)
#define SOC_CTF_SGIPSTAT1_sgid6_status_END (23)
#define SOC_CTF_SGIPSTAT1_sgid7_status_START (24)
#define SOC_CTF_SGIPSTAT1_sgid7_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 29;
        unsigned int ppistatus : 2;
        unsigned int reserved_1: 1;
    } reg;
} SOC_CTF_PPIPSTAT_UNION;
#endif
#define SOC_CTF_PPIPSTAT_ppistatus_START (29)
#define SOC_CTF_PPIPSTAT_ppistatus_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spistatus : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CTF_SPIPSTAT_UNION;
#endif
#define SOC_CTF_SPIPSTAT_spistatus_START (0)
#define SOC_CTF_SPIPSTAT_spistatus_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iar_intid : 10;
        unsigned int iar_cpuid : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_CTF_IAR_UNION;
#endif
#define SOC_CTF_IAR_iar_intid_START (0)
#define SOC_CTF_IAR_iar_intid_END (9)
#define SOC_CTF_IAR_iar_cpuid_START (10)
#define SOC_CTF_IAR_iar_cpuid_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eoir_intid : 10;
        unsigned int eoir_cpuid : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_CTF_EOIR_UNION;
#endif
#define SOC_CTF_EOIR_eoir_intid_START (0)
#define SOC_CTF_EOIR_eoir_intid_END (9)
#define SOC_CTF_EOIR_eoir_cpuid_START (10)
#define SOC_CTF_EOIR_eoir_cpuid_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nfiq_stat : 1;
        unsigned int nirq_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CTF_OUTSTAT_UNION;
#endif
#define SOC_CTF_OUTSTAT_nfiq_stat_START (0)
#define SOC_CTF_OUTSTAT_nfiq_stat_END (0)
#define SOC_CTF_OUTSTAT_nirq_stat_START (1)
#define SOC_CTF_OUTSTAT_nirq_stat_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
