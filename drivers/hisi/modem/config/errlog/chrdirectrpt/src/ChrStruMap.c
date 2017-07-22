#include "ChrCommConvert.h"
#include "ChrEventIDComm.h"

enum STRUCT_ID_ENUM
{
    LL2_OM_VOLTE_STAT_INFO_STRU_ID	= 77,
    LMAC_OM_PRACH_CONFIG_STRU_ID	= 71,
    LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_SUBEVENT	= 36,
    LPS_LOW_QUILITY_ABNORMAL_STRU_ID	= 73,
    LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_SUBEVENT	= 41,
    LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_SUBEVENT	= 48,
    LRRC_OM_AIR_SIGNAL_INFO_STRU_ID	= 74,
    LRRC_OM_LAYER_EVENT_INFO_STRU_ID	= 75,
    LRRC_OM_MEASRPT_INFO_ID	= 76,
    LRRC_OM_SCELL_ID_ID	= 69,
    LRRC_OM_TAC_STRU_ID	= 72,
    LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU_ID	= 58,
    LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU_ID	= 60,
    PCH_CELL_INFO_REPORT_STRU_ID	= 66,
    TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU_ID	= 68,
    TLL2_OOS_INFO_STRU_SUBEVENT	= 22,
    TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_SUBEVENT	= 24,
    TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_SUBEVENT	= 33,
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU_ID	= 64,
    TRRC_APP_STATE_INFO_STRU_ID	= 63,
    TRRC_CS_CALL_AIRMSG_INFO_STRU_SUBEVENT	= 29,
    TRRC_CS_CALL_CONN_REQ_INFO_STRU_SUBEVENT	= 26,
    TRRC_CS_CALL_EST_CNF_INFO_STRU_SUBEVENT	= 25,
    TRRC_CS_CALL_MM_INFO_STRU_ID	= 65,
    TRRC_OOS_INFO_STRU_SUBEVENT	= 21,
    TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_SUBEVENT	= 23,
    T_CellDesc_Tag_ID	= 67,
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[1];
} g_LL2_STATISTIC_INFO_COLLECTION = 
{
    LL2_STATISTIC_INFO_COLLECTION_EVENTID,     0,     260,     1,
    {
    {FIELD_TYPE_CLASS, LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_SUBEVENT},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[3];
} g_LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU = 
{
    LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_ALARMID,     LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_SUBEVENT,     260,     3,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ARRAY, 3},
    {0x800 | FIELD_TYPE_CLASSARRAY, TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[56];
} g_LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU = 
{
    LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_ALARMID,     LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_SUBEVENT,     1712,     56,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_CLASS, LRRC_OM_TAC_STRU_ID},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_CLASS, LPS_LOW_QUILITY_ABNORMAL_STRU_ID},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {0x1400 | FIELD_TYPE_CLASSARRAY, LRRC_OM_AIR_SIGNAL_INFO_STRU_ID},
    {FIELD_TYPE_UINT, 4},
    {0x3800 | FIELD_TYPE_CLASSARRAY, LRRC_OM_LAYER_EVENT_INFO_STRU_ID},
    {FIELD_TYPE_UINT, 4},
    {0x1000 | FIELD_TYPE_CLASSARRAY, LRRC_OM_MEASRPT_INFO_ID},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {0x600 | FIELD_TYPE_CLASSARRAY, LL2_OM_VOLTE_STAT_INFO_STRU_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[30];
} g_LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU = 
{
    LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_ALARMID,     LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_SUBEVENT,     576,     30,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    {0x1000 | FIELD_TYPE_CLASSARRAY, LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU_ID},
    {FIELD_TYPE_UINT, 4},
    {0x2800 | FIELD_TYPE_CLASSARRAY, LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[1];
} g_LPS_VOLTE_STAT_IND = 
{
    LPS_VOLTE_STAT_IND_EVENTID,     0,     576,     1,
    {
    {FIELD_TYPE_CLASS, LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_SUBEVENT},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[1];
} g_LRRC_VOLTE_FAULT_AUTOAN_IND = 
{
    LRRC_VOLTE_FAULT_AUTOAN_IND_EVENTID,     0,     1712,     1,
    {
    {FIELD_TYPE_CLASS, LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_SUBEVENT},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[2];
} g_TDS_OOS_INFO_REPORT = 
{
    TDS_OOS_INFO_REPORT_FAULTID,     0,     44,     2,
    {
    {FIELD_TYPE_CLASS, TRRC_OOS_INFO_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TLL2_OOS_INFO_STRU_SUBEVENT},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[4];
} g_TLL2_OOS_INFO_STRU = 
{
    TLL2_OOS_INFO_STRU_ALARMID,     TLL2_OOS_INFO_STRU_SUBEVENT,     4,     4,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[50];
} g_TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU = 
{
    TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_ALARMID,     TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_SUBEVENT,     100,     50,
    {
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[2];
} g_TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU = 
{
    TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_ALARMID,     TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_SUBEVENT,     84,     2,
    {
    {FIELD_TYPE_UINT, 4},
    {0xA00 | FIELD_TYPE_CLASSARRAY, PCH_CELL_INFO_REPORT_STRU_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[6];
} g_TRRC_CS_CALL_AIRMSG_INFO_STRU = 
{
    TRRC_CS_CALL_AIRMSG_INFO_STRU_ALARMID,     TRRC_CS_CALL_AIRMSG_INFO_STRU_SUBEVENT,     36,     6,
    {
    {FIELD_TYPE_CLASS, TRRC_APP_STATE_INFO_STRU_ID},
    {FIELD_TYPE_CLASS, TRRC_APP_CS_RELEASE_CELL_INFO_STRU_ID},
    {FIELD_TYPE_CLASS, TRRC_CS_CALL_MM_INFO_STRU_ID},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[12];
} g_TRRC_CS_CALL_CONN_REQ_INFO_STRU = 
{
    TRRC_CS_CALL_CONN_REQ_INFO_STRU_ALARMID,     TRRC_CS_CALL_CONN_REQ_INFO_STRU_SUBEVENT,     48,     12,
    {
    {FIELD_TYPE_CLASS, TRRC_APP_STATE_INFO_STRU_ID},
    {FIELD_TYPE_CLASS, TRRC_APP_CS_RELEASE_CELL_INFO_STRU_ID},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_ENUM, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_ARRAY, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[12];
} g_TRRC_CS_CALL_EST_CNF_INFO_STRU = 
{
    TRRC_CS_CALL_EST_CNF_INFO_STRU_ALARMID,     TRRC_CS_CALL_EST_CNF_INFO_STRU_SUBEVENT,     36,     12,
    {
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_ARRAY, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_ENUM, 4},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[13];
} g_TRRC_OOS_INFO_STRU = 
{
    TRRC_OOS_INFO_STRU_ALARMID,     TRRC_OOS_INFO_STRU_SUBEVENT,     40,     13,
    {
    {0x200 | FIELD_TYPE_ENUMARRAY, 1},
    {FIELD_TYPE_VARCHAR, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_VARCHAR, 2},
    {FIELD_TYPE_UINT, 4},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[13];
} g_TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU = 
{
    TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_ALARMID,     TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_SUBEVENT,     32,     13,
    {
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[6];
} g_TRRC_STATISTIC_INFO_COLLECTION = 
{
    TRRC_STATISTIC_INFO_COLLECTION_EVENTID,     0,     336,     6,
    {
    {FIELD_TYPE_CLASS, TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TRRC_CS_CALL_EST_CNF_INFO_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TRRC_CS_CALL_CONN_REQ_INFO_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TRRC_CS_CALL_AIRMSG_INFO_STRU_SUBEVENT},
    {FIELD_TYPE_CLASS, TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_SUBEVENT},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[13];
} g_LL2_OM_VOLTE_STAT_INFO_STRU = 
{
    0,     LL2_OM_VOLTE_STAT_INFO_STRU_ID,     24,     13,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[4];
} g_LMAC_OM_PRACH_CONFIG_STRU = 
{
    0,     LMAC_OM_PRACH_CONFIG_STRU_ID,     4,     4,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[12];
} g_LPS_LOW_QUILITY_ABNORMAL_STRU = 
{
    0,     LPS_LOW_QUILITY_ABNORMAL_STRU_ID,     12,     12,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[16];
} g_LRRC_OM_AIR_SIGNAL_INFO_STRU = 
{
    0,     LRRC_OM_AIR_SIGNAL_INFO_STRU_ID,     28,     16,
    {
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_INT, 2},
    {FIELD_TYPE_INT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_INT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_INT, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_UINT, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[3];
} g_LRRC_OM_LAYER_EVENT_INFO_STRU = 
{
    0,     LRRC_OM_LAYER_EVENT_INFO_STRU_ID,     8,     3,
    {
    {FIELD_TYPE_ENUM, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[18];
} g_LRRC_OM_MEASRPT_INFO = 
{
    0,     LRRC_OM_MEASRPT_INFO_ID,     28,     18,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[9];
} g_LRRC_OM_SCELL_ID = 
{
    0,     LRRC_OM_SCELL_ID_ID,     24,     9,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_CLASS, LRRC_OM_TAC_STRU_ID},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[3];
} g_LRRC_OM_TAC_STRU = 
{
    0,     LRRC_OM_TAC_STRU_ID,     4,     3,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ARRAY, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[6];
} g_LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU = 
{
    0,     LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU_ID,     12,     6,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_CLASS, LRRC_OM_TAC_STRU_ID},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[7];
} g_LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU = 
{
    0,     LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU_ID,     8,     7,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_ENUM, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[4];
} g_PCH_CELL_INFO_REPORT_STRU = 
{
    0,     PCH_CELL_INFO_REPORT_STRU_ID,     8,     4,
    {
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_CLASS, T_CellDesc_Tag_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[5];
} g_TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU = 
{
    0,     TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU_ID,     32,     5,
    {
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_CLASS, LRRC_OM_SCELL_ID_ID},
    {FIELD_TYPE_CLASS, LMAC_OM_PRACH_CONFIG_STRU_ID},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[5];
} g_TRRC_APP_CS_RELEASE_CELL_INFO_STRU = 
{
    0,     TRRC_APP_CS_RELEASE_CELL_INFO_STRU_ID,     8,     5,
    {
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_INT, 1},
    {FIELD_TYPE_ARRAY, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[3];
} g_TRRC_APP_STATE_INFO_STRU = 
{
    0,     TRRC_APP_STATE_INFO_STRU_ID,     4,     3,
    {
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_ENUM, 1},
    {FIELD_TYPE_ENUM, 2},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[5];
} g_TRRC_CS_CALL_MM_INFO_STRU = 
{
    0,     TRRC_CS_CALL_MM_INFO_STRU_ID,     12,     5,
    {
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 4},
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const struct
{
    VOS_UINT16          EventID;
    VOS_UINT16          StructID;
    VOS_UINT16          StructSize;
    VOS_UINT16          FieldCount;
    FIELD_DESC          Fields[3];
} g_T_CellDesc_Tag = 
{
    0,     T_CellDesc_Tag_ID,     4,     3,
    {
    {FIELD_TYPE_UINT, 2},
    {FIELD_TYPE_UINT, 1},
    {FIELD_TYPE_UINT, 1},
    }
};
const VOS_VOID * const g_FaultStructDesc[] = 
{
    (const VOS_VOID *) &g_LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU,
    (const VOS_VOID *) &g_LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU,
    (const VOS_VOID *) &g_LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU,
    (const VOS_VOID *) &g_TDS_OOS_INFO_REPORT,
    (const VOS_VOID *) &g_TLL2_OOS_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU,
    (const VOS_VOID *) &g_TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU,
    (const VOS_VOID *) &g_TRRC_CS_CALL_AIRMSG_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_CS_CALL_CONN_REQ_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_CS_CALL_EST_CNF_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_OOS_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU,
    (const VOS_VOID *) &g_LL2_OM_VOLTE_STAT_INFO_STRU,
    (const VOS_VOID *) &g_LMAC_OM_PRACH_CONFIG_STRU,
    (const VOS_VOID *) &g_LPS_LOW_QUILITY_ABNORMAL_STRU,
    (const VOS_VOID *) &g_LRRC_OM_AIR_SIGNAL_INFO_STRU,
    (const VOS_VOID *) &g_LRRC_OM_LAYER_EVENT_INFO_STRU,
    (const VOS_VOID *) &g_LRRC_OM_MEASRPT_INFO,
    (const VOS_VOID *) &g_LRRC_OM_SCELL_ID,
    (const VOS_VOID *) &g_LRRC_OM_TAC_STRU,
    (const VOS_VOID *) &g_LRRC_OM_VOLTE_SINGLE_CALL_INFO_STRU,
    (const VOS_VOID *) &g_LRRC_OM_VOLTE_SINGLE_FAULT_INFO_STRU,
    (const VOS_VOID *) &g_PCH_CELL_INFO_REPORT_STRU,
    (const VOS_VOID *) &g_TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU,
    (const VOS_VOID *) &g_TRRC_APP_CS_RELEASE_CELL_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_APP_STATE_INFO_STRU,
    (const VOS_VOID *) &g_TRRC_CS_CALL_MM_INFO_STRU,
    (const VOS_VOID *) &g_T_CellDesc_Tag,
};
const VOS_UINT32 g_FaultStructDescCount = sizeof(g_FaultStructDesc) / sizeof(g_FaultStructDesc[0]);
const VOS_VOID * const g_EventStructDesc[] = 
{
    (const VOS_VOID *) &g_LL2_STATISTIC_INFO_COLLECTION,
    (const VOS_VOID *) &g_LPS_VOLTE_STAT_IND,
    (const VOS_VOID *) &g_LRRC_VOLTE_FAULT_AUTOAN_IND,
    (const VOS_VOID *) &g_TRRC_STATISTIC_INFO_COLLECTION,
};
const VOS_UINT32 g_EventStructDescCount = sizeof(g_EventStructDesc) / sizeof(g_EventStructDesc[0]);
