/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <linux/module.h>
#include <linux/io.h>
#include <osl_common.h>
#include <osl_thread.h>
#include <osl_sem.h>
#include <drv_comm.h>
#include "icc_core.h"
#include <bsp_sec_call.h>
#ifdef CONFIG_TZDRIVER
#include <teek_client_api.h>
#include <teek_client_id.h>

struct ca_icc_ctrl
{
    TEEC_UUID svc_uuid;
    u8   svc_name[32];
    u32  session_cmd_id;
    u32  task_priority;
};

OSL_TASK_ID  ca_icc_task_id;
#if 0
/******************************************************************************
Function:       TEEK_ca_icc_init
Description:    TEEK初始化
Input:          session
                context
                svc_uuid
                svc_name
Output:         none
Return:         0: OK  其他: ERROR码
******************************************************************************/
static int TEEK_ca_icc_init(TEEC_Session *session, TEEC_Context *context, TEEC_UUID *svc_uuid, const char *svc_name)
{
    TEEC_Result result;
    TEEC_Operation operation = {0};
    u32 root_id = 0;

    result = TEEK_InitializeContext(NULL, context);

    if(result != TEEC_SUCCESS) {
        icc_print_error("TEEK_InitializeContext failed,result = 0x%x!\n",result);
        return BSP_ERROR;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes = TEEC_PARAM_TYPES(
            TEEC_NONE,
            TEEC_NONE,
            TEEC_MEMREF_TEMP_INPUT,
            TEEC_MEMREF_TEMP_INPUT);
    operation.params[2].tmpref.buffer = (void *)(&root_id);
    operation.params[2].tmpref.size = sizeof(root_id);
    operation.params[3].tmpref.buffer = (void *)svc_name;
    operation.params[3].tmpref.size = strlen(svc_name) + 1;
    result = TEEK_OpenSession(
                context,
                session,
                svc_uuid,
                TEEC_LOGIN_IDENTIFY,
                NULL,
                &operation,
                NULL);

    if (result != TEEC_SUCCESS)
    {
        icc_print_error("TEEK_OpenSession failed,result = 0x%x!\n",result);
        TEEK_FinalizeContext(context);
        return BSP_ERROR;
    }

    return BSP_OK;
}

/******************************************************************************
Function:        TEEK_ca_icc_session
Description:     通过session传入命令字或值
Input:
        cmd_id      - 传送给安全OS的cmd_id
Output:          none
Return:          0: OK  其他: ERROR码
******************************************************************************/
static int TEEK_ca_icc_session(TEEC_Session *session, u32 cmd_id)
{
    TEEC_Result result;
    TEEC_Operation operation;
    unsigned int   origin;

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes = TEEC_PARAM_TYPES(
                           TEEC_NONE,
                           TEEC_NONE,
                           TEEC_NONE,
                           TEEC_NONE);

    result = TEEK_InvokeCommand(
                           session,
                           cmd_id,
                           &operation,
                           &origin);
    if (result != TEEC_SUCCESS) {
        icc_print_error("invoke failed!result = 0x%x!\n",result);
        result = BSP_ERROR;
    }

    return result;
}

int ca_icc_task_func(void* data)
{
    TEEC_Session session;
    TEEC_Context context;
    struct ca_icc_ctrl *ca_icc_control = (struct ca_icc_ctrl *)data;
    int ret = BSP_ERROR;

    ret = TEEK_ca_icc_init(&session, &context, &ca_icc_control->svc_uuid, ca_icc_control->svc_name);
    if(BSP_ERROR == ret)
    {
        icc_print_error("TEEK_InitializeContext failed!\n");
        return ret;
    }

    /* coverity[no_escape] */
    for( ; ; )
    {
        ret = TEEK_ca_icc_session(&session, ca_icc_control->session_cmd_id);
        if(BSP_ERROR == ret)
        {
            icc_print_error("TEEK_ca_icc_session fail!\n");
            break;
        }
    }

    TEEK_CloseSession(&session);
    TEEK_FinalizeContext(&context);

    return ret;
}

/******************************************************************************
Function:        TEEK_icc_ca_cfg_get
Description:     通过session传入命令字或值
Input:
        cmd_id      - 传送给安全OS的cmd_id
Output:          none
Return:          0: OK  其他: ERROR码
******************************************************************************/
static int TEEK_icc_ca_cfg_get(TEEC_Session *session, u32 cmd_id)
{
    TEEC_Result result;
    TEEC_Operation operation;
    unsigned int   origin;
    char task_name[32] = "";
    char cmd_id_str[4] = "";
    struct ca_icc_ctrl *ca_cfg_get = NULL;
    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramTypes = TEEC_PARAM_TYPES(
                           TEEC_MEMREF_TEMP_OUTPUT,
                           TEEC_NONE,
                           TEEC_NONE,
                           TEEC_NONE);

    ca_cfg_get = (struct ca_icc_ctrl *)osl_malloc(sizeof(struct ca_icc_ctrl));
    if (!ca_cfg_get)
    {
        icc_print_error("ca_cfg_get malloc fail!\n");
        return BSP_ERROR;
    }

    operation.params[0].tmpref.buffer = (void *)ca_cfg_get;
    operation.params[0].tmpref.size = sizeof(struct ca_icc_ctrl);

    result = TEEK_InvokeCommand(
                           session,
                           cmd_id,
                           &operation,
                           &origin);
    if (result != TEEC_SUCCESS) {
        icc_print_error("invoke failed!result = 0x%x!\n",result);
        osl_free(ca_cfg_get);
        return BSP_ERROR;
    }

    ca_cfg_get = (struct ca_icc_ctrl *)operation.params[0].tmpref.buffer;

    (void)snprintf(cmd_id_str, 4, "%d", ca_cfg_get->session_cmd_id);   
    (void)strncpy(task_name, ca_cfg_get->svc_name, 16 - strlen(cmd_id_str) - 1);
    (void)strncat(task_name, cmd_id_str, strlen(cmd_id_str));
    icc_print_error("icc_cfg_task_name: %s\n", task_name);

    if(ERROR == osl_task_init(task_name, ca_cfg_get->task_priority, 0x1000, (OSL_TASK_FUNC)ca_icc_task_func,(void *)ca_cfg_get, &ca_icc_task_id))
    {
        icc_print_error("ca icc task init fail!\n");
        osl_free(ca_cfg_get);
        return BSP_ERROR;
    }

    return BSP_OK;
}

int ca_icc_cfg_task_func(void* data)
{
    TEEC_Session session;
    TEEC_Context context;
    struct ca_icc_ctrl *ca_cfg = (struct ca_icc_ctrl *)data;
    int ret = BSP_ERROR;

    ret = TEEK_ca_icc_init(&session, &context, &ca_cfg->svc_uuid, ca_cfg->svc_name);
    if(BSP_ERROR == ret)
    {
        icc_print_error("TEEK_InitializeContext failed!\n");
        return ret;
    }

    /* coverity[no_escape] */
    for( ; ; )
    {
        ret = TEEK_icc_ca_cfg_get(&session, ca_cfg->session_cmd_id);
        if(BSP_ERROR == ret)
        {
            icc_print_error("TEEK_icc_ca_cfg_get fail!\n");
            break;
        }
    }

    TEEK_CloseSession(&session);
    TEEK_FinalizeContext(&context);

    return ret;
}

static struct ca_icc_ctrl ca_cfg_get = {
    .svc_uuid = TEE_SERVICE_SECBOOT,
    .svc_name = "sec_boot",
    .session_cmd_id = SECBOOT_CMD_ID_BSP_ICC_OPEN_THREAD,
    .task_priority = 90,
};

int __init ca_icc_init(void)
{
    int ret = BSP_OK;

    ret = osl_task_init("ca_icc_cfg", ca_cfg_get.task_priority, 0x1000, (OSL_TASK_FUNC)ca_icc_cfg_task_func,(void *)&ca_cfg_get, &ca_icc_task_id);
    if(ERROR == ret)
    {
        icc_print_error("ca icc task init fail!\n");
        return BSP_ERROR;
    }

    icc_print_error("ok\n");

    return BSP_OK;
}
#endif

int ca_icc_cfg_task_func(void* data)
{
    osl_task_delay(50000);
    for( ; ; )
    {
        (void)bsp_sec_call(FUNC_ICC_MSG_SWITCH_ON, 0);
        osl_task_delay(2000);
    }

    return 0;
}

int __init ca_icc_init(void)
{
    int ret = BSP_OK;

    ret = osl_task_init("ca_icc_cfg", 90, 0x1000, (OSL_TASK_FUNC)ca_icc_cfg_task_func, NULL, &ca_icc_task_id);
    if(ERROR == ret)
    {
        icc_print_error("ca icc task init fail!\n");
        return BSP_ERROR;
    }

    icc_print_error("ok\n");

    return BSP_OK;
}

//module_init(ca_icc_init);
#endif
