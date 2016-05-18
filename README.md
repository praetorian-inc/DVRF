# Damn Vulnerable Router Firmware (DVRF) v0.3

Thanks for checking out my project. The goal of this project is to simulate a real world environment to help people learn about other CPU architectures outside of the x86_64 space. This project will also help people get into discovering new things about hardware.
As of now this firmware is tailored for the Linksys E1550 Device. If you do not have one don't worry! There's also Qemu and I will write up some tutorials on how to do this since this is another learning aspect of embedded device hacking especially for exploit development.

### Installation
> To Install this binary onto your E1550 simply go to the Firmware Upgrade page (http://192.168.1.1/Upgrade.asp) and point the upgrade path to DVRF_v01.bin and click "Upgrade"

### Removal || Revert
> To revert back to stock simply navigate to the main page of DVRF (http://192.168.1.1/index.asp), Click Browse, Point it to the stock firmware binary, and Click "Upload Firmware"

### Getting Started
> You don't have to have a E1550 in order to get started. The following link will show you how to get started with DVRF using QEMU to emulate the environment - https://www.praetorian.com/blog/getting-started-with-damn-vulnerable-router-firmware-dvrf-v0.1

### Source Code for pwnables
> Feel free to take a look at the source code for the pwnables so you can get a better understanding MIPS assembly. Please note that the compiled binaries used gcc flag -O0 to turn off compiler optimizations.

### Compiling your own DVRF build
> Execute **merge_and_compile.sh** and if the tar ball was successfully made you can run **clean.sh** to remove the 00* files.
> To compile just extract the TAR file and run **make.sh** and make sure to update **toolchain.sh** to the path of your toolchain
> The toolchain is located under ./projects/hnd/tools/linux/hndtools-mipsel-linux-uclibc-4.2.3/bin.
> Also note that the target linux version is 2.6 so you can either compile it on a 2.6 box like Fedora Core 11 or try compiling with the linux 2.6 headers.

=======

#### Fixes
* Replaced execve("/bin/sh",0,0) with system("/bin/sh -c")
* Due to "jr RA" I added exit(0) after the system() call to prevent infinite loops.

#### Bugs
* WiFi does not broadcast a SSID but all ethernet ports work and DHCP is enabled

#### TODO
* Implement new HTTPd
* Implement new FTPd
* Disable WAN Port **DO NOT HAVE THE WAN PORT PLUGGED IN WHEN INSTALLING OR RUNNING THIS!!!**
* Create pwnables that incorporate exploit mitigations (e.g. Stack Cookies & DEP)
* Create more Firmware images for other devices with different CPU architectures
* Clean up and TAR the Source Code so anyone can compile it.

-<a href="https://twitter.com/b1ack0wl">b1ack0wl</a>
