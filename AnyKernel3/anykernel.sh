# AnyKernel3 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() { '
kernel.string=Note 20 Ultra 5G Kernel by grbvieira @ xda-developers
do.devicecheck=1
do.modules=0
do.cleanup=1
do.cleanuponabort=1
device.name1=c2s
supported.versions=
supported.patchlevels=
'; } # end properties

# shell variables
block=/dev/block/by-name/boot;
is_slot_device=0;
ramdisk_compression=auto;


## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. tools/ak3-core.sh;

dump_boot;
write_boot;
