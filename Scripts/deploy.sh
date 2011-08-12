#!/bin/sh
#Deploy Application (Put Inside r0ket folder)
sudo cp tools/bootloader/42-nxp-flash.rules /etc/udev/rules.d/
sudo /etc/init.d/udev restart

cd firmware
make flash APP=$1 
