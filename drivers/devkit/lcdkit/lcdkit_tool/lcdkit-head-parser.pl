# lcdkit-head-parser.pl

my $paranum = 0;
my $platform = $ARGV[$paranum];
$paranum++;

if ($platform eq 'qcom')
{
    require "./lcdkit-base-lib.pl";
}
else
{
    require "../../../../../chipset_common/devkit/lcdkit/lcdkit_tool/lcdkit-base-lib.pl";
}

# initialize the parser
my $lcd_xml_parser = new XML::LibXML;
my $parse_error_string = get_err_string();

debug_print("get chip platform is : $platform\n");

my $out_head_file = $ARGV[$paranum];
$paranum++;
debug_print("get head file path is : $out_head_file\n");

my $xml_file_num = uc($ARGV[$paranum]);
$paranum++;
debug_print("get xml file number is $xml_file_num\n");

if(scalar @ARGV < ($xml_file_num + $paranum))
{
    error_print(($xml_file_num + $paranum) . " command line arguments required.\n");
    error_print("1-chip platform(hisi or qcom)\n");
    error_print("2-out file path of head file\n");
    error_print("3-the number of XML Document to be parsed\n");
    error_print("4-". ($xml_file_num + $paranum) . ":XML Documents to parse\n");

    exit 1;
}

my @lcd_xml_doc;
my @lcd_xml_files;
for (my $count = 0; $count < $xml_file_num; $count++) {
    debug_print("get para file [$count] is $ARGV[$count + $paranum]\n");
    push(@lcd_xml_files, $ARGV[$count + $paranum]);
    push(@lcd_xml_doc, $lcd_xml_parser->parse_file($ARGV[$count + $paranum]));
}

my $panel_file_name = file_name_from_path($out_head_file);
welcome_print_begin(\@lcd_xml_files, $panel_file_name);

my $xml_version = parse_multi_xml('/hwlcd/Version');
if ($xml_version eq $parse_error_string) {
    error_print("get error xml file version!\n");
    exit_with_info($panel_file_name, 1);
}
debug_print("xml file version is : $xml_version\n");


print "=====================parsing head file: $panel_file_name.h ======================\n";

#generater head file used in lk or bootable
open (my $panel_head_file, '>'.$out_head_file) or die "open $out_head_file fail!\n";

print $panel_head_file create_hfile_header($xml_version, $panel_file_name);

if ($platform eq 'qcom')
{
    print $panel_head_file "#include \"panel.h\"\n\n";
}



#please keep alignment, thanks!
my @panel_config_attrs = (
    ["panel_name",                                 "-n",    
     "\"lcdkit_" . lc($panel_file_name) . "\"",                                  '-w', ''  ],
    ["/hwlcd/PanelEntry/PanelController",          "-f",    \&string_tran,       '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelCompatible",          "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelInterface",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelCmdType",             "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelDestination",         "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelOrientation",         "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelClockrate",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelFrameRate",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelChannelId",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/DSIVirtualChannelId",      "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelBroadcastMode",       "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/Lp11InitFlag",             "-n",    "",                  '-w', 0   ],
   #["/hwlcd/PanelEntry/PanelInitDelay",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/DelayAfLp11",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/DSIStream",                "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/InterleaveMode",           "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/BitClockFrequency",        "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelOperatingMode",       "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/UseEnableGpio",            "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/ModeGpioState",            "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/SlavePanelNodeId",         "-n",    "",                  '-w', 0   ]);

my @panel_resolution_attrs = (
    ["/hwlcd/PanelEntry/PanelXres",                "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/PanelYres",                "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HFrontPorch",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HBackPorch",               "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HPulseWidth",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HSyncSkew",                "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VFrontPorch",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VBackPorch",               "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VPulseWidth",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HLeftBorder",              "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HRightBorder",             "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VTopBorder",               "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VBottomBorder",            "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/HActiveRes",               "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/VActiveRes",               "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/InvertDataPolarity",       "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/InvertVsyncPolarity",      "-n",    "",                  '-w', 0   ],
    ["/hwlcd/PanelEntry/InvertHsyncPolarity",      "-n",    "",                  '-w', 0   ]);

my @panel_color_attrs = (
    ["/hwlcd/PanelEntry/ColorFormat",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/ColorOrder",               "-f",    \&string_tran,        '-w', 0  ],
    ["/hwlcd/PanelEntry/UnderFlowColor",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BorderColor",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PixelPacking",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PixelAlignment",           "-n",    "",                   '-w', 0  ]);

my @panel_cmd_state = (
    ["/hwlcd/PanelEntry/PanelOnCommandState",      "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelOffCommandState",     "-n",    "",                   '-w', 0  ]);

my @panel_cmd_info = (
    ["/hwlcd/PanelEntry/TECheckEnable",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEPinSelect",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEUsingTEPin",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/AutoRefreshEnable",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/AutoRefreshEnable",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEvSyncRdPtrIrqLine",      "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEvSyncContinuesLines",    "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEvSyncStartLineDivisor",  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEPercentVariance",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TEDCSCommand",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DisableEoTAfterHSXfer",    "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/CmdModeIdleTime",          "-n",    "",                   '-w', 0  ]);

my @panel_vedio_info = (
    ["/hwlcd/PanelEntry/HSyncPulse",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/HFPPowerMode",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/HBPPowerMode",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/HSAPowerMode",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLLPEOFPowerMode",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLLPPowerMode",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TrafficMode",              "-f",    \&string_tran,        '-w', 0  ],
    ["/hwlcd/PanelEntry/DMADelayAfterVsync",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLLPEOFPower",             "-n",    "",                   '-w', 0  ]);

my @panel_lane_cfginfo = (
    ["/hwlcd/PanelEntry/DSILanes",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DSILaneMap",               "-f",    \&string_tran,        '-w', 0  ],
    ["/hwlcd/PanelEntry/Lane0State",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/Lane1State",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/Lane2State",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/Lane3State",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/ForceClkLaneHs",           "-n",    "",                   '-w', 0  ]);

my @panel_timing = (
    ["/hwlcd/PanelEntry/PanelTimings",             "-f",    \&apply_patten,       '-w', 0  ]);
if ($platform eq 'qcom')
{
    my $lkusedtiming = parse_multi_xml("/hwlcd/PanelEntry/LkUsedTiming");
    if ($lkusedtiming ne $parse_error_string)
    {
    	#if lk used timing is specificed, used it or use default
    	$lkusedtiming = apply_patten($lkusedtiming);
    	$panel_timing[0][0] = "/hwlcd/PanelEntry/" . $lkusedtiming;
    }
}

my @panel_timing_info = (
    ["/hwlcd/PanelEntry/DSIMDPTrigger",            "-f",    \&string_tran,        '-w', 0  ],
    ["/hwlcd/PanelEntry/DSIDMATrigger",            "-f",    \&string_tran,        '-w', 0  ],
    ["/hwlcd/PanelEntry/TClkPost",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TClkPre",                  "-n",    "",                   '-w', 0  ]);

my @panel_backlight_set = (
    ["/hwlcd/PanelEntry/BLInterfaceType",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLMinLevel",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLMaxLevel",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLStep",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLPMICControlType",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLPMICModel",              "-n",    "",                   '-w', 0  ]);

my @panel_labibb_set = (
    ["/hwlcd/PanelEntry/PanelType",                "-f",    \&parse_panel_type,   '-w', 0  ],
    ["/hwlcd/PanelEntry/ForceConfig",              "-n",    "",                   '-w', 0  ],
#   ["/hwlcd/PanelEntry/IbbMinVolt",               "-n",    "",                   '-w', 0  ],
#   ["/hwlcd/PanelEntry/IbbMaxVolt",               "-n",    "",                   '-w', 0  ],
#   ["/hwlcd/PanelEntry/LbbMinVolt",               "-n",    "",                   '-w', 0  ],
#   ["/hwlcd/PanelEntry/LbbMaxVolt",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsp",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsp",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsn",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsn",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/IbbDischargEn",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/Swire_controlEn",          "-n",    "",                   '-w', 0  ]);

my @regulator_setting = (
    ["/hwlcd/PanelEntry/RegulatorSetting",         "-f",    \&apply_patten,       '-w', 0  ]);

my @qcom_platcfg_attrs = (
    ["/hwlcd/PanelEntry/WledSlaveId",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/UseBlGpio",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/UseModeGpio",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/UseGpioBlEn",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/OnLdomap",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/OffLdomap",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VciLdomap",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/IovccLdomap",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioTpReset",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioEnable",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioMode",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioReset",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioTe",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioIovcc",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVci",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVsp",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVsn",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioBl",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioBlEn",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdanalogVcc",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdioVcc",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdBias",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsp",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsn",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BLDefaultLevel",           "-n",    "",                   '-w', 0  ]);

my @qcom_misc_attrs = (
    ["/hwlcd/PanelEntry/IovccOnIsNeedReset",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VsnOnIsNeedReset",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdType",                  "-n",    "",                   '-w', 0  ],
   #["/hwlcd/PanelEntry/ReadPowerStatus",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelType",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BiasPowerCtrlMode",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/IovccPowerCtrlMode",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VciPowerCtrlMode",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/TxEotAppend",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/RxEotIgnore",              "-n",    "",                   '-w', 0  ]); 

my @qcom_delayctl_attrs = (
    ["/hwlcd/PanelEntry/DelayAfVciOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfIovccOn",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfBiasOn",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVspOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOn",             "-n",    "",                   '-w', 0  ],
   #["/hwlcd/PanelEntry/DelayAfLp11",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVspOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfBiasOff",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfIovccOff",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVciOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayBeBL",                "-n",    "",                   '-w', 0  ]);

my @qcom_on_cmd_paras = ("hwlcd/PanelEntry/PanelOnCommand",
                         $panel_file_name."_on_cmd", $panel_file_name."_on_command");

my @qcom_off_cmd_paras = ("hwlcd/PanelEntry/PanelOffCommand",
                         $panel_file_name."_off_cmd", $panel_file_name."_off_command");
                         
#my @panel_reset_seq_paras = ("hwlcd/PanelEntry/ResetSequence",
#            'static struct panel_reset_sequence ' . $panel_file_name . '_reset_seq');
my @panel_reset_seq_paras = (
    ["/hwlcd/PanelEntry/LcdRstFirstHigh",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdRstLow",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdRstSecondHigh",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/EnableBit",                "-n",    "",                   '-w', 0  ]);

################################################################################################

my @panel_info_attrs = (
    ["/hwlcd/PanelEntry/PanelXres",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelYres",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelWidth",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelHeight",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelOrientation",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBpp",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBgrfmt",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlType",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlmin",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlmax",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlpwmIntrValue",      "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlpwmMaxValue",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelCmdType",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelCompatible",          "-n",    "",                   '-w', 0  ],    
    ["/hwlcd/PanelEntry/PanelIfbcType",            "-n",    "",                   '-w', 0  ],
    ["panel_name",                                 "-n",    
     "\"/"."lcdkit_" . lc($panel_file_name) . "\"",                               '-w', '' ],
    ["/hwlcd/PanelEntry/PanelFrcEnable",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelEsdEnable",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelCeSupport",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelPrefixSharpSupport",  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelSblSupport",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelAcmSupport",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelAcmCeSupport",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelGammaSupport",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelPxlClk",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelPxlClkDiv",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelDirtUpdtSupport",     "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelDsiUptSupport",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelVsynCtrType",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelBlPwmPreciType",      "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelStepSupport",         "-n",    "",                   '-w', 0  ]);

my @panel_ldi_attrs = (
    ["/hwlcd/PanelEntry/HBackPorch",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/HFrontPorch",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/HPulseWidth",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VBackPorch",               "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VFrontPorch",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VPulseWidth",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiHsyncPlr",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiVsyncPlr",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiPixelClkPlr",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiDataEnPlr",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiDpi0OverlapSize",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LdiDpi1OverlapSize",       "-n",    "",                   '-w', 0  ]);

my @panel_mipi_attrs = (
    ["/hwlcd/PanelEntry/MipiVc",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiLaneNums",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiColorMode",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClk",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiBurstMode",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiMaxEscClk",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkVal1",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkVal2",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkVal3",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkVal4",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkVal5",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiDsiBitClkUpt",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiNonContinueEnable",    "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkPostAdjust",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkPreAdjust",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkTHsPrepareAdjust",  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkTLpxAdjust",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkTHsTrailAdjust",    "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkTHsExitAdjust",     "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/MipiClkTHsZeroAdjust",     "-n",    "",                   '-w', 0  ]);

my @panel_platcfg_attrs = (
    ["/hwlcd/PanelEntry/GpioReset",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioTe",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioIovcc",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVci",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVsp",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioVsn",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/GpioBl",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdanalogVcc",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdioVcc",                 "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdBias",                  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsp",                   "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdVsn",                   "-n",    "",                   '-w', 0  ]);

my @panel_misc_attrs = (
    ["/hwlcd/PanelEntry/IovccOnIsNeedReset",       "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/VsnOnIsNeedReset",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdType",           "-n",    "",                '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelTpColorSupport",          "-n",    "",               '-w', 0  ],
    ["/hwlcd/PanelEntry/IdPinReadSupport",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelType",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BiasPowerCtrlMode",        "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/IovccPowerCtrlMode",        "-n",    "",                  '-w', 0  ],
    ["/hwlcd/PanelEntry/VciPowerCtrlMode",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/BlPowerCtrlMode",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelDisplayOnInBaklight",  "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/PanelDisplayOnEffectSupport",  "-n",    "",                '-w', 0  ]);

my @panel_delayctl_attrs = (
    ["/hwlcd/PanelEntry/DelayAfVciOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfIovccOn",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfBiasOn",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVspOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOn",             "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfLp11",              "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdRstFirstHigh",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdRstLow",                "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/LcdRstSecondHigh",         "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVsnOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVspOff",            "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfBiasOff",           "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfIovccOff",          "-n",    "",                   '-w', 0  ],
    ["/hwlcd/PanelEntry/DelayAfVciOff",            "-n",    "",                   '-w', 0  ]);
	
my @hisi_on_cmd_paras = ("hwlcd/PanelEntry/PanelOnCommand", $panel_file_name."_on_cmds");
my @hisi_display_on_in_backlight_cmd_paras = ("hwlcd/PanelEntry/PanelDisplayOnCommand", $panel_file_name."_display_on_in_backlight_cmds");
my @hisi_off_cmd_paras = ("hwlcd/PanelEntry/PanelOffCommand", $panel_file_name."_off_cmds");
my @hisi_tp_color_cmd_paras = ("hwlcd/PanelEntry/PanelTpColorCommand", $panel_file_name."_tp_color_cmds");
my @hisi_id_pin_check_cmd_paras = ("hwlcd/PanelEntry/PanelIdPinCheckCommand", $panel_file_name."_id_pin_check_cmds");
my @hisi_display_on_effect_cmd_paras = ("hwlcd/PanelEntry/PanelDisplayOnEffectCommand", $panel_file_name."_display_on_effect_cmds");

my @head_property_strings = (
        ['qcom',      "Panel configuration",                \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_config_attrs,                 \&create_data_struct,
         'static struct panel_config ' . $panel_file_name. '_panel_data '                  ],
        ['qcom',      "Panel resolution",                   \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_resolution_attrs,             \&create_data_struct,
         'static struct panel_resolution ' . $panel_file_name. '_panel_res '               ],
        ['qcom',      "Panel color information",            \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_color_attrs,                  \&create_data_struct,
         'static struct color_info ' . $panel_file_name. '_color '                         ],
        ['qcom',      "Panel on/off command ",              \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@qcom_on_cmd_paras,                  \&qcom_cmd_struct_grp,
         ''                                                                                ],
        ['qcom',      \@qcom_off_cmd_paras,                 \&qcom_cmd_struct_grp,
         ''                                                                                ],
        ['qcom',      \@panel_cmd_state,                    \&create_data_struct,
         'static struct command_state ' . $panel_file_name . '_state '                     ],
        ['qcom',      "Command mode panel",                 \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_cmd_info,                     \&create_data_struct,
         'static struct commandpanel_info '.$panel_file_name.'_command_panel '             ],
        ['qcom',      "Video mode panel",                   \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_vedio_info,                   \&create_data_struct,
         'static struct videopanel_info ' . $panel_file_name . '_video_panel '             ],
        ['qcom',      "Lane configuration",                 \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_lane_cfginfo,                 \&create_data_struct,
         'static struct lane_configuration ' . $panel_file_name . '_lane_config '          ],
        ['qcom',      "Panel timing",                       \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_timing,                       \&create_data_struct,
         'static const uint32_t ' . $panel_file_name . '_timings[]'                        ],
        ['qcom',      \@panel_timing_info,                  \&create_data_struct,
         'static struct panel_timing ' . $panel_file_name . '_timing_info '                ],
        ['qcom',      "Panel reset sequence",               \&hfile_section_header,
         ''                                                                                ],
#       ['qcom',      \@panel_reset_seq_paras,              \&parser_reset_seq_qcom,
#        ''                                                                                ],
        ['qcom',      \@panel_reset_seq_paras,              \&parser_reset_seq_comm,
         'static struct panel_reset_sequence ' . $panel_file_name . '_reset_seq '          ],
        ['qcom',      "Backlight setting",                  \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_backlight_set,                \&create_data_struct,
         'static struct backlight ' . $panel_file_name . '_backlight '                     ],
        ['qcom',      "Labibb setting",                     \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@panel_labibb_set,                   \&create_data_struct,
         'static struct labibb_desc ' . $panel_file_name . '_labibb '                      ],
        ['qcom',      "turn on backlight delay",            \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      '/hwlcd/PanelEntry/MdpPipeType',      \&print_data_var,
         'int ' . $panel_file_name . '_mdp_pipe_type '                                     ],
        ['qcom',      '/hwlcd/PanelEntry/DsiPllType',       \&print_data_var,
         'int ' . $panel_file_name . '_dsi_pll_type '                                      ],
        ['qcom',      '/hwlcd/PanelEntry/MipiSignature',    \&print_data_var,
         'int ' . $panel_file_name . '_mipi_signature '                                    ],
        ['qcom',      \@regulator_setting,                  \&create_data_struct,
         'static const uint32_t ' . $panel_file_name . '_regulator_setting[]'              ],
        ['qcom',      "platform Config",                    \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@qcom_platcfg_attrs,                 \&create_data_struct,
         'static struct lcdkit_platform_config ' . $panel_file_name. '_panel_platform_config '    ],
        ['qcom',      "misc Information",                   \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@qcom_misc_attrs,                    \&create_data_struct,
         'static struct lcdkit_misc_info ' . $panel_file_name. '_panel_misc_info '         ],
        ['qcom',      "delay ctrl",                         \&hfile_section_header,
         ''                                                                                ],
        ['qcom',      \@qcom_delayctl_attrs,                \&create_data_struct,
         'static struct lcdkit_delay_ctrl ' . $panel_file_name. '_panel_delay_ctrl '       ],

        ['hisi',      "Panel Information",                  \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_info_attrs,                   \&create_data_struct,
         'static struct lcdkit_panel_info ' . $panel_file_name. '_panel_info '             ],
        ['hisi',      "Ldi Information",                    \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_ldi_attrs,                    \&create_data_struct,
         'static struct lcdkit_panel_ldi ' . $panel_file_name. '_panel_ldi '               ],
        ['hisi',      "Mipi Information",                   \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_mipi_attrs,                   \&create_data_struct,
         'static struct lcdkit_panel_mipi ' . $panel_file_name. '_panel_mipi '             ],
        ['hisi',      "platform Config",                    \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_platcfg_attrs,                \&create_data_struct,
         'static struct lcdkit_platform_config ' . $panel_file_name. '_panel_platform_config '    ],
        ['hisi',      "misc Information",                   \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_misc_attrs,                   \&create_data_struct,
         'static struct lcdkit_misc_info ' . $panel_file_name. '_panel_misc_info '         ],

        ['hisi',      "delay ctrl",                         \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@panel_delayctl_attrs,               \&create_data_struct,
         'static struct lcdkit_delay_ctrl ' . $panel_file_name. '_panel_delay_ctrl '       ],
        ['hisi',      "on/off cmd information",             \&hfile_section_header,
         ''                                                                                ],
        ['hisi',      \@hisi_on_cmd_paras,                  \&hisi_cmd_struct_grp,
         ''                                                                                ],
        ['hisi',      \@hisi_display_on_in_backlight_cmd_paras,    \&hisi_cmd_struct_grp,
         ''                                                                                ],
        ['hisi',      \@hisi_display_on_effect_cmd_paras,    \&hisi_cmd_struct_grp,
         ''                                                                                ],
        ['hisi',      \@hisi_off_cmd_paras,                 \&hisi_cmd_struct_grp,
         ''                                                                                ],
        ['hisi',      \@hisi_tp_color_cmd_paras,            \&hisi_cmd_struct_grp,
         ''                                                                                ],
        ['hisi',      \@hisi_id_pin_check_cmd_paras,        \&hisi_cmd_struct_grp,
         ''                                                                                ]);

for ($count = 0; $count < @head_property_strings; $count++)  {	
	  if (($platform eq $head_property_strings[$count][0])
	   || ('comm' eq $head_property_strings[$count][0]))
	  {
        my $parser_tmp_str = $head_property_strings[$count][2]->($head_property_strings[$count][1]);
        print $panel_head_file $head_property_strings[$count][3] . $parser_tmp_str;
		}
}

print $panel_head_file create_hfile_tail($panel_file_name);
close($panel_head_file);

exit_with_info($panel_file_name, 0);


sub parser_hex_order {  return parser_hex_order_base(shift, $platform);  }
sub parse_multi_xml  {  return parse_multi_xml_base(\@lcd_xml_doc, shift);  }