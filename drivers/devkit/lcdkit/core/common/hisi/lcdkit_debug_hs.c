#include "hisi_fb.h"
#include "lcdkit_dbg.h"

void lcdkit_debug_set_vsp_vsn(void* vcc_cmds, int cnt)
{
    int i = 0;
    struct vcc_desc* cm = NULL;

    cm = (struct vcc_desc*) vcc_cmds;

    for (i = 0; i < cnt; i++)
    {
        if (cm->dtype == DTYPE_VCC_SET_VOLTAGE)
        {
            if (0 == strncmp(cm->id, VCC_LCDKIT_BIAS_NAME, strlen(cm->id)))
            {
                cm->min_uV = lcdkit_dbg.lcdkit_panel_bias;
                cm->max_uV = lcdkit_dbg.lcdkit_panel_bias;
            }
            else if (0 == strncmp(cm->id, VCC_LCDKIT_VSP_NAME, strlen(cm->id)))
            {
                cm->min_uV = lcdkit_dbg.lcdkit_panel_vsp;
                cm->max_uV = lcdkit_dbg.lcdkit_panel_vsp;
            }
            else if (0 == strncmp(cm->id, VCC_LCDKIT_VSN_NAME, strlen(cm->id)))
            {
                cm->min_uV = lcdkit_dbg.lcdkit_panel_vsn;
                cm->max_uV = lcdkit_dbg.lcdkit_panel_vsn;
            }
        }

        cm++;
    }
}