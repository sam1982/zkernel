mkernel
=======

This is a minimalist kernel which prints "`my first kernel`" on the screen and then hangs.

* The kernel is multi-boot compliant and loads with GRUB.


#### Blog post ####


#### Build commands ####
```
./build.sh    
```
#### Test on emulator ####
```
qemu-system-i386 -kernel kernel
```

#### Get to boot ####
GRUB requires your kernel executable to be of the pattern `kernel-<version>`.

So, rename the kernel:

```
mv kernel kernel-701
```

