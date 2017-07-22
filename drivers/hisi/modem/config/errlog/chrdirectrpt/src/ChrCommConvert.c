/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

******************************************************************************
File Name       : ChrCommConvert.c
Description     : 包含CHR直通事件结构体转换引用文件
History         :
   1.q00312157      2016-5-25     Draft Enact

******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include  "ChrCommConvert.h"

/*
#define    THIS_FILE_ID            PS_FILE_ID_CHRCOMMCONVERT_C
*/

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/
/* 直通新接口定义，新增事件或XML结构改变时必须更新 */
VOS_UINT8  aucProductName[20] = {"COMMON#102"};
VOS_UINT8  ucLogVersion       = 3;


/*****************************************************************************
  3 函数实现
*****************************************************************************/

/*****************************************************************************
 函 数 名  : Modem_ErrLog_FillModemHeader
 功能描述  : 填充直通事件接口MODEM_ERR_LOG_HEADER_STRU
 输入参数  : pstmodemHeader      直通事件接口ModemHeader
             usSubEventID        子事件事件ID，填充对应的非关联子事件事件ID；关联事件默认填0
             ucSubEventCause     子事件原因值，AP目前未使用，默认为0
             enModemHidsLog      该事件是否抓取保存HiDS日志，默认不抓取，特殊事件需要定位问题打开

 输出参数  :

 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年07月15日
    作    者   : q00312157
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_VOID Modem_ErrLog_FillModemHeader(MODEM_ERR_LOG_HEADER_STRU *pstmodemHeader, VOS_UINT16 usSubEventID,
                                              VOS_UINT8 ucSubEventCause, VOS_BOOL enModemHidsLog)
{

    if (VOS_NULL_PTR == pstmodemHeader)
    {
        return;
    }
    memcpy_s(pstmodemHeader->aucProductName, 20, aucProductName, 20);

    pstmodemHeader->usSubEventID    = usSubEventID;
    pstmodemHeader->enModemHidsLog  = enModemHidsLog;
    pstmodemHeader->ucLogVersion    = ucLogVersion;
    pstmodemHeader->ucSubEventCause = ucSubEventCause;
}


/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertStruct
 功能描述  : 把结构体转换为字节流
 输入参数  : pBuffer        字节流缓冲区
             ulBufferSize     字节流缓冲区大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pStructDesc    结构体描述信息

 输出参数  : pBufferLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_ConvertStruct(VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize,
    const STRUCT_DESC *pStructDesc);

/*****************************************************************************
 函 数 名  : GetStructDescByEventID
 功能描述  : 获取事件结构体描述信息
 输入参数  : usEventID        事件ID

 输出参数  :

 返 回 值  : const STRUCT_DESC *：success  VOS_NULL_PTR：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
const STRUCT_DESC * GetStructDescByEventID(VOS_UINT16 usEventID)
{
    VOS_UINT32 i = 0;
    const STRUCT_DESC *pStructDesc = VOS_NULL_PTR;
    for (i = 0; i < g_FaultStructDescCount; ++i)
    {
        pStructDesc = (const STRUCT_DESC *) g_FaultStructDesc[i];
        if (VOS_NULL_PTR != pStructDesc && usEventID == pStructDesc->EventID)
        {
            return pStructDesc;
        }
    }

    return VOS_NULL_PTR;
}

/*****************************************************************************
 函 数 名  : GetStructDescByStructID
 功能描述  : 获取结构体描述信息，包括事件和子结构体
 输入参数  : usStructID        事件、结构体ID

 输出参数  :

 返 回 值  : const STRUCT_DESC *：success  VOS_NULL_PTR：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
const STRUCT_DESC * GetStructDescByStructID(VOS_UINT16 usStructID)
{
    VOS_UINT32 i = 0;
    const STRUCT_DESC *pStructDesc = VOS_NULL_PTR;
    for (i = 0; i < g_FaultStructDescCount; ++i)
    {
        pStructDesc = (const STRUCT_DESC *) g_FaultStructDesc[i];
        if (VOS_NULL_PTR != pStructDesc && usStructID == pStructDesc->StructID)
        {
            return pStructDesc;
        }
    }

    return VOS_NULL_PTR;
}

/*****************************************************************************
 函 数 名  : GetStructDescByAbsoluteEventID
 功能描述  : 获取事件结构体描述信息
 输入参数  : usEventID        事件ID

 输出参数  :

 返 回 值  : const STRUCT_DESC *：success  VOS_NULL_PTR：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
const STRUCT_DESC * GetStructDescByAbsoluteEventID(VOS_UINT16 usEventID)
{
    VOS_UINT32 i = 0;
    VOS_UINT32 j = 0;
    const STRUCT_DESC *pStructDesc = VOS_NULL_PTR;
    const FIELD_DESC *pField = VOS_NULL_PTR;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;
    for (i = 0; i < g_EventStructDescCount; ++i)
    {
        pStructDesc = (const STRUCT_DESC *) g_EventStructDesc[i];
        if (VOS_NULL_PTR != pStructDesc)
        {
            for (j = 0; j < pStructDesc->FieldCount; ++j)
            {
                pField = &pStructDesc->Fields[j];
                if (FIELD_TYPE_CLASS == pField->FieldType)
                {
                    pSubStructDesc = GetStructDescByStructID(pField->FieldLength);
                    if (VOS_NULL_PTR != pSubStructDesc && usEventID == pSubStructDesc->EventID)
                    {
                        return pStructDesc;
                    }
                }
            }
        }
    }

    return VOS_NULL_PTR;
}

/*****************************************************************************
 函 数 名  : CopyValue
 功能描述  : 把字段值转换为字节流，是要进行高低字节转换
 输入参数  : pDst        字节流缓冲区
             pSrc        字段值指针
             ulLen       字段长度

 输出参数  :

 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
void CopyValue(VOS_UINT8 *pDst, const VOS_UINT8 *pSrc, VOS_UINT32 ulLen)
{
    VOS_UINT32 i = 0;

    if (VOS_NULL_PTR != pDst && VOS_NULL_PTR != pSrc)
    {
        for (i = 0; i < ulLen; ++i)
        {
            pDst[i] = pSrc[ulLen - i - 1];
        }
    }
}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertStructByDesc
 功能描述  : 把结构体转换为字节流
 输入参数  : pBuffer        字节流缓冲区
             ulBufferSize     字节流缓冲区大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pSubStructDesc        结构体描述信息

 输出参数  : pBufferLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_ConvertStructByDesc(VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
                                         VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize,
                                         const STRUCT_DESC *pSubStructDesc)
{
    VOS_INT32 ret = VOS_ERR;

    if (VOS_NULL_PTR == pSubStructDesc || 2 + ulStructSize > ulBufferSize)
    {
        return VOS_ERR;
    }

    CopyValue(pBuffer, (VOS_UINT8 *) &pSubStructDesc->StructID, 2);
    pBuffer += 2;
    ulBufferSize -= 2;

    ret = Modem_ErrLog_ConvertStruct(pBuffer, ulBufferSize, pBufferLen, pStruct, ulStructSize, pSubStructDesc);
    if (VOS_OK != ret || ulBufferSize < *pBufferLen)
    {
        return VOS_ERR;
    }

    *pBufferLen = *pBufferLen + 2;

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertStructByID
 功能描述  : 把结构体转换为字节流
 输入参数  : pBuffer        字节流缓冲区
             ulBufferSize     字节流缓冲区大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             usStructID        结构体ID

 输出参数  : pBufferLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_ConvertStructByID(VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize,
    VOS_UINT16 usStructID)
{
    const STRUCT_DESC *pSubStructDesc = GetStructDescByStructID(usStructID);

    return Modem_ErrLog_ConvertStructByDesc(pBuffer, ulBufferSize, pBufferLen, pStruct, ulStructSize, pSubStructDesc);
}

/*****************************************************************************
 函 数 名  : ConvertField_ClassArray
 功能描述  : 把结构体的子结构体字段转换为字节流
 输入参数  : p        字节流缓冲区
             ulSize     字节流缓冲区大小
             pStructLen    字段的字节大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pField    结构体字段描述信息

 输出参数  : pLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 ConvertField_Class(VOS_UINT8 *p, VOS_UINT32 ulSize, VOS_UINT32 *pLen, VOS_UINT32 *pStructLen,
                             const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize, const FIELD_DESC *pField)
{
    VOS_INT32 ret = VOS_ERR;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;

    if (VOS_NULL_PTR == p || VOS_NULL_PTR == pLen || VOS_NULL_PTR == pStructLen || VOS_NULL_PTR == pStruct || VOS_NULL_PTR == pField)
    {
        return VOS_ERR;
    }

    *pLen = 0;
    *pStructLen = 0;

    pSubStructDesc = GetStructDescByStructID(pField->FieldLength);

    if (VOS_NULL_PTR == pSubStructDesc)
    {
        return VOS_ERR;
    }

    ret = Modem_ErrLog_ConvertStructByDesc(p, ulSize, pLen, pStruct, ulStructSize, pSubStructDesc);
    if (VOS_OK != ret || ulSize < *pLen)
    {
        return VOS_ERR;
    }

    *pStructLen = pSubStructDesc->StructSize;
    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : ConvertField_ClassArray
 功能描述  : 把结构体的子结构体数组字段转换为字节流
 输入参数  : p        字节流缓冲区
             ulSize     字节流缓冲区大小
             pStructLen    字段的字节大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pField    结构体字段描述信息

 输出参数  : pLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 ConvertField_ClassArray(VOS_UINT8 *p, VOS_UINT32 ulSize, VOS_UINT32 *pLen, VOS_UINT32 *pStructLen,
                             const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize, const FIELD_DESC *pField)
{
    VOS_INT32 ret = VOS_ERR;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;
    VOS_UINT16 usArraySize = 0;
    VOS_UINT32 j = 0;
    VOS_UINT32 ulLen = 0;

    if (VOS_NULL_PTR == p || VOS_NULL_PTR == pLen || VOS_NULL_PTR == pStructLen || VOS_NULL_PTR == pStruct || VOS_NULL_PTR == pField || 2 + ulStructSize > ulSize)
    {
        return VOS_ERR;
    }

    *pLen = 0;
    *pStructLen = 0;

    /* 数组的FieldType高24位为数组元素个数 */
    usArraySize = pField->FieldType >> 8;

    CopyValue(p, (VOS_UINT8 *) &usArraySize, 2);
    p += 2;
    *pLen = *pLen + 2;

    pSubStructDesc = GetStructDescByStructID(pField->FieldLength);

    if (VOS_NULL_PTR == pSubStructDesc)
    {
        return VOS_ERR;
    }

    for (j = 0; j < usArraySize; ++j)
    {
        ret = Modem_ErrLog_ConvertStructByDesc(p, ulSize, &ulLen, pStruct, ulStructSize, pSubStructDesc);
        if (VOS_OK != ret || ulSize < ulLen)
        {
            return VOS_ERR;
        }

        p += ulLen;
        ulSize -= ulLen;
        pStruct += pSubStructDesc->StructSize;
        ulStructSize -= pSubStructDesc->StructSize;
        *pLen += ulLen;
    }

    *pStructLen = usArraySize * pSubStructDesc->StructSize;
    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : ConvertField_Array
 功能描述  : 把结构体的字符串、字节数组字段转换为字节流
 输入参数  : p        字节流缓冲区
             ulSize     字节流缓冲区大小
             pStructLen    字段的字节大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pField    结构体字段描述信息

 输出参数  : pLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 ConvertField_Array(VOS_UINT8 *p, VOS_UINT32 ulSize, VOS_UINT32 *pLen, VOS_UINT32 *pStructLen,
                             const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize, const FIELD_DESC *pField)
{
    if (VOS_NULL_PTR == p || VOS_NULL_PTR == pLen || VOS_NULL_PTR == pStruct || VOS_NULL_PTR == pField)
    {
        return VOS_ERR;
    }

    *pLen = 0;
    *pStructLen = 0;

    /* 根据字段类型进行转换 */
    switch (pField->FieldType & FIELD_TYPE_MASK)
    {
    case FIELD_TYPE_VARCHAR:
    case FIELD_TYPE_ARRAY:
        {
            if (pField->FieldLength > ulSize || pField->FieldLength > ulStructSize)
            {
                return VOS_ERR;
            }

            *pLen = pField->FieldLength;
            memcpy_s(p, ulSize, pStruct, *pLen);

            *pStructLen = pField->FieldLength;
            break;
        }
    default:
        {
            return VOS_ERR;
        }
    }
    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : ConvertField_Value
 功能描述  : 把结构体的整形、枚举、枚举数组字段转换为字节流
 输入参数  : p        字节流缓冲区
             ulSize     字节流缓冲区大小
             pStructLen    字段的字节大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pField    结构体字段描述信息

 输出参数  : pLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 ConvertField_Value(VOS_UINT8 *p, VOS_UINT32 ulSize, VOS_UINT32 *pLen, VOS_UINT32 *pStructLen,
                             const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize, const FIELD_DESC *pField)
{
    VOS_UINT16 usArraySize = 0;
    VOS_UINT32 ulDataLen = 0;
    VOS_UINT32 i = 0;

    if (VOS_NULL_PTR == p || VOS_NULL_PTR == pLen || VOS_NULL_PTR == pStruct || VOS_NULL_PTR == pField)
    {
        return VOS_ERR;
    }

    *pLen = 0;
    *pStructLen = 0;

    /* 根据字段类型进行转换 */
    switch (pField->FieldType & FIELD_TYPE_MASK)
    {
        /* 枚举数组 */
    case FIELD_TYPE_ENUMARRAY:
        {
            /* 数组的FieldType高24位为数组元素个数 */
            usArraySize = pField->FieldType >> 8;

            /* 枚举数组的FieldLength为枚举的字节长度 */
            ulDataLen = (VOS_UINT32) pField->FieldLength * usArraySize;
            if (ulDataLen + 2 > ulSize || ulDataLen > ulStructSize)
            {
                return VOS_ERR;
            }

            CopyValue(p, (VOS_UINT8 *) &usArraySize, 2);
            p += 2;
            *pLen = *pLen + 2;

            for (i = 0; i < usArraySize; ++i)
            {
                CopyValue(p + i * pField->FieldLength, pStruct + i * pField->FieldLength, pField->FieldLength);
            }

            *pLen = *pLen + ulDataLen;

            *pStructLen = ulDataLen;
            break;
        }
        /* 有符号整形、无符号整形、字符串、字节数组、枚举 */
    case FIELD_TYPE_INT:
    case FIELD_TYPE_UINT:
    case FIELD_TYPE_ENUM:
        {
            if (pField->FieldLength > ulSize || pField->FieldLength > ulStructSize)
            {
                return VOS_ERR;
            }

            *pLen = pField->FieldLength;
            CopyValue(p, pStruct, *pLen);

            *pStructLen = pField->FieldLength;
            break;
        }
    default:
        {
            return VOS_ERR;
        }
    }
    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_ConvertStruct
 功能描述  : 把结构体转换为字节流
 输入参数  : pBuffer        字节流缓冲区
             ulBufferSize     字节流缓冲区大小
             pStruct        结构体指针
             ulStructSize    结构体数据长度
             pStructDesc    结构体描述信息

 输出参数  : pBufferLen        字节流长度

 返 回 值  : VOS_OK：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_ConvertStruct(VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize,
    const STRUCT_DESC *pStructDesc)
{
    VOS_UINT32 i = 0;
    const FIELD_DESC *pField = VOS_NULL_PTR;
    VOS_INT32 ret = VOS_OK;
    /* 写入缓冲区的临时指针 */
    VOS_UINT8 *p = pBuffer;
    /* 缓冲区剩余空间 */
    VOS_UINT32 ulSize = ulBufferSize;
    /* 缓冲区长度 */
    VOS_UINT32 ulLen = 0;
    /* 子结构体的大小 */
    VOS_UINT32 ulStructLen = 0;

    if (VOS_NULL_PTR == pBuffer || VOS_NULL_PTR == pStruct || NULL == pBufferLen || VOS_NULL_PTR == pStructDesc || ulBufferSize < ulStructSize)
    {
        return VOS_ERR;
    }

    /* bParamInvalid已经进行了空指针判断，下面的PCLINT可以屏蔽 */
    /*lint -save -e613*/
    /* 初始化返回的字节流长度 */
    *pBufferLen = 0;

    for (i = 0; i < pStructDesc->FieldCount; ++i)
    {
        pField = &pStructDesc->Fields[i];

        /* 根据字段类型进行转换 */
        switch (pField->FieldType & FIELD_TYPE_MASK)
        {
        /* 子结构体 */
        case FIELD_TYPE_CLASS:
            {
                ret = ConvertField_Class(p, ulSize, &ulLen, &ulStructLen, pStruct, ulStructSize, pField);
                break;
            }
        /* 子结构体数组 */
        case FIELD_TYPE_CLASSARRAY:
            {
                ret = ConvertField_ClassArray(p, ulSize, &ulLen, &ulStructLen, pStruct, ulStructSize, pField);
                break;
            }
        /* 枚举数组 */
        case FIELD_TYPE_ENUMARRAY:
        /* 有符号整形、无符号整形、字符串、字节数组、枚举 */
        case FIELD_TYPE_INT:
        case FIELD_TYPE_UINT:
        case FIELD_TYPE_ENUM:
            {
                ret = ConvertField_Value(p, ulSize, &ulLen, &ulStructLen, pStruct, ulStructSize, pField);
                break;
            }
        case FIELD_TYPE_VARCHAR:
        case FIELD_TYPE_ARRAY:
            {
                ret = ConvertField_Array(p, ulSize, &ulLen, &ulStructLen, pStruct, ulStructSize, pField);
                break;
            }
        /* 日期时间，不支持  */
        case FIELD_TYPE_DATETIME:
        default:
            {
                return VOS_ERR;
            }
        }

        if (VOS_OK != ret)
        {
            return ret;
        }

        p += ulLen;
        ulSize -= ulLen;
        pStruct += ulStructLen;
        ulStructSize -= ulStructLen;
    }

    *pBufferLen = (VOS_UINT32) (p - pBuffer);
    /*lint -restore*/
    return VOS_OK;
}

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
VOS_INT32 Modem_ErrLog_ConvertEvent(VOS_UINT16 usEventID, VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize)
{
    const STRUCT_DESC *pStructDesc = GetStructDescByEventID(usEventID);

    if (VOS_NULL_PTR == pBuffer || VOS_NULL_PTR == pStruct || NULL == pBufferLen || ulBufferSize < ulStructSize + 2 || VOS_NULL_PTR == pStructDesc)
    {
        return VOS_ERR;
    }

    /* 子事件填充子结构体ID, 事件不填ID */
    CopyValue(pBuffer, (VOS_UINT8 *) &pStructDesc->StructID, 2);
    pBuffer += 2;
    ulBufferSize -= 2;

    *pBufferLen = 0;
    if (VOS_OK == Modem_ErrLog_ConvertStruct(pBuffer, ulBufferSize, pBufferLen, pStruct, ulStructSize, pStructDesc))
    {
        *pBufferLen = *pBufferLen + 2;
        return VOS_OK;
    }
    else
    {
        return VOS_ERR;
    }
}

/*****************************************************************************
 函 数 名  : CalcStructSize
 功能描述  : 获取子结构体字节流长度
 输入参数  : pStructDesc       结构体描述信息

 输出参数  :

 返 回 值  : 0：失败  其他：字节流长度
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月15日
    作    者   : l00353313
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 CalcStructSize(const STRUCT_DESC *pStructDesc)
{
    VOS_UINT32 i = 0;
    const FIELD_DESC *pField = VOS_NULL_PTR;
    VOS_INT32 lRet = 0;
    VOS_INT32 lSize = 0;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;
    VOS_UINT16 usArraySize = 0;

    if (VOS_NULL_PTR == pStructDesc)
    {
        return 0;
    }

    for (i = 0; i < pStructDesc->FieldCount; ++i)
    {
        pField = &pStructDesc->Fields[i];

        /* 根据字段类型进行转换 */
        switch (pField->FieldType & FIELD_TYPE_MASK)
        {
        /* 子结构体 */
        case FIELD_TYPE_CLASS:
            {
                pSubStructDesc = GetStructDescByStructID(pField->FieldLength);
                lRet = CalcStructSize(pSubStructDesc);
                if (0 != lRet)
                {
                    lRet += 2;
                }
                break;
            }
        /* 子结构体数组 */
        case FIELD_TYPE_CLASSARRAY:
            {
                pSubStructDesc = GetStructDescByStructID(pField->FieldLength);
                usArraySize = pField->FieldType >> 8;
                lRet = CalcStructSize(pSubStructDesc);
                if (0 != lRet)
                {
                    lRet = 2 + (lRet + 2) * usArraySize;
                }
                break;
            }
        /* 枚举数组 */
        case FIELD_TYPE_ENUMARRAY:
        /* 有符号整形、无符号整形、字符串、字节数组、枚举 */
            {
                lRet = 2 + pField->FieldLength * (pField->FieldType >> 8);
                break;
            }
        case FIELD_TYPE_INT:
        case FIELD_TYPE_UINT:
        case FIELD_TYPE_ENUM:
        case FIELD_TYPE_VARCHAR:
        case FIELD_TYPE_ARRAY:
            {
                lRet = pField->FieldLength;
                break;
            }
        /* 日期时间，不支持  */
        case FIELD_TYPE_DATETIME:
        default:
            {
                return 0;
            }
        }

        if (0 == lRet)
        {
            return 0;
        }

        lSize += lRet;
    }

    return lSize;
}

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
VOS_INT32 Modem_ErrLog_CalcEventSize(VOS_UINT16 usEventID)
{
    VOS_INT32 lSize = 2;
    const STRUCT_DESC *pStructDesc = GetStructDescByEventID(usEventID);
    VOS_INT32 lRet = 0;

    if (NULL == pStructDesc)
    {
        return 0;
    }

    lRet = CalcStructSize(pStructDesc);

    if (0 >= lRet)
    {
        return 0;
    }

    lSize += lRet;

    return lSize;
}

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
VOS_INT32 Modem_ErrLog_ConvertAbsoluteEvent(VOS_UINT16 usEventID, VOS_UINT8 *pBuffer, VOS_UINT32 ulBufferSize,
    VOS_UINT32 *pBufferLen, const VOS_UINT8 *pStruct, VOS_UINT32 ulStructSize)
{
    VOS_UINT32 j = 0;
    const FIELD_DESC *pField = VOS_NULL_PTR;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;
    const STRUCT_DESC *pStructDesc = GetStructDescByAbsoluteEventID(usEventID);
    VOS_UINT32 len = 0;

    if (VOS_NULL_PTR == pBuffer || VOS_NULL_PTR == pStruct || NULL == pBufferLen || ulBufferSize < ulStructSize + 2 || VOS_NULL_PTR == pStructDesc)
    {
        return VOS_ERR;
    }

    *pBufferLen = 0;
    for (j = 0; j < pStructDesc->FieldCount; ++j)
    {
        pField = &pStructDesc->Fields[j];
        if (FIELD_TYPE_CLASS != pField->FieldType)
        {
            return VOS_ERR;
        }

        pSubStructDesc = GetStructDescByStructID(pField->FieldLength);
        if (VOS_NULL_PTR == pSubStructDesc)
        {
            return VOS_ERR;
        }

        if (usEventID == pSubStructDesc->EventID)
        {
            CopyValue(pBuffer, (VOS_UINT8 *) &pSubStructDesc->StructID, 2);
            pBuffer += 2;
            ulBufferSize -= 2;
            len += 2;
            if (VOS_OK != Modem_ErrLog_ConvertStruct(pBuffer, ulBufferSize, pBufferLen, pStruct, ulStructSize, pSubStructDesc))
            {
                return VOS_ERR;
            }
            pBuffer += *pBufferLen;
            ulBufferSize -= *pBufferLen;
        }
        else
        {
            *((VOS_UINT16 *) pBuffer) = 0xFFFFu;
            pBuffer += 2;
            ulBufferSize -= 2;
            len += 2;
        }
    }
    *pBufferLen = *pBufferLen + len;
    return VOS_OK;
}

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
VOS_INT32 Modem_ErrLog_CalcAbsoluteEventSize(VOS_UINT16 usEventID)
{
    VOS_UINT32 j = 0;
    const FIELD_DESC *pField = VOS_NULL_PTR;
    const STRUCT_DESC *pSubStructDesc = VOS_NULL_PTR;
    const STRUCT_DESC *pStructDesc = GetStructDescByAbsoluteEventID(usEventID);
    VOS_INT32 lSize = 0;
    VOS_INT32 lRet = 0;

    if (VOS_NULL_PTR == pStructDesc)
    {
        return 0;
    }

    for (j = 0; j < pStructDesc->FieldCount; ++j)
    {
        pField = &pStructDesc->Fields[j];
        if (FIELD_TYPE_CLASS != pField->FieldType)
        {
            return 0;
        }

        pSubStructDesc = GetStructDescByStructID(pField->FieldLength);
        if (VOS_NULL_PTR == pSubStructDesc)
        {
            return 0;
        }

        if (usEventID == pSubStructDesc->EventID)
        {
            lRet = CalcStructSize(pSubStructDesc);

            if (0 >= lRet)
            {
                return 0;
            }

            lSize += 2 + lRet;
        }
        else
        {
            lSize += 2;
        }
    }
    return lSize;
}




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif


