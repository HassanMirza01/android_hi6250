#!/bin/bash

converter_dir=../modem/config/errlog/chrdirectrpt/converter/deploy/bin/
build_dir=../../../../../../../build
project_dir=../../projects

cd $project_dir
make clean
make

cd $(dirname $0)
./convert_stru.sh "$1" "$2" "$3"
