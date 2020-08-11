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

## FAQ - Linux Terminal Basic Keyboard

Typing command line in linux terminal inside UserLand is reasonably easy if you are familiar with linux command line on server or desktop. Here are android specific important points

#### TAB key on auto filling
See attached picture in this folder "tab.gif".  Tab key in android is the character below "ESC". It is left/right arrow in one symbol. TAB key is powerful in linux command line.  Typing full word of file or folder names are inconvenient. 

Here is easier way with tab:
```
   cd  newenglandcoin_v1.3.0.1_ubuntu16.04

```
  Typing above long word in android phone is close to impossible. An easier way to do is:

```
   cd  newe-finger push TAB key
```
After you push TAB afer word "newe" , the android UserLand linux terminal should behave like linux in server/desktop with the full file/folder name "newenglandcoin_v1.3.0.1_ubuntu16.04" auto populated for you. 

#### Arrow up or down key for history

The arrow up or down key is useful key if you want to repeat a command in recent history.  This is same as desktop/server linux terminal. 


## optional - "screen" command to run cheetah_cpuminer

"screen" is useful linux command for background running in linux, you can start screen session job in the phone and log out. 
When you re-login into phone, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
####  start a screen session: type "screen" command in linux terminal
####  detach screen: Ctrl-A-D
####  re-attach screen: type "screen -r" command
####  re-attach specfic screen session when multiple sessions are running (say 3145.pts-1.localhost session):  screen -r 31
#### force re-attach if the screen session is open at another computer: screen -r 31 -d

  Inside screen, run below in cheetah to mine NENG, and detach screen session to leave it running in background:
```
   screen

   python main.py --interval 10 --cpu 6

   CTRL-A-D

```

Now you can let the cheetah cpuminer running with the phone cord connected to charger. You can let it run overnight until you pick up the phone tomorrow for daily use. 




## optional - Load GUI QT wallet into windows/mac/linux Desktop Remotely

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

## optional - Fix the phone IP address at home LAN

If you have a router at home environment with wifi connection to the phone for android mining, you will realize that the phone IP address is constantly changing for each time to come home with wifi connection. You should be able to get a fixed IP address through your router setup so that you do not need to find out IP address each time to try the ssh login. 

Take NETGEAR router as example, after intranet admin login into web, say 192.168.1.1 as example, "ADVANCED" -> "WPS Wizard" -> "LAN Setup" -> "ADD", you can add a device mainly based on MAC address and assign that MAC address with an IP, say "192.168.1.98" in our case.  Apply and restart the router. Now reconnect phone wifi, you will get a fixed IP address on the phone no matter what. To avoid conflict with other electronic devices at home, try to pick large IP number, say 98 last digits. Other router vendors may have different lay out of admin web menu setup, but should have similar feature of allowing you to assign a fixed LAN internal IP address for the phone based on MAC address.

   
