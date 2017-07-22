/**
    @copyright: Huawei Technologies Co., Ltd. 2016-xxxx. All rights reserved.

    @file: bfr_core.c

    @brief: define the core's external public enum/macros/interface for BFR (Boot Fail Recovery)

    @version: 2.0

    @author: QiDechun ID: 216641

    @date: 2016-08-17

    @history:
*/

/*----includes-----------------------------------------------------------------------*/

#include <linux/kernel.h>
#include <linux/init.h>
#include <chipset_common/bfmr/common/bfmr_common.h>
#include <chipset_common/bfmr/bfr/chipsets/bfr_chipsets.h>
#include <chipset_common/bfmr/bfr/core/bfr_core.h>


/*----local macroes------------------------------------------------------------------*/

#define BFR_RECORD_COPIES_MAX_COUNT (2)
#define BFR_RRECORD_PART_MAX_COUNT (2)
#define BFR_RECOVERY_RECORD_READ_MAX_COUNT (5)


/*----local prototypes----------------------------------------------------------------*/

typedef struct bfr_misc_message
{
    char command[32];
    char status[32];
    char recovery[1024];
} bfr_misc_message_t;

typedef struct bfr_recovery_method_select_param
{
    unsigned int cur_boot_fail_stage;
    unsigned int cur_boot_fail_no;
    bfr_suggested_recovery_method_e suggested_recovery_method;
    int latest_valid_recovery_record_count;
    bfr_recovery_record_t latest_recovery_record[BFR_RECOVERY_RECORD_READ_MAX_COUNT];
} bfr_recovery_method_select_param_t;

typedef struct
{
    bfr_recovery_method_e recovery_method;
    char *desc;
} bfr_recovery_method_desc_t;


/*----local variables-----------------------------------------------------------------*/

static bfr_enter_erecovery_reason_map_t s_enter_erecovery_reason_map[] =
{
    {{BL1_ERRNO_START, BL1_PL1_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{BL1_PL1_START, BL1_PL2_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{BL1_PL2_START, BL2_ERRNO_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{BL2_ERRNO_START, BL2_PL1_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{BL2_PL1_START, BL2_PL2_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{BL2_PL2_START, KERNEL_ERRNO_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_BOOTLOADER_BOOT_FAIL},
    {{KERNEL_ERRNO_START, KERNEL_PL1_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_KERNEL_BOOT_FAIL},
    {{KERNEL_PL1_START, KERNEL_PL2_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_KERNEL_BOOT_FAIL},
    {{KERNEL_PL2_START, NATIVE_ERRNO_START - 1}, ENTER_ERECOVERY_REASON_BECAUSE_KERNEL_BOOT_FAIL},
    {{SYSTEM_MOUNT_FAIL, SYSTEM_MOUNT_FAIL}, ENTER_ERECOVERY_BECAUSE_SYSTEM_MOUNT_FAILED},
    {{SECURITY_FAIL, SECURITY_FAIL}, ENTER_ERECOVERY_BECAUSE_SECURITY_FAIL},
    {{CRITICAL_SERVICE_FAIL_TO_START, CRITICAL_SERVICE_FAIL_TO_START}, ENTER_ERECOVERY_BECAUSE_KEY_PROCESS_START_FAILED},
    {{DATA_MOUNT_FAILED_AND_ERASED, DATA_MOUNT_FAILED_AND_ERASED}, ENTER_ERECOVERY_BECAUSE_DATA_MOUNT_FAILED},
    {{DATA_MOUNT_RO, DATA_MOUNT_RO}, ENTER_ERECOVERY_BECAUSE_DATA_MOUNT_RO},
    {{VENDOR_MOUNT_FAIL, VENDOR_MOUNT_FAIL}, ENTER_ERECOVERY_BECAUSE_VENDOR_MOUNT_FAILED},
    {{NATIVE_ERRNO_START, PACKAGE_MANAGER_SETTING_FILE_DAMAGED}, ENTER_ERECOVERY_BECAUSE_APP_BOOT_FAIL},
};

#if defined(CONFIG_USE_AB_SYSTEM)
static bfr_recovery_policy_e s_fixed_recovery_policy[] =
{
    {
        SYSTEM_MOUNT_FAIL, 1,
        {
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY}
        },
    },
};
#else
static bfr_recovery_policy_e s_fixed_recovery_policy[] =
{
    {
        SYSTEM_MOUNT_FAIL, 1,
        {
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY}
        },
    },
    {
        VENDOR_MOUNT_FAIL, 1,
        {
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY}
        },
    },
    {
        CRITICAL_SERVICE_FAIL_TO_START, 1,
        {
            {1, FRM_REBOOT},
            {1, FRM_GOTO_ERECOVERY_FACTORY_RESET},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
        },
    },
    {
        DATA_MOUNT_FAILED_AND_ERASED, 1,
        {
            {1, FRM_REBOOT},
            {1, FRM_GOTO_ERECOVERY_FACTORY_RESET},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
        },
    },
    {
        DATA_MOUNT_RO, 1,
        {
            {1, FRM_REBOOT},
            {1, FRM_GOTO_ERECOVERY_LOWLEVEL_FORMAT_DATA},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
        },
    },
    {
        DATA_NOSPC, 1,
        {
            {1, FRM_GOTO_ERECOVERY_DEL_FILES_FOR_NOSPC},
            {1, FRM_GOTO_ERECOVERY_FACTORY_RESET},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
            {1, FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY},
        },
    },
};
#endif

static bfr_recovery_record_param_t s_rrecord_param[BFR_RECORD_COPIES_MAX_COUNT];
static bfr_recovery_method_desc_t s_recovery_method_desc[] =
{
    {FRM_DO_NOTHING, "do nothing"},
    {FRM_REBOOT, "reboot"},
    {FRM_GOTO_B_SYSTEM, "goto B system"},
    {FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF, "del files in /data part"},
    {FRM_GOTO_ERECOVERY_DEL_FILES_FOR_NOSPC, "del files in /data part because of no space"},
    {FRM_GOTO_ERECOVERY_FACTORY_RESET, "recommend user to do factory reset"},
    {FRM_GOTO_ERECOVERY_FORMAT_DATA_PART, "recommend user to format /data part"},
    {FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY, "download and recovery"},
    {FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_DEL_FILES, "recommend user to del files in /data after download and recovery"},
    {FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET, "recommend user to do factory reset after download and recovery"},
    {FRM_NOTIFY_USER_RECOVERY_FAILURE, "recovery failed, the boot fail fault can't be recoveried by BFRM"},
    {FRM_GOTO_ERECOVERY_LOWLEVEL_FORMAT_DATA, "recommend user to do low-level formatting data"},
};


/*----global variables-----------------------------------------------------------------*/


/*----global function prototypes--------------------------------------------------------*/


/*----local function prototypes---------------------------------------------------------*/

#if defined(CONFIG_USE_AB_SYSTEM)
static int bfr_another_system_is_ok(void);
static void bfr_goto_another_system(void);
#endif
static bool bfr_boot_fail_has_fixed_recovery_method(
    unsigned int boot_fail_no,
    int failed_times_in_application,
    bfr_recovery_method_e *pfixed_recovery_method);
static bfr_recovery_method_running_status_e bfr_init_recovery_method_running_status(
    bfr_recovery_method_e recovery_method);
static bfr_recovery_method_run_result_e bfr_init_recovery_method_run_result(
    bfr_recovery_method_e recovery_method);
static bfr_recovery_method_e bfr_select_recovery_method(
    bfr_recovery_method_select_param_t *pselect_param);
static bfr_boot_fail_stage_e bfr_get_main_boot_fail_stage(unsigned int boot_fai_no);
static int bfr_run_recovery_method(bfr_recovery_method_e recovery_method,
    unsigned int boot_fail_stage,
    unsigned int boot_fail_no);
static int bfr_set_misc_msg_for_erecovery(void);
static int bfr_save_enter_erecovery_reason(bfr_enter_erecovery_reason_param_t *reason_param);
static int bfr_init_local_recovery_record_param(void);
static int bfr_release_local_recovery_record_param(void);
static int bfr_read_recovery_record_to_local_buf(void);
static int bfr_verify_recovery_record(void);
static int bfr_init_recovery_record_header(void);
static int bfr_read_recovery_record(bfr_recovery_record_t *precord,
    int record_count_to_read,
    int *record_count_actually_read);
static int bfr_create_recovery_record(bfr_recovery_record_t *precord);
static int bfr_renew_recovery_record(bfr_recovery_record_t *precord);
static bool bfm_is_bottom_layer_boofail(unsigned int cur_boot_fail_no);


/*----function definitions--------------------------------------------------------------*/

#if defined(CONFIG_USE_AB_SYSTEM)
static int bfr_another_system_is_ok(void)
{
    return 1;
}


static void bfr_goto_another_system(void)
{
    return;
}
#endif


static bool bfr_boot_fail_has_fixed_recovery_method(
    unsigned int boot_fail_no,
    int failed_times_in_application,
    bfr_recovery_method_e *pfixed_recovery_method)
{
    int count = sizeof(s_fixed_recovery_policy) / sizeof(s_fixed_recovery_policy[0]);
    int i = 0;

    if (unlikely(NULL == pfixed_recovery_method))
    {
        BFMR_PRINT_INVALID_PARAMS("pfixed_recovery_method: %p\n", pfixed_recovery_method);
        return false;
    }

    for (i = 0; i < count; i++)
    {
        if (boot_fail_no != s_fixed_recovery_policy[i].boot_fail_no)
        {
            continue;
        }

        if (0 != s_fixed_recovery_policy[i].has_fixed_policy)
        {
            int method_count = sizeof(s_fixed_recovery_policy[i].param)
                / sizeof(s_fixed_recovery_policy[i].param[0]);

            if ((failed_times_in_application <= 0) || (failed_times_in_application > method_count))
            {
                *pfixed_recovery_method = FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY;
                BFMR_PRINT_KEY_INFO("ErrNo: %x failed_times_in_application: %d recovery_method: %d\n",
                    (unsigned int)boot_fail_no, failed_times_in_application, (int)*pfixed_recovery_method);
                return true;
            }

            failed_times_in_application--;
            if (0 != s_fixed_recovery_policy[i].param[failed_times_in_application].enable_this_method)
            {
                *pfixed_recovery_method = s_fixed_recovery_policy[i].param[failed_times_in_application].recovery_method;
            }
            else
            {
                *pfixed_recovery_method = FRM_DO_NOTHING;
            }

            BFMR_PRINT_KEY_INFO("ErrNo: %x recovery_method: %x\n", boot_fail_no, *pfixed_recovery_method);

            return true;
        }
        else
        {
            break;
        }
    }

    return false;
}


static unsigned int bfr_get_enter_erecovery_reason(unsigned int boot_fail_no)
{
    int i = 0;
    int count = sizeof(s_enter_erecovery_reason_map) / sizeof(s_enter_erecovery_reason_map[0]);

    for (i = 0; i < count; i++)
    {
        if ((boot_fail_no >= s_enter_erecovery_reason_map[i].range.start)
            && boot_fail_no <= s_enter_erecovery_reason_map[i].range.end)
        {
            return s_enter_erecovery_reason_map[i].enter_erecovery_reason;
        }
    }

    return ENTER_ERECOVERY_UNKNOWN;
}


static int bfr_save_enter_erecovery_reason(bfr_enter_erecovery_reason_param_t *reason_param)
{
    int ret = -1;
    char *dev_path = NULL;

    if (NULL == reason_param)
    {
        BFMR_PRINT_INVALID_PARAMS("reason_param:%p!\n", reason_param);
        return -1;
    }

    ret = bfr_get_full_path_of_rrecord_part(&dev_path);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
        goto __out;
    }

    ret = bfmr_write_emmc_raw_part(dev_path, BFR_ENTER_ERECOVERY_REASON_OFFSET,
        (char *)reason_param, (unsigned long long)sizeof(bfr_enter_erecovery_reason_param_t));
    if (0 != ret)
    {
        BFMR_PRINT_ERR("write enter erecovery reason to [%s] failed!\n", dev_path);
        goto __out;
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


static int bfr_set_misc_msg_for_erecovery(void)
{
    int ret = -1;
    bfr_misc_message_t *pmsg = NULL;
    char *dev_path = NULL;

    dev_path = (char *)bfmr_malloc(BFMR_DEV_FULL_PATH_MAX_LEN + 1);
    if (NULL == dev_path)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        goto __out;
    }
    memset((void *)dev_path, 0, BFMR_DEV_FULL_PATH_MAX_LEN + 1);

    pmsg = (bfr_misc_message_t *)bfmr_malloc(sizeof(bfr_misc_message_t));
    if (NULL == pmsg)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        goto __out;
    }
    memset((void *)pmsg, 0, sizeof(bfr_misc_message_t));

    ret = bfmr_get_device_full_path(BFR_MISC_PART_NAME, dev_path, BFMR_DEV_FULL_PATH_MAX_LEN);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("get full path of [%s] failed!\n", BFR_MISC_PART_NAME);
        goto __out;
    }

    memcpy(pmsg->command, (void *)BFR_ENTER_ERECOVERY_CMD, strlen(BFR_ENTER_ERECOVERY_CMD));
    ret = bfmr_write_emmc_raw_part(dev_path, 0x0, (char *)pmsg, sizeof(bfr_misc_message_t));
    if (0 != ret)
    {
        BFMR_PRINT_ERR("write enter erecovery misc cmd failed!\n");
        goto __out;
    }

__out:
    if (NULL != pmsg)
    {
        bfmr_free(pmsg);
    }

    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


static bool bfm_is_bottom_layer_boofail(unsigned int cur_boot_fail_no)
{
    switch (bfmr_get_boot_stage_from_bootfail_errno(cur_boot_fail_no))
    {
    case PBL_STAGE:
    case BL1_STAGE:
    case BL2_STAGE:
    case KERNEL_STAGE:
        {
            BFMR_PRINT_KEY_INFO("cur_boot_fail_no: 0x%08x, bootstage in bootfail errno: %d\n",
                (unsigned int)cur_boot_fail_no, (int)bfmr_get_boot_stage_from_bootfail_errno(cur_boot_fail_no));
            return true;
        }
    default:
        {
            break;
        }
    }

    return false;
}


static bfr_recovery_method_e bfr_select_recovery_method(
    bfr_recovery_method_select_param_t *pselect_param)
{
    int i = 0;
    int recovery_failed_times_total = 0;
    int recovery_failed_times_in_bottom_layer = 0;
    int recovery_failed_times_in_application = 0;
    bfr_recovery_method_e fixed_recovery_method = FRM_DO_NOTHING;
    bool has_fixed_recovery_method = false;

    BFMR_PRINT_ENTER();

    if (NULL == pselect_param)
    {
        BFMR_PRINT_INVALID_PARAMS("pselect_param: %p\n", pselect_param);
        return FRM_DO_NOTHING;
    }

    /* record count is >= 3 */
    for (i= 0; i < pselect_param->latest_valid_recovery_record_count; i++)
    {
        if (BOOT_FAIL_RECOVERY_SUCCESS == pselect_param->latest_recovery_record[i].recovery_result)
        {
            recovery_failed_times_total = 0;
            recovery_failed_times_in_bottom_layer = 0;
        }
        else
        {
            recovery_failed_times_total++;
            if (bfm_is_bottom_layer_boofail(pselect_param->latest_recovery_record[i].boot_fail_no))
            {
                recovery_failed_times_in_bottom_layer++;
            }
        }
    }

    recovery_failed_times_total++;
    if (bfm_is_bottom_layer_boofail(pselect_param->cur_boot_fail_no))
    {
        recovery_failed_times_in_bottom_layer++;
    }

    recovery_failed_times_in_application = recovery_failed_times_total - recovery_failed_times_in_bottom_layer;
    BFMR_PRINT_KEY_INFO("bf_total_times:%d bf_bottom_layer_times: %d bf_app_times: %d\n",
        recovery_failed_times_total, recovery_failed_times_in_bottom_layer,
        recovery_failed_times_in_application);

    /* It is the first failure */
    has_fixed_recovery_method = bfr_boot_fail_has_fixed_recovery_method(
        pselect_param->cur_boot_fail_no, recovery_failed_times_in_application, &fixed_recovery_method);
    if (0 == pselect_param->latest_valid_recovery_record_count)
    {
        BFMR_PRINT_KEY_INFO("System has no valid recovery record, the boot fail occurs in [%s]\n",
            (pselect_param->cur_boot_fail_stage < NATIVE_STAGE_START) ? ("Bottom layer") : ("APP"));
        if (has_fixed_recovery_method)
        {
            return fixed_recovery_method;
        }

        return FRM_REBOOT;
    }

    switch (recovery_failed_times_in_bottom_layer)
    {
    case 0:
        {
            if (has_fixed_recovery_method)
            {
                BFMR_PRINT_KEY_INFO("[Bottom layer has no boot fail] APP has fixed recovery method: [%d]\n",
                    fixed_recovery_method);
                return fixed_recovery_method;
            }

            switch (recovery_failed_times_in_application)
            {
            case 1:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has no boot fail] FRM_REBOOT\n");
                    return FRM_REBOOT;
                }
            case 2:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has no boot fail] FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF\n");
                    return FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF;
                }
            case 3:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has no boot fail] FRM_GOTO_ERECOVERY_FACTORY_RESET\n");
                    return FRM_GOTO_ERECOVERY_FACTORY_RESET;
                }
            case 4:
            default:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has no boot fail] FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY\n");
                    return FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY;
                }
            }
            break;
        }
    case 1:
    case 2:
        {
            if (has_fixed_recovery_method)
            {
                BFMR_PRINT_KEY_INFO("[Bottom layer has 1 or 2 boot fail] APP has fixed recovery method\n");
                return fixed_recovery_method;
            }

            switch (recovery_failed_times_in_application)
            {
            case 0:
                {
                    BFMR_PRINT_KEY_INFO("[APP has no Bootfail] FRM_REBOOT\n");
                    return FRM_REBOOT;
                }
            case 1:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has boot fail] FRM_REBOOT\n");
                    return FRM_REBOOT;
                }
            case 2:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has boot fail] FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF\n");
                    return FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF;
                }
            case 3:
            default:
                {
                    BFMR_PRINT_KEY_INFO("[Bottom layer has boot fail] FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET\n");
                    return FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET;
                }
            }
            break;
        }
    case 3:
    default:
        {
            BFMR_PRINT_KEY_INFO("[APP has no boot fail] FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY\n");
            return FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY;
        }
    }

    BFMR_PRINT_EXIT();

    return FRM_REBOOT;
}


static bfr_boot_fail_stage_e bfr_get_main_boot_fail_stage(unsigned int boot_fai_no)
{
    if (bfmr_is_bl1_errno(boot_fai_no) || bfmr_is_bl2_errno(boot_fai_no))
    {
        return BFS_BOOTLOADER;
    }
    else if (bfmr_is_kernel_errno(boot_fai_no))
    {
        return BFS_KERNEL;
    }
    else
    {
        return BFS_APP;
    }
}


static int bfr_run_recovery_method(bfr_recovery_method_e recovery_method,
    unsigned int boot_fail_stage,
    unsigned int boot_fail_no)
{
    switch (recovery_method)
    {
#if defined(CONFIG_USE_AB_SYSTEM)
    case FRM_GOTO_B_SYSTEM:
        {
            bfr_goto_another_system();
            break;
        }
#endif
    case FRM_GOTO_ERECOVERY_DEL_FILES_FOR_BF:
    case FRM_GOTO_ERECOVERY_DEL_FILES_FOR_NOSPC:
    case FRM_GOTO_ERECOVERY_FACTORY_RESET:
    case FRM_GOTO_ERECOVERY_FORMAT_DATA_PART:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_DEL_FILES:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY:
    case FRM_GOTO_ERECOVERY_LOWLEVEL_FORMAT_DATA:
        {
            bfr_enter_erecovery_reason_param_t reason_param;

            memset((void *)&reason_param, 0, sizeof(reason_param));
            memcpy((void *)reason_param.command, (void *)BFR_ENTER_ERECOVERY_CMD,
                strlen(BFR_ENTER_ERECOVERY_CMD));/*[false alarm]:strlen*/
            reason_param.enter_erecovery_reason = EER_BOOT_FAIL_SOLUTION;
            reason_param.enter_erecovery_reason_number = bfr_get_enter_erecovery_reason(boot_fail_no);
            reason_param.boot_fail_stage_for_erecovery = bfr_get_main_boot_fail_stage(boot_fail_no);
            reason_param.recovery_method = (unsigned int)recovery_method;
            reason_param.boot_fail_no = (unsigned int)boot_fail_no;
            (void)bfr_save_enter_erecovery_reason(&reason_param);
            (void)bfr_set_misc_msg_for_erecovery();
            break;
        }
    case FRM_NOTIFY_USER_RECOVERY_FAILURE:
        {
            break;
        }
    default:
        {
            return 0;
        }
    }

    return 0;
}


static bfr_recovery_method_running_status_e bfr_init_recovery_method_running_status(
    bfr_recovery_method_e recovery_method)
{
    switch (recovery_method)
    {
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_DEL_FILES:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET:
        {
            return RMRSC_ERECOVERY_BOOT_FAILED;
        }
    default:
        {
            break;
        }
    }

    return RMRSC_EXEC_COMPLETED;
}


static bfr_recovery_method_run_result_e bfr_init_recovery_method_run_result(
    bfr_recovery_method_e recovery_method)
{
    switch (recovery_method)
    {
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_DEL_FILES:
    case FRM_GOTO_ERECOVERY_DOWNLOAD_RECOVERY_AND_FACTORY_RESET:
        {
            return RMRR_FAILED;
        }
    default:
        {
            break;
        }
    }

    return RMRR_SUCCESS;
}


static int bfr_init_local_recovery_record_param(void)
{
    int i = 0;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);

    memset((void *)&s_rrecord_param, 0, sizeof(s_rrecord_param));
    for (i = 0; i < count; i++)
    {
        s_rrecord_param[i].buf = (unsigned char *)bfmr_malloc(BFR_EACH_RECORD_PART_SIZE);
        if (NULL == s_rrecord_param[i].buf)
        {
            BFMR_PRINT_ERR("bfmr_malloc failed!\n");
            return -1;
        }
        memset((void *)s_rrecord_param[i].buf, 0, BFR_EACH_RECORD_PART_SIZE);
        s_rrecord_param[i].buf_size = BFR_EACH_RECORD_PART_SIZE;
        s_rrecord_param[i].part_offset = (0 == i)
            ? (BFR_RRECORD_FIRST_PART_OFFSET) : ((1 == i)
            ? (BFR_RRECORD_SECOND_PART_OFFSET) : (BFR_RRECORD_THIRD_PART_OFFSET));
    }

    return 0;
}


static int bfr_release_local_recovery_record_param(void)
{
    int i = 0;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);

    for (i = 0; i < count; i++)
    {
        bfmr_free(s_rrecord_param[i].buf);
        s_rrecord_param[i].buf = NULL;        
    }

    return 0;
}


static int bfr_read_recovery_record_to_local_buf(void)
{
    int i = 0;
    int ret = -1;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);
    char *dev_path = NULL;

    ret = bfr_get_full_path_of_rrecord_part(&dev_path);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
        goto __out;
    }

    for (i = 0; i < count; i++)
    {
        ret = bfmr_read_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset,
            s_rrecord_param[i].buf, s_rrecord_param[i].buf_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("read [%s] failed!\n", dev_path);
            break;
        }
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


static int bfr_verify_recovery_record(void)
{
    bfr_recovery_record_header_t *pfirst_header = NULL;
    bfr_recovery_record_header_t *psecond_header = NULL;
    int ret = -1;
    int i = 0;
    int valid_record_idx = -1;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);
    int record_damaged = 0;
    char *dev_path = NULL;

    /* 1. check the magic number */
    pfirst_header = (bfr_recovery_record_header_t *)s_rrecord_param[0].buf;
    psecond_header = (bfr_recovery_record_header_t *)s_rrecord_param[1].buf;
    if ((BFR_RRECORD_MAGIC_NUMBER != pfirst_header->magic_number)
        && (BFR_RRECORD_MAGIC_NUMBER != psecond_header->magic_number))
    {
        /* maybe it is the first time teh rrecord part hae been used */
        return bfr_init_recovery_record_header();
    }

    /* 2. check the crc32 value */
    for (i = 0; i < count; i++)
    {
        unsigned int local_crc32 = 0x0;
        bfr_recovery_record_header_t *pheader = (bfr_recovery_record_header_t *)s_rrecord_param[i].buf;

        local_crc32 = bfmr_get_crc32(s_rrecord_param[i].buf + (unsigned int)sizeof(pheader->crc32),
            s_rrecord_param[i].buf_size - (unsigned int)sizeof(pheader->crc32));
        if (local_crc32 != pheader->crc32)
        {
            BFMR_PRINT_ERR("CRC check failed! orig_crc32:0x%08x local_crc32: 0x%08x\n",
                pheader->crc32, local_crc32);
            s_rrecord_param[i].record_damaged = 1;
            record_damaged++;
        }
        else
        {
            s_rrecord_param[i].record_damaged = 0;
            valid_record_idx = i;
        }
    }

    /* 3. no valid record has been found, init the record header and return here */
    if (valid_record_idx < 0)
    {
        BFMR_PRINT_ERR("There is no valid recovery record!\n");
        return bfr_init_recovery_record_header();
    }

    /* 4. malloc memory for the full path buffer of rrecord */
    if (0 != record_damaged)
    {
        ret = bfr_get_full_path_of_rrecord_part(&dev_path);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
            goto __out;
        }
    }

    /* 5. correct the recovery record */
    ret = 0; /* set the value of ret as 0 here because the maybe all the parts are valid */
    for (i = 0; i < count; i++)
    {
        if (0 == s_rrecord_param[i].record_damaged)
        {
            continue;
        }

        memcpy((void *)s_rrecord_param[i].buf, (void *)s_rrecord_param[valid_record_idx].buf,
            s_rrecord_param[valid_record_idx].buf_size);
        ret = bfmr_write_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset,
            s_rrecord_param[i].buf, s_rrecord_param[i].buf_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("write data to [%s] failed!\n", dev_path);
            break;
        }
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


static int bfr_init_recovery_record_header(void)
{
    bfr_recovery_record_header_t *pheader = NULL;
    unsigned int header_size = (unsigned int)sizeof(bfr_recovery_record_header_t);
    int i = 0;
    int ret = -1;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);
    char *dev_path = NULL;

    ret = bfr_get_full_path_of_rrecord_part(&dev_path);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
        goto __out;
    }

    for (i = 0; i < count; i++)
    {
        pheader = (bfr_recovery_record_header_t *)s_rrecord_param[i].buf;
        memset((void *)pheader, 0, header_size);
        pheader->magic_number = BFR_RRECORD_MAGIC_NUMBER;
        pheader->record_count = (s_rrecord_param[i].buf_size - header_size)
            / sizeof(bfr_recovery_record_t);
        pheader->crc32 = bfmr_get_crc32(s_rrecord_param[i].buf + (unsigned int)sizeof(pheader->crc32),
            s_rrecord_param[i].buf_size - (unsigned int)sizeof(pheader->crc32));
        ret = bfmr_write_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset,
            (char *)s_rrecord_param[i].buf, s_rrecord_param[i].buf_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("Write part [%s] failed [ret = %d]!\n", dev_path, ret);
            break;
        }
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


static int bfr_read_recovery_record(bfr_recovery_record_t *precord,
    int record_count_to_read,
    int *record_count_actually_read)
{
    int ret = -1;
    unsigned int buf_size = 0;
    unsigned int header_size = (unsigned int)sizeof(bfr_recovery_record_header_t);
    unsigned int record_size = (unsigned int)sizeof(bfr_recovery_record_t);
    bfr_recovery_record_header_t *precord_header = NULL;

    if (unlikely((NULL == precord) || (NULL == record_count_actually_read)))
    {
        BFMR_PRINT_INVALID_PARAMS("precord: %p record_count_actually_read: %p\n",
            precord, record_count_actually_read);
        return -1;
    }

    /* 1. read recovery record to local buf */
    ret = bfr_read_recovery_record_to_local_buf();
    if (0 != ret)
    {
        BFMR_PRINT_ERR("bfr_read_recovery_record_to_local_buf failed!\n");
        return -1;
    }

    /* 2. init the record_count_actually_read as 0 */
    *record_count_actually_read = 0;

    /* 3. verify the recovery record */
    ret = bfr_verify_recovery_record();
    if (0 != ret)
    {
        BFMR_PRINT_ERR("bfr_verify_recovery_record failed!\n");
        return -1;
    }

    /* 4. read recovery record */
    precord_header = (bfr_recovery_record_header_t *)s_rrecord_param[0].buf;
    *record_count_actually_read = (precord_header->boot_fail_count <= record_count_to_read)
        ? (precord_header->boot_fail_count) : (record_count_to_read);
    buf_size = (*record_count_actually_read) * sizeof(bfr_recovery_record_t);
    if (precord_header->next_record_idx >= *record_count_actually_read)
    {
        memcpy((void *)precord, (void *)(s_rrecord_param[0].buf
            + header_size + (precord_header->next_record_idx
            - *record_count_actually_read) * record_size), buf_size);
    }
    else
    {
        if (precord_header->boot_fail_count > precord_header->record_count)
        {
            unsigned int count_in_the_end = *record_count_actually_read - precord_header->next_record_idx;
            unsigned int count_in_the_begin = precord_header->next_record_idx;

            memcpy((void *)precord, (void *)(s_rrecord_param[0].buf + header_size
                + (precord_header->record_count - count_in_the_end)* record_size), count_in_the_end * record_size);
            memcpy((void *)((char *)precord + count_in_the_end * record_size),
                (void *)(s_rrecord_param[0].buf + header_size), count_in_the_begin * record_size);
        }
        else
        {
            memcpy((void *)precord, (void *)(s_rrecord_param[0].buf
                + header_size + (precord_header->next_record_idx
                - *record_count_actually_read) * record_size), buf_size);
        }
    }

    return 0;
}


static int bfr_create_recovery_record(bfr_recovery_record_t *precord)
{
    int i = 0;
    int ret = -1;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);
    bfr_recovery_record_header_t *pheader = NULL;
    unsigned int header_size = (unsigned int)sizeof(bfr_recovery_record_header_t);
    unsigned int record_size = (unsigned int)sizeof(bfr_recovery_record_t);
    char *dev_path = NULL;

    if (0 != bfr_get_full_path_of_rrecord_part(&dev_path))
    {
        BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
        goto __out;
    }

    for (i = 0; i < count; i++)
    {
        pheader = (bfr_recovery_record_header_t *)s_rrecord_param[i].buf;
        memcpy((void *)(s_rrecord_param[i].buf + header_size
            + pheader->next_record_idx * record_size), (void *)precord, record_size);
        pheader->boot_fail_count++;
        pheader->next_record_idx++;
        if (pheader->next_record_idx >= pheader->record_count)
        {
            pheader->next_record_idx = 0;
            pheader->last_record_idx = pheader->record_count - 1;
        }
        else
        {
            pheader->last_record_idx = pheader->next_record_idx - 1;
        }
        pheader->crc32 = bfmr_get_crc32(s_rrecord_param[i].buf + (unsigned int)sizeof(pheader->crc32),
            s_rrecord_param[i].buf_size - (unsigned int)sizeof(pheader->crc32));

        /* 1. write herder */
        ret = bfmr_write_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset, (char *)pheader, header_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("Write recovery record header to [%s] failed!\n", dev_path);
            goto __out;
        }

        /* 2. write record */
        ret = bfmr_write_emmc_raw_part(dev_path, (s_rrecord_param[i].part_offset
            + header_size + (pheader->boot_fail_count - 1) * record_size), (char *)precord, record_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("Write recovery record to [%s] failed!\n", dev_path);
            goto __out;
        }
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


/* this function need not be realized in bootloader, it should be realized in kernel and erecovery */
static int bfr_renew_recovery_record(bfr_recovery_record_t *precord)
{
    int i = 0;
    int ret = -1;
    int count = sizeof(s_rrecord_param) / sizeof(s_rrecord_param[0]);
    int valid_record_idx = -1;
    bfr_recovery_record_t recovery_record;
    unsigned int header_size = (unsigned int)sizeof(bfr_recovery_record_header_t);
    unsigned int record_size = (unsigned int)sizeof(bfr_recovery_record_t);
    unsigned int local_crc32 = 0x0;
    bool system_boot_fail_last_time = false;
    char *dev_path = NULL;

    if (NULL == precord)
    {
        BFMR_PRINT_INVALID_PARAMS("precord: %p\n", precord);
        return -1;
    }

    /* 1. get the full path of the valid rrecord part */
    if (0 != bfr_get_full_path_of_rrecord_part(&dev_path))
    {
        BFMR_PRINT_ERR("find the full path of rrecord part failed!\n");
        goto __out;
    }

    /* 2. read  recovery record*/
    for (i = 0; i < count; i++)
    {
        ret = bfmr_read_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset,
            (char *)s_rrecord_param[i].buf, s_rrecord_param[i].buf_size);
        if (0 != ret)
        {
            BFMR_PRINT_ERR("Read [%s] failed![%d]\n", dev_path, ret);
            goto __out;
        }
    }

    /* 3. verify recovery record */
    for (i = 0; i < count; i++)
    {
        bfr_recovery_record_header_t *pheader = (bfr_recovery_record_header_t *)s_rrecord_param[i].buf;

        local_crc32 = bfmr_get_crc32(s_rrecord_param[i].buf + (unsigned int)sizeof(pheader->crc32),
            s_rrecord_param[i].buf_size - (unsigned int)sizeof(pheader->crc32));
        if (local_crc32 != pheader->crc32)
        {
            BFMR_PRINT_ERR("CRC check failed! orig_crc32:0x%08x local_crc32: 0x%08x\n", pheader->crc32, local_crc32);
            s_rrecord_param[i].record_damaged = true;
        }
        else
        {
            s_rrecord_param[i].record_damaged = false;
            valid_record_idx = i;
        }
    }

    /* 4. correct the recovery record */
    if (valid_record_idx < 0)
    {
        BFMR_PRINT_ERR("There is no valid recovery record!\n");
        goto __out;
    }

    for (i = 0; i < count; i++)
    {
        if (s_rrecord_param[i].record_damaged)
        {
            memcpy((void *)s_rrecord_param[i].buf, (void *)s_rrecord_param[valid_record_idx].buf,
                s_rrecord_param[valid_record_idx].buf_size);
        }
    }

    /* 5. update recovery record*/
    for (i = 0; i < count; i++)
    {
        bfr_recovery_record_header_t *pheader = (bfr_recovery_record_header_t *)s_rrecord_param[i].buf;

        memset((void *)&recovery_record, 0, record_size);
        memcpy((void *)&recovery_record, (void *)(s_rrecord_param[i].buf + header_size
            + pheader->last_record_idx * record_size), record_size);
        if (BOOT_FAIL_RECOVERY_SUCCESS != recovery_record.recovery_result)
        {
            system_boot_fail_last_time = true;
        }
        recovery_record.recovery_result = precord->recovery_result;
        memcpy((void *)(s_rrecord_param[i].buf + header_size + pheader->last_record_idx * record_size),
            (void *)&recovery_record, record_size);
        pheader->crc32 = bfmr_get_crc32(s_rrecord_param[i].buf + (unsigned int)sizeof(pheader->crc32),
            s_rrecord_param[i].buf_size - (unsigned int)sizeof(pheader->crc32));
    }

    /* 6. save recovery record */
    ret = 0;
    for (i = 0; i < count; i++)
    {
        if (system_boot_fail_last_time || (0 != s_rrecord_param[i].record_damaged))
        {
            ret = bfmr_write_emmc_raw_part(dev_path, s_rrecord_param[i].part_offset,
                (char *)s_rrecord_param[i].buf, s_rrecord_param[i].buf_size);
            if (0 != ret)
            {
                BFMR_PRINT_ERR("Write [%s] failed![errno: %d]\n", dev_path, ret);
                goto __out;
            }
        }
    }

__out:
    if (NULL != dev_path)
    {
        bfmr_free(dev_path);
    }

    return ret;
}


char* bfr_get_recovery_method_desc(int recovery_method)
{
    int i = 0;
    int count = sizeof(s_recovery_method_desc) / sizeof(s_recovery_method_desc[0]);

    for (i = 0; i < count; i++)
    {
        if ((bfr_recovery_method_e)recovery_method == s_recovery_method_desc[i].recovery_method)
        {
            return s_recovery_method_desc[i].desc;
        }
    }

    return "unknown";
}


/**
    @function: void boot_status_notify(int boot_success)
    @brief: when the system bootup successfully, the BFM must call this
        function to notify the BFR, and the BFM was notified by the BFD.

    @param: boot_success.

    @return: none.

    @note: this fuction only need be initialized in kernel.
*/
void boot_status_notify(int boot_success)
{
    bfr_recovery_record_t recovery_record;

    BFMR_PRINT_KEY_INFO("Recovery boot fail Successfully!\n");
    memset((void *)&recovery_record, 0, sizeof(recovery_record));
    recovery_record.recovery_result = (0 == boot_success) ? (BOOT_FAIL_RECOVERY_FAILURE)
        : (BOOT_FAIL_RECOVERY_SUCCESS);
    (void)bfr_renew_recovery_record(&recovery_record);
}


/**
    @function: bfr_recovery_method_e try_to_recovery(
        unsigned long long boot_fail_detected_time,
        bfmr_bootfail_errno_e boot_fail_no,
        bfmr_detail_boot_stage_e boot_fail_stage,
        bfr_suggested_recovery_method_e suggested_recovery_method,
        char *args)
    @brief: do recovery for the boot fail.

    @param: boot_fail_detected_time [in], rtc time when boot fail was detected.
    @param: boot_fail_no [in], boot fail errno.
    @param: boot_fail_stage [in], the stage when boot fail happened.
    @param: suggested_recovery_method [in], suggested recovery method transfered by the BFD(Boot Fail Detection).
    @param: args [in], extra parametrs for recovery.

    @return: the recovery method selected by the BFR.

    @note:
*/
bfr_recovery_method_e try_to_recovery(
    unsigned long long boot_fail_detected_time,
    bfmr_bootfail_errno_e boot_fail_no,
    bfmr_detail_boot_stage_e boot_fail_stage,
    bfr_suggested_recovery_method_e suggested_recovery_method,
    char *args)
{
    int ret = -1;
    int record_count_actually_read = -1;
    bfr_recovery_method_e recovery_method = FRM_DO_NOTHING;
    bfr_recovery_method_select_param_t pselect_param;
    bfr_recovery_record_t recovery_record[BFR_RECOVERY_RECORD_READ_MAX_COUNT];
    bfr_recovery_record_t cur_recovery_record;

    BFMR_PRINT_KEY_INFO("boot_fail_stage:%x NATIVE_STAGE_START: %x boot_fail_no: %x "
        "suggested_recovery_method: %d\n", boot_fail_stage, NATIVE_STAGE_START,
        boot_fail_no, suggested_recovery_method);

    if (DO_NOTHING == suggested_recovery_method)
    {
        return FRM_DO_NOTHING;
    }

    /* 1. read recovery record */
    BFMR_PRINT_KEY_INFO("File: %s Line: %d bfr_read_recovery_record\n", __FILE__, __LINE__);
    memset(recovery_record, 0, sizeof(recovery_record));
    ret = bfr_read_recovery_record(recovery_record, BFR_RECOVERY_RECORD_READ_MAX_COUNT,
        &record_count_actually_read);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("bfr_read_recovery_record failed!\n");
        return FRM_DO_NOTHING;
    }

    /* 2. select recovery method */
    BFMR_PRINT_KEY_INFO("File: %s Line: %d bfr_select_recovery_method\n", __FILE__, __LINE__);
    memset((void *)&pselect_param, 0, sizeof(pselect_param));
    pselect_param.cur_boot_fail_stage = boot_fail_stage;
    pselect_param.cur_boot_fail_no = boot_fail_no;
    pselect_param.suggested_recovery_method = suggested_recovery_method;
    pselect_param.latest_valid_recovery_record_count = record_count_actually_read;
    memcpy(&pselect_param.latest_recovery_record, recovery_record, sizeof(recovery_record));
    recovery_method = bfr_select_recovery_method(&pselect_param);

    /* 3.save recovery record */
    BFMR_PRINT_KEY_INFO("File: %s Line: %d bfr_create_recovery_record\n", __FILE__, __LINE__);
    memset((void *)&cur_recovery_record, 0, sizeof(cur_recovery_record));
    cur_recovery_record.boot_fail_detected_time = boot_fail_detected_time;
    cur_recovery_record.boot_fail_stage = boot_fail_stage;
    cur_recovery_record.boot_fail_no = boot_fail_no;
    cur_recovery_record.recovery_method = recovery_method;
    cur_recovery_record.running_status_code = bfr_init_recovery_method_running_status(recovery_method);
    cur_recovery_record.method_run_result = bfr_init_recovery_method_run_result(recovery_method);
    cur_recovery_record.recovery_result = BOOT_FAIL_RECOVERY_FAILURE;
    ret = bfr_create_recovery_record(&cur_recovery_record);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("bfr_create_recovery_record failed!\n");
        return FRM_DO_NOTHING;
    }

    /* 4. run recovery method. Note: reboot is executed by the caller now */
    BFMR_PRINT_KEY_INFO("File: %s Line: %d bfr_run_recovery_method\n", __FILE__, __LINE__);
    ret = bfr_run_recovery_method(recovery_method, boot_fail_stage, boot_fail_no);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("Failed to run recovery method!\n");
    }

    /* 5. return recovery method to the caller */
    return recovery_method;
}


/**
    @function: int bfr_init(void)
    @brief: init BFR.

    @param: none.

    @return: none.

    @note:
*/
int __init bfr_init(void)
{
    int ret = -1;

    ret = bfr_init_local_recovery_record_param();
    if (0 != ret)
    {
        BFMR_PRINT_ERR("Failed to init local recovery record param!\n");
        goto __err_exit;
    }

    /* success here return 0 */
    return 0;

__err_exit:
    (void)bfr_release_local_recovery_record_param();

    return ret;
}

