#!/bin/sh
#Must be used on the same folder as the git clone
echo "Getting the last Version"
git clone git://github.com/r0ket/r0ket.git
cd r0ket/firmware
cp SECRETS SECRETS.release
echo "Making Build"
sh release-all
cp ../release/final.bin ../tools/bootloader/firmware.bin
cd ../tools/bootloader/
echo "W8 +/- 30 secs"
./autoflash
#Turn the device with 1 method (Turn Left and Power One w8 almost 30 secs)
echo "After turn ON in USB Mode (Turn Down and Power) and Copy Release Files"
