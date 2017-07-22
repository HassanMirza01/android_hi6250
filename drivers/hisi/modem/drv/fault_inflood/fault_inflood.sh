#!/system/bin/sh

G_TAGET=""

env_init()
{
	if ! test -f /system/bin/rfile
	then
		echo "there is not /system/bin/rfile!"
		exit 1
	fi

	if ! test -f /system/bin/rfile.ko
	then
		echo "there is not /system/bin/rfile.ko!"
		exit 1
	fi

	if ! test -f /system/bin/iozone
	then
		echo "there is not /system/bin/iozone!"
		exit 1
	fi
}

usage()
{
	echo "fault_inflood.sh help"
	echo "	help online."
	echo "fault_inflood.sh fault_inflood_testcaseXXX"
	echo "	XXX is 001, 002, ..., 037."
}

parse_input()
{
	G_TAGET=$1
}

fault_inflood_testcase001()
{
	echo "fault_inflood_testcase001"
	echo "NOT SUPPORT, Please see the testcase excel!"
}

fault_inflood_testcase002()
{
	echo "fault_inflood_testcase002"
	echo "NOT SUPPORT, Please see the testcase excel!"
}

fault_inflood_testcase003()
{
	echo "fault_inflood_testcase003"
	echo "NOT SUPPORT, Please see the testcase excel!"
}

fault_inflood_testcase004()
{
	echo "fault_inflood_testcase004"
	echo "NOT SUPPORT, Please see the testcase excel!"
}

fault_inflood_testcase005()
{
	echo "fault_inflood_testcase005"
	umount /mnvm2\:0/
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase006()
{
	echo "fault_inflood_testcase006"
	umount /modem_log/
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase007()
{
	echo "fault_inflood_testcase007"
	umount /modem_fw/
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase008()
{
	echo "fault_inflood_testcase008"
	umount /modem_secure/
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase009()
{
	echo "fault_inflood_testcase009"
	rm -rf /modem_fw/sec_balong_modem.bin
	if test -f /modem_fw/sec_balong_modem.bin
	then
		echo "PASS"
	fi
	if ! test -f /modem_fw/sec_balong_modem.bin
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase010()
{
	echo "fault_inflood_testcase010"
	rm -rf /modem_fw/sec_modem_dt.img
	if test -f /modem_fw/sec_modem_dt.img
	then
		echo "PASS"
	fi
	if ! test -f /modem_fw/sec_modem_dt.img
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase011()
{
	echo "fault_inflood_testcase011"
	rm -rf /mnvm2\:0/modem_nv/nv.bin
	if ! test -f /modem_fw/sec_balong_modem.bin
	then
		echo "PASS"
	fi
	if test -f /modem_fw/sec_balong_modem.bin
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase012()
{
	echo "fault_inflood_testcase012"
	rm -rf /modem_fw/sec_xphy_mcore.bin
	if test -f /modem_fw/sec_xphy_mcore.bin
	then
		echo "PASS"
	fi
	if ! test -f /modem_fw/sec_xphy_mcore.bin
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase013()
{
	echo "fault_inflood_testcase013"
	rm -rf /modem_fw/sec_lphy.bin
	if test -f /modem_fw/sec_lphy.bin
	then
		echo "PASS"
	fi
	if ! test -f /modem_fw/sec_lphy.bin
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase014()
{
	echo "fault_inflood_testcase014"
	rfile 0 /modem_fw/sec_balong_modem.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase015()
{
	echo "fault_inflood_testcase015"
	rfile 0 /modem_fw/sec_modem_dt.img
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase016()
{
	echo "fault_inflood_testcase016"
	rm -rf /mnvm2\:0/modem_nv/nv.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase017()
{
	echo "fault_inflood_testcase017"
	rfile 0 /modem_fw/sec_xphy_mcore.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase018()
{
	echo "fault_inflood_testcase018"
	rfile 0 /modem_fw/sec_lphy.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase019()
{
	echo "fault_inflood_testcase019"
	rfile full /mnvm2\:0/
}

fault_inflood_testcase020()
{
	echo "fault_inflood_testcase020"
	rfile full /modem_secure
}

fault_inflood_testcase021()
{
	echo "fault_inflood_testcase021"
	rfile full /modem_fw
}

fault_inflood_testcase022()
{
	echo "fault_inflood_testcase022"
	rfile full /modem_log
}

fault_inflood_testcase023()
{
	echo "fault_inflood_testcase023"
	echo "hello world" > /modem_fw/test.txt
	if ! test /modem_fw/test.txt
	then
		echo "PASS"
	fi
	if test /modem_fw/test.txt
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase024()
{
	echo "fault_inflood_testcase024"
	echo "hello world" > /mnvm2\:0/test.txt
	cat /mnvm2\:0/test.txt
	if test /mnvm2\:0/test.txt
	then
		echo "PASS"
	fi
	if ! test /mnvm2\:0/test.txt
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase025()
{
	echo "fault_inflood_testcase025"
	echo "hello world" > /modem_log/test.txt
	if test /modem_log/test.txt
	then
		echo "PASS"
	fi
	if ! test /modem_log/test.txt
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase026()
{
	echo "fault_inflood_testcase026"
	echo "hello world" > /modem_secure/test.txt
	if test /modem_secure/test.txt
	then
		echo "PASS"
	fi
	if ! test /modem_secure/test.txt
	then
		echo "FAIL"
	fi
}

fault_inflood_testcase027()
{
	echo "fault_inflood_testcase027"
	rfile broken /modem_fw/sec_balong_modem.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase028()
{
	echo "fault_inflood_testcase028"
	rfile broken /modem_fw/sec_modem_dt.img
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase029()
{
	echo "fault_inflood_testcase029"
	rfile broken /mnvm2\:0/modem_nv/nv.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase030()
{
	echo "fault_inflood_testcase030"
	rfile broken /modem_fw/sec_xphy_mcore.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase031()
{
	echo "fault_inflood_testcase031"
	rfile broken /modem_fw/sec_lphy.bin
	echo 11 > /sys/devices/platform/balong_power/state
}

fault_inflood_testcase032()
{
	i=0
	echo "fault_inflood_testcase032"
	mkdir /data/test
	ecall nv_test_create_read_write_task
	#ecall nv_test_set_read_write_count 10000
	until ((i>100))
	do
		iozone -ec -+n -L64 -S32 -r512k -s1g -i0 -w -f /data/test/testfile
		iozone -ec -+n -L64 -S32 -r512k -s1g -i1 -w -f /data/test/testfile
		echo "$i"
		let ++i
	done
	echo "fault_inflood_testcase032 over!"
}

fault_inflood_testcase033()
{
	echo "fault_inflood_testcase033"
	mkdir /data/test
	echo nv_test_wakeup_read_write_task > /sys/kernel/debug/fault_inflood/test_case
	if test $? -ne 0
		then
		exit 160
	fi

	until ((i>100))
	do
		iozone -ec -+n -L64 -S32 -r512k -s1g -i0 -w -f /data/test/testfile
		iozone -ec -+n -L64 -S32 -r512k -s1g -i1 -w -f /data/test/testfile
		echo "$i"
		let ++i
	done

	node_addr=$(cat /sys/kernel/debug/fault_inflood/test_case)
	if test $? -ne 0
	then
		exit 161
	fi

	echo ${node_addr} > /sys/kernel/debug/fault_inflood/test_rslt
	if test $? -ne 0
	then
		exit 162
	fi

	ecall testrslt_read

	echo "fault_inflood_testcase033 over!"
}

fault_inflood_testcase034()
{
	echo "fault_inflood_testcase034"
	mkdir /data/test
	echo modem_log_fs > /sys/kernel/debug/fault_inflood/test_case
	if test $? -ne 0
		then
		exit 160
	fi

	until ((i>100))
	do
		iozone -ec -+n -L64 -S32 -r512k -s1g -i0 -w -f /data/test/testfile
		echo "$i"
		let ++i
	done

	node_addr=$(cat /sys/kernel/debug/fault_inflood/test_case)
	if test $? -ne 0
	then
		exit 161
	fi

	echo ${node_addr} > /sys/kernel/debug/fault_inflood/test_rslt
	if test $? -ne 0
	then
		exit 162
	fi

	ecall testrslt_read

	echo "fault_inflood_testcase034 over!"
}

fault_inflood_testcase035()
{
	echo "fault_inflood_testcase035"
	ccore_fi ccore_access_outside_mem
}

fault_inflood_testcase036()
{
	echo "fault_inflood_testcase036"
	ccore_fi code_seg_readonly_mem
}

fault_inflood_testcase037()
{
	echo "fault_inflood_testcase037"
	ccore_fi readonly_mem
}

fault_inflood_testcase038()
{
	echo "fault_inflood_testcase038"
	ccore_fi overflow_mem
}

action_testcase()
{
	if test "$G_TAGET" = "help"
	then
		usage
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase001"
	then
		fault_inflood_testcase001
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase002"
	then
		fault_inflood_testcase002
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase003"
	then
		fault_inflood_testcase003
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase004"
	then
		fault_inflood_testcase004
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase005"
	then
		fault_inflood_testcase005
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase006"
	then
		fault_inflood_testcase006
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase007"
	then
		fault_inflood_testcase007
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase008"
	then
		fault_inflood_testcase008
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase009"
	then
		fault_inflood_testcase009
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase010"
	then
		fault_inflood_testcase010
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase011"
	then
		fault_inflood_testcase011
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase012"
	then
		fault_inflood_testcase012
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase013"
	then
		fault_inflood_testcase013
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase014"
	then
		fault_inflood_testcase014
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase015"
	then
		fault_inflood_testcase015
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase016"
	then
		fault_inflood_testcase016
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase017"
	then
		fault_inflood_testcase017
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase018"
	then
		fault_inflood_testcase018
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase019"
	then
		fault_inflood_testcase019
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase020"
	then
		fault_inflood_testcase020
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase021"
	then
		fault_inflood_testcase021
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase022"
	then
		fault_inflood_testcase022
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase023"
	then
		fault_inflood_testcase023
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase024"
	then
		fault_inflood_testcase024
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase025"
	then
		fault_inflood_testcase025
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase026"
	then
		fault_inflood_testcase026
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase027"
	then
		fault_inflood_testcase027
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase028"
	then
		fault_inflood_testcase028
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase029"
	then
		fault_inflood_testcase029
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase030"
	then
		fault_inflood_testcase030
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase031"
	then
		fault_inflood_testcase031
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase032"
	then
		fault_inflood_testcase032
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase033"
	then
		fault_inflood_testcase033
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase034"
	then
		fault_inflood_testcase034
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase035"
	then
		fault_inflood_testcase035
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase036"
	then
		fault_inflood_testcase036
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase037"
	then
		fault_inflood_testcase037
		exit 0
	fi

	if test "$G_TAGET" = "fault_inflood_testcase038"
	then
		fault_inflood_testcase038
		exit 0
	fi
}

env_init
parse_input "$@"
action_testcase
