#!/bin/sh
cd ..
make APP=l0dable LAPP=msn
cd l0dable
make msn.c0d

cd ..
make APP=l0dable LAPP=sender
cd l0dable
make sender.c0d
