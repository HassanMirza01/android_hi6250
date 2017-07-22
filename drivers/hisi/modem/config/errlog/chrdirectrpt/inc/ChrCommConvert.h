/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

******************************************************************************
File Name       : ChrcommConvert.h
Description     : 结构体描述信息头文件
History         :
   1.l00353313     2016-6-16     Draft Enact

******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#include  "product_config.h"
#include  "vos.h"
#include  "omerrorlog.h"

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif


/* xml的数据类型 */
enum FIELD_TYPE_ENUM
{
    FIELD_TYPE_INT = 1,     /* 有符号整形，包括char, short, int, long */
    FIELD_TYPE_UINT,    /* 无符号整形，包括unsigned char, unsigned short, unsinged int, unsigned long */
    FIELD_TYPE_VARCHAR, /* 字符串，char[] */
    FIELD_TYPE_ENUM,    /* 枚举 */
    FIELD_TYPE_ARRAY,   /* 字节数组 byte[] */
    FIELD_TYPE_DATETIME,    /* 日期时间 */
    FIELD_TYPE_CLASS,       /* 结构体 */
    FIELD_TYPE_CLASSARRAY,  /* 结构体数组 */
    FIELD_TYPE_ENUMARRAY,   /* 枚举数组 */
    FIELD_TYPE_MASK = 0xFF,
};

/* 字段描述 */
typedef struct
{
    VOS_UINT16          FieldType;
    VOS_UINT16          FieldLength;
} FIELD_DESC;

/* 结构体描述信息结构体 */
typedef struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[1];
} STRUCT_DESC;

/* 结构体描述信息 */
extern const VOS_VOID * const g_FaultStructDesc[];
/* 结构体个数 */
extern const VOS_UINT32 g_FaultStructDescCount;

extern const VOS_VOID * const g_EventStructDesc[];
extern const VOS_UINT32 g_EventStructDescCount;

/* 直通新接口定义，新增事件或XML结构改变时必须更新 */
extern   VOS_UINT8  aucProductName[20];
extern   VOS_UINT8  ucLogVersion;

/*****************************************************************************
 函 数 名  : Modem_ErrLog_FillModemHeader
 功能描述  : 填充直通事件接口MODEM_ERR_LOG_HEADER_STRU
 输入参数  : pstmodemHeader      直通事件接口ModemHeader
             usSubEventID        子事件事件ID
             ucSubEventCause     子事件原因值
             enModemHidsLog      该事件是否抓取保存HiDS日志

 输出参数  :

 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年07月15日
    作    者   : q00312157
    修改内容   : Modem直通项目新增
*****************************************************************************/
extern VOS_VOID Modem_ErrLog_FillModemHeader(MODEM_ERR_LOG_HEADER_STRU *pstmodemHeader, VOS_UINT16 usSubEventID,
                                              VOS_UINT8 ucSubEventCause, VOS_BOOL enModemHidsLog);


/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertEvent
 功能描述  : 把关联事件中的子事件结构体转换为字节流。
             调用前可使用Modem_ErrLog_CalcEventSize计算转换后的字节流长度，用于提前分配缓冲区
             转换后的字节流需要与关联事件的其他子事件一起打包之后，才可作为给AP的参数
 输入参数  : usEventID     子事件ID（ALARMID）
             pBuffer       字节流缓冲区
             ulBufferSize  字节流缓冲区大小
             pStruct       子事件结构体指针
             ulStructSize  结构体数据长度

 输出参数  : pBufferLen    字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
extern VOS_INT32 Modem_ErrLog_ConvertEvent(VOS_UINT16 usEventID, VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize);

/*****************************************************************************
 函 数 名  : Modem_ErrLog_CalcEventSize
 功能描述  : 获取关联事件的子事件字节流长度。
             用于在调用字节流转换函数Modem_ErrLog_ConvertEvent之前提前计算所需的缓冲区
 输入参数  : usEventID     子事件ID（ALARMID）

 输出参数  :

 返 回 值  : 0：失败  其他：字节流长度
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
extern VOS_INT32 Modem_ErrLog_CalcEventSize(VOS_UINT16 usEventID);

/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertAbsoluteEvent
 功能描述  : 把非关联事件中的子事件结构体转换为字节流。
             调用前可使用Modem_ErrLog_CalcAbsoluteEventSize计算转换后的字节流长度，用于提前分配缓冲区
             转换后的字节流可直接作为给AP的参数
 输入参数  : usEventID     子事件ID（ALARMID）
             pBuffer       字节流缓冲区
             ulBufferSize  字节流缓冲区大小
             pStruct       子事件结构体指针
             ulStructSize  结构体数据长度

 输出参数  : pBufferLen    字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
extern VOS_INT32 Modem_ErrLog_ConvertAbsoluteEvent(VOS_UINT16 usEventID, VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize);

/*****************************************************************************
 函 数 名  : Modem_ErrLog_CalcAbsoluteEventSize
 功能描述  : 获取非关联事件字节流长度
             用于在调用字节流转换函数Modem_ErrLog_ConvertEvent之前提前计算所需的缓冲区
 输入参数  : usEventID     子事件ID（ALARMID）

 输出参数  :

 返 回 值  : 0：失败  其他：字节流长度
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
extern VOS_INT32 Modem_ErrLog_CalcAbsoluteEventSize(VOS_UINT16 usEventID);

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

