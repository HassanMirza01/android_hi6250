#!/bin/bash

if [ $# -lt 3 ]
then
	echo "error: not enough param."
	echo "USAGE: $0 type productname logversion buildproduct"
	exit 1
fi 

build_product=hi3650

if [ $# -ge 4 ]
then
	build_product=$4
fi 

converter_dir=../modem/config/errlog/chrdirectrpt/converter/deploy/bin/
build_dir=../../../../../../../build

cd $(dirname $0)
rm -f ChrRelationEvent.c
rm -f *.bin

./convertrelationevent.py

cp -f ./LOGDESC.xml ../../../xml/LOGDESC_$2_$3.xml
cp -f ./ENUMDESC.xml ../../../xml/ENUMDESC_$2_$3.xml

cd $build_dir
rm -rf ./delivery/$build_product

./HiBuild.sh product=$build_product tools_config_chr_relationevent
mv -f delivery/$build_product/lib/tools_config_chr_relationevent.o $converter_dir/tools_config_chr_relationevent.bin

./HiBuild.sh product=$build_product tools_config_chr_tlas
mv -f delivery/$build_product/lib/tools_config_chr_tlas.o $converter_dir/tools_config_chr_tlas.bin

rm -rf ./delivery/$build_product

cd $converter_dir
./convertelf . ../../../xml ../../../src/ChrStruMap.c "$1" "$2" "$3"

cd $(dirname $0)
rm -f ChrRelationEvent.c
rm -f *.bin
