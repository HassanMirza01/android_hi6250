CHR直通事件开发维护记录，记录每个CHR直通事件基本信息。包含事件ID、事件类型、属于组件、合入版本（ProductName/LogVersion）、上报频次（单位：分钟（小时）/次）、事件简要描述等信息。
请每次新增和修改时更新！！！

序号  子事件ID名称                                                  子事件ID号  事件ID名                                               事件ID号  事件类型  属于组件     新增/修改  上报频次  合入版本信息     事件描述
1     TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_ALARMID                 24001      TRRC_STATISTIC_INFO_COLLECTION_EVENTID                 1         非关联    TRRC         新增       30分钟    COMMON#101/001   UE在某一小区反复失步、小区更新失败超过两次的小区信息统计
2     TRRC_OOS_INFO_STRU_ALARMID                                     24002      TDS_OOS_INFO_REPORT_FAULTID                            64        关联      TRRC、TMAC   新增       30分钟    COMMON#101/001   UE在某一小区一定时间段内出现失步的次数大于限定阈值的小区信息统计
3     TLL2_OOS_INFO_STRU_ALARMID                                     25001      TDS_OOS_INFO_REPORT_FAULTID                            64        关联      TRRC、TMAC   新增       30分钟    COMMON#101/001   UE在某一小区一定时间段内出现失步的次数大于限定阈值的小区信息统计
4     LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_ALARMID              25002      LL2_STATISTIC_INFO_COLLECTION_EVENTID                  77        非关联    LL2          新增       8小时     COMMON#101/002   Preamble不匹配信息统计
5     TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_ALARMID                  25003      TRRC_STATISTIC_INFO_COLLECTION_EVENTID                 1         非关联    TRRC         新增       6小时     COMMON#101/003   TDS收集外场频点信息













































