# Damn Vulnerable Router Firmware (DVRF) v0.2

Thanks for checking out my project. The goal of this project is to simulate a real world environment to help people learn about other CPU architectures outside of the x86_64 space. This project will also help people get into discovering new things about hardware.
As of now this firmware is tailored for the Linksys E1550 Device. If you do not have one don't worry! There's also Qemu and I will write up some tutorials on how to do this since this is another learning aspect of embedded device hacking especially for exploit development.

### Installation
> To Install this binary onto your E1550 simply go to the Firmware Upgrade page (http://192.168.1.1/Upgrade.asp) and point the upgrade path to DVRF_v01.bin and click "Upgrade"

### Removal || Revert
> To revert back to stock simply navigate to the main page of DVRF (http://192.168.1.1/index.asp), Click Browse, Point it to the stock firmware binary, and Click "Upload Firmware"

### Source Code for pwnables
> Feel free to take a look at the source code for the pwnables so you can get a better understanding MIPS assembly. Please note that the compiled binaries used gcc flag -O0 to turn off compiler optimizations.

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
