# Mobile Mining on Android 64 bits phone (arm64) with UserLand App

This folder describe how to CPU mine NewEnglandcoin (NENG) in 64 bits android phone (arm64) through UserLand app inside a linux terminal.  UserLand app is an open-source app that can run linux inside your android phone. 

Minimum hardware requirement: 1G memory phone with 3G spare hard disk. 
Software Required: UserLand app from Google Play Store or F-Droid

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/NENG_2020_Q3_report/NENG_2020_Q3_report.pdf 

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


### Step 3: Remember IP of phone from above step, remote login from desktop computer

For windows 10 desktop machine, install a free software "PuTTY", login into phone with your
username/password picked at port 2022

A screen shot of putty was provided. 

For linux or MacOS,  you can remote login with ssh from command line at port 2022. For example 
IP = 192.168.1.4 with user "hlu" like below 
```
  ssh hlu@192.168.1.4 -p 2022
```

## Now you can run below commands from putty from windows 10 or ssh from MacOS or Linux
### Step 4: Install library files
Please run below shell script in Userland Ubuntu for installing dependencies and library files:
```
  wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/newenglandcoin_v1.4.0_android_arm64_userland.tgz
  tar xvfz newenglandcoin_v1.4.0_android_arm64_userland.tgz 
  cd newenglandcoin_v1.4.0_android_arm64_userland 
  bash prepare_userland.sh
  bash prepare_neng.sh
  bash prepare_nengX.sh
```

### Step 5: download the binary wallet and boost:
```
  wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu16.04_boost1.58_arm64.tgz
  tar xvfz ubuntu16.04_boost1.58_arm64.tgz
  sudo mv boost1.58  /opt/
  sudo mv boost1.58.conf  /etc/ld.so.conf.d/
  sudo ldconfig

  wget  https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/newenglandcoin_v1.4.0_u16_arm64.tgz
  tar xvfz newenglandcoin_v1.4.0_u16_arm64.tgz
```

### Step 6: Install Cheetah_Cpuminer:

```
  git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git
  sudo pip install python-bitcoinrpc
  more /proc/cpuinfo
```

  Try to find how much cpu threads you have on the phone, for quad core phone, 8 cpu threads were found 

### optional - screen command to run cheeta
  screen is useful linux command for background running in linux, you can start screen session job in the phone and log out. 
When you re-login into phone, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
#### start a screen session: type "screen" command in linux terminal
####  detach screen: Ctrl-A-D
####  re-attach screen: type "screen -r" command
####  re-attach specfic screen session when multiple sessions are running (say 3145.pts-1.localhost session):  screen -r 31

  Inside screen, run below in cheetah to mine NENG, detach screen
```
   screen

   python main.py --interval 10 --cpu 6

   CTRL-A-D

```

### optional - load QT wallet in windows 10 remotely

 free software "VcXsrv" can be installed in windows 10 to allow QT GUI NENG wallet 
 running in phone and display in windows 10 remotely. Check the screenshot2 of putty for enabling 
 "Enable X11 forwarding" for the userland login setting. Once the login with X11 enabled, start VcXsrv in windows, 
 re-login into phone into linux command line,  type "./newenglandcoin-qt  & "  in phone linux terminal will 
 pop the QT GUI wallet in windows 10 running VcXsrv and control the wallet inside phone from windows.


   
