# Damn Vulnerable Router Firmware (DVRF) v0.4

Thanks for checking out my project. The goal of this project is to simulate a real world environment to help people learn about other CPU architectures outside of the x86_64 space. This project will also help people get into discovering new things about hardware.

As of now this firmware is tailored for the Linksys E1550 Device. If you do not have one don't worry! There's also QEMU and I encourage end users to experiment with both environments.

### Installation
To Install this binary onto your E1550 simply go to the Firmware Upgrade page `http://192.168.1.1/Upgrade.asp` and point the upgrade path to DVRF_v04.bin and click `"Upgrade"`

### Removal || Revert
To revert back to stock simply navigate to the main page of DVRF `(http://192.168.1.1/index.asp)`, Click Browse, Point it to the stock firmware binary, and Click `"Upload Firmware"`

### Getting Started
You don't have to have a E1550 in order to get started. The following link will show you how to get started with DVRF using QEMU to emulate the environment - https://www.praetorian.com/blog/getting-started-with-damn-vulnerable-router-firmware-dvrf-v0.1

### Source Code for pwnables
Feel free to take a look at the source code for the pwnables so you can get a better understanding MIPS assembly. Please note that the compiled binaries used gcc flag `-O0` to turn off compiler optimizations.

### Compiling your own DVRF build
Execute **merge_and_compile.sh** and if the tar ball was successfully made you can run **clean.sh** to remove the -a* files.`

Follow the instructions within the `"README.txt"`` file to compile your own firmware binaries

=======

#### Fixes
* Included MIPSel buildroot to fix compilation issues.
* Fixed shell scripts for merging and extracting the source TAR file.

#### Notes
* **DO NOT HAVE THE WAN PORT PLUGGED IN WHEN INSTALLING OR RUNNING THIS!!!**
* UART access is needed in order to execute the pwnable binaries.
* WiFi is disabled, only the ethernet ports are available.

-<a href="https://twitter.com/b1ack0wl">b1ack0wl</a>
