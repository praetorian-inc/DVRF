# Damn Vulnerable Router Firmware (DVRF) v0.5

Thanks for checking out my project. The goal of this project is to simulate a real world environment to help people learn about other CPU architectures outside of the x86_64 space. This project is also for those who are curious about embedded research, but don't want to invest a lot of money.

This firmware was developed by modifying the [GPL source code](http://downloads.linksys.com/downloads/gplcode/1224700471571/E1550_1.0.03.002.tar.gz) for the Linksys E1550. If you do not have an E1550 don't worry! There's always QEMU and I encourage end users to experiment with both environments.

### Installation
To Install this binary onto your E1550 simply go to the Firmware Upgrade page `http://192.168.1.1/Upgrade.asp` and point the upgrade path to DVRF_v04.bin and click `"Upgrade"`

### Removal || Revert
To revert back to stock simply navigate to the main page of DVRF `http://192.168.1.1/index.asp`, Click Browse, Point it to the stock firmware binary, and Click `"Upload Firmware"`

### Getting Started
You don't have to have a E1550 in order to get started. The following link will show you how to get started with DVRF using QEMU to emulate the environment - https://www.praetorian.com/blog/getting-started-with-damn-vulnerable-router-firmware-dvrf-v0.1

### Source Code for pwnables
Feel free to take a look at the source code for the pwnables so you can get a better understanding MIPS assembly. Please note that the compiled binaries used gcc flag `-O0` to turn off compiler optimizations.

### Compiling your own DVRF build

* Download the Fedora 11 x86 ISO: https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/11/Fedora/i386/iso/Fedora-11-i386-DVD.iso
* Deploy a new VM and Install Fedora Core 11
  * **VirtualBox Installation Note**: You'll need to setup the environment as `"Linux --> Other (32-bit)"` since the Fedora template uses a SATA drive which for some reason hangs the login screen.
* Execute `merge_and_extract.sh` and if the tar ball was successfully made you can run `clean.sh` to remove the `-a*` files.
* Execute `deps.sh` to download and install all of the needed dependencies.
* Follow the instructions within the `"README.txt"` file to compile your own firmware binaries

=======

#### Fixes
* Removed header check from `unlink()` within `uClibc-0.9.29/libc/stdlib/malloc-standard/malloc.h` for `heap_overflow_01`
* It's now possible to compile the source and toolchain without `root` rights.
* Pwnable sources are now compiled during the `make` process.

#### Notes
* **DO NOT HAVE THE WAN PORT PLUGGED IN WHEN INSTALLING OR RUNNING THIS!!!**
* UART access is needed in order to execute the pwnable binaries.
* WiFi is disabled, only the ethernet ports are available.
* DVRF is a free tool for everything. Anything written up for this project must be made available to the public for free.
* New levels will be released soon. DVRF will be overhauled without the hacked GPL code to make it easier to read+modify. Plus, I'm tired of having to use Fedora 11 for this.

<a href="https://twitter.com/b1ack0wl">b1ack0wl</a>
