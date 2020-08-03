# Mobile Mining on Android 64 bits phone (arm64) with UserLand App

This folder describe how to CPU mine NewEnglandcoin (NENG) on 64 bits android phone (arm64). 

Minimum hardware requirement: 1G memory phone with 3G spare hard disk. 

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/NENG_2020_Q3_report/NENG_2020_Q3_report.pdf 


### Step 1: Install and setup UserLand app from Google Play Store

First install free "UserLand" app from google play store.  After installation, click Distribution 
"Ubuntu", pick a username, password, and VNC password (which could be same password). You will enter 
a linux terminal inside UserLand app, which runs arm64 version of Ubuntu 18.04. 

Here we are recommending running through SSH (linux terminal) only, not VNC.  For linux GUI, it is much better to run remotely 
through putty and you can display all linux GUI software in windows 10 with a few mouse clicks of free software download and installs. See optional 
item at bottom of the parent page.

### Step 2: prepare UserLand

Type below commands in linux terminal inside Userland:

```
  sudo apt update
  sudo apt install wget ssh
  hostname -I
```

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
### Step 4: Prepare UserLand app Linux Terminal
First login into UserLand app linux terminal remotely, you should find that common linux command like "top", "uptime" does not work. 
Please run below for workaround for those issues:
```
  bash prepare_userland.sh

```

After completion of above, logout and re-login into UserLand linux terminal, you should be able to use "top", "uptime" etc command. 


### Step 5: Install library files, wallet and cheetah_cpuminer
Please run below shell script in Userland Ubuntu for installing dependencies and library files:
```
  bash prepare_neng.sh

```
The above step automatically download binary NENG wallet file and cheetah_cpuminer in current folder.

### Step 6: Optimize CPU mining with Cheetah_Cpuminer:

Run below to find cpu info and memory information:

```
  more /proc/cpuinfo
  top
```
 For quad core phone, 8 cpu threads were found. You can now optimize Cheetah_Cpuminer parameter to perform android mining. 
 
 For more information on CPU mining with cheetah_Cpuminer, please checkout:
https://github.com/ShorelineCrypto/cheetah_cpuminer

### optional - "screen" command to run cheetah_cpuminer

"screen" is useful linux command for background running in linux, you can start screen session job in the phone and log out. 
When you re-login into phone, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
####  start a screen session: type "screen" command in linux terminal
####  detach screen: Ctrl-A-D
####  re-attach screen: type "screen -r" command
####  re-attach specfic screen session when multiple sessions are running (say 3145.pts-1.localhost session):  screen -r 31

  Inside screen, run below in cheetah to mine NENG, and detach screen
```
   screen

   python main.py --interval 10 --cpu 6

   CTRL-A-D

```

Now you can let the cheetah cpuminer running with the phone cord connected to charger. You can let it run overnight until you pick up the phone tomorrow for daily use. 



   
