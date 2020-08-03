# Mobile Mining on Android 64 bits phone (arm64) with UserLand App

This folder describe how to CPU mine NewEnglandcoin (NENG) in 64 bits android phone (arm64) through UserLand app inside a linux terminal.  UserLand app is an open-source app that can run linux inside your android phone. 

- Minimum hardware requirement: 1G memory phone with 3G spare hard disk. 
- Software Required: UserLand app from Google Play Store or F-Droid

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/NENG_2020_Q3_report/NENG_2020_Q3_report.pdf 

For CPU mining steps and optimization with cheetah_Cpuminer, please checkout: 
https://github.com/ShorelineCrypto/cheetah_cpuminer

## Confusion on android vs linux on NENG v1.4.x release

There was some confusion created by recent android mining release v1.4.0.  Please watch this youtube video from android authority Gary Sims:

Is Android really just Linux? - Gary explains
https://www.youtube.com/watch?v=BkP6FTy0a4Y&t=307s

Not trying to create a flaming war.  Understanding the relationship between android vs linux, then you will clearly know what we did on NENG android CPU mining through UserLand app inside a linux terminal at almost native OS speed.


## Debian or Ubuntu?

UserLand app offers 4 linux distros (Alpine, Arch, Debian, Ubuntu). Currently for NewEnglandcoin android mining, two distros are supported and tested: Debian and Ubuntu. 

UserLand Debian runs Debian 10 (buster) on arm64.  UserLand ubuntu runs Ubuntu 18.04 on arm64.  The UserLand LXDE or XFCE desktop installation session uses Debian. 

Either distro is fine with similar user experience. If you are interested in desktop offering, Debian is preferred. 

## Linux Terminal (SSH) or Desktop (VNC or XSDL)? 

For NENG android mining purpose, we recommend using Linux terminal only through UserLand SSH login mode.  Our experience on debian or ubuntu has been fabulous and smooth with 
easy setup for remote login from windows/Mac/Linux desktop on big screen. 

In fact, we have tested XSDL/VNC in quad core android 8.0 on VNC or XSDL mode, and failed with crashes.  We do not know the reason of crash errors like "Connection Failed" after hours of LXDE or XFCE installation.  We also tested Arch SSH installation and failed to complete. 

Android is optimized for mobile GUI on top of linux kernel. GNU or regular linux LXDE or XFCE desktop is mainly for desktop/laptop environment. Therefore we see limited value using LXDE/XFCE in android phones any way. If you want to learn or have fun experience for linux, we would recommend to install a copy of Linux OS inside "VirtualBox" in windows 10. Oracle VirtualBox is free virtual machine software that can install and run a second operating system in windows 10 without need of dual boot.  With virutalBox setup for any one of 8 distros that we support for NENG wallet, you can mine NENG with cheetah_cpuminer easily in linux inside virtualbox of windows 10. 


### optional - Load GUI QT wallet into windows/mac/linux Desktop Remotely

 Running linux terminal-only does not mean that you can not load NENG QT wallet with GUI remotely. If your home wifi speed is decent, you could try to load NENG QT GUI wallet in windows 10, or MacOS or Linux Desktop PCs. 
 - Windows 10 with VcXsrv. Download, install and run free software "VcXsrv".  Check the screenshot2 of putty for enabling 
 "Enable X11 forwarding" for the userland login setting. Save the login session with X11 enabled, start VcXsrv in windows, 
 re-login into phone with putty and type below command lines:
 ```
 hlu@localhost:~$ cd newenglandcoin_v1.4.0_u16_arm64
 hlu@localhost:~/newenglandcoin_v1.4.0_u16_arm64$ ./newenglandcoin-qt &
```
 Above command inside putty will pop the QT GUI wallet in windows 10 with VcXsrv running. Wait for a while for the QT wallet to fully show up in windows, and then you can control the wallet inside phone from windows 10.
 - macOS with XQuartz. Download, install free software "XQuartz". Log out and re-login. Open up mac terminal:
 ```
 $ ssh -XY hlu@192.168.1.98 -p 2022
 -----login in phone----
 hlu@localhost:~$ cd newenglandcoin_v1.4.0_u16_arm64
 hlu@localhost:~/newenglandcoin_v1.4.0_u16_arm64$ ./newenglandcoin-qt &
```
Above in mac terminal will pop up android phone NENG QT GUI wallet in macOS desktop. 

 - Linux Desktop, any distro in a terminal
```
 honglu@MX $ ssh -XY hlu@192.168.1.98 -p 2022
 -----login in phone----
 hlu@localhost:~$ cd newenglandcoin_v1.4.0_u16_arm64
 hlu@localhost:~/newenglandcoin_v1.4.0_u16_arm64$ ./newenglandcoin-qt &
```
Above in linux desktop terminal will pop android phone NENG QT wallet in linux desktop remotely.
   
