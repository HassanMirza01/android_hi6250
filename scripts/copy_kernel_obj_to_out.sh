#!/bin/bash

kernel_src_tree=$1
kernel_out=$2

for obj in $(find -L $kernel_src_tree -name *.o); do dest=${obj/$kernel_src_tree/$kernel_out}; mkdir -p $(dirname  $dest);cp -f $obj $dest; done

