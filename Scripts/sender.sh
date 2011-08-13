#!/bin/sh
#Build for simulator and final c0d
#Must be on (r0ket/firmware/l0dable)
#Usage sh sender.sh l0dable_name
cd ..
make APP=l0dable LAPP=$1
cd l0dable
make $1.c0d
