# Mobile Mining on Android 64 bits phone (arm64) with UserLand App

This folder describe how to CPU mine NewEnglandcoin (NENG) on 64 bits android phone (arm64). 

Minimum hardware requirement: 1G memory phone with 3G spare hard disk. 

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/NENG_2020_Q3_report/NENG_2020_Q3_report.pdf 


### Step 1: Install and setup UserLand app from Google Play Store

First install free "UserLand" app from google play store.  After installation, click Distribution 
"Ubuntu", pick a username, password, and VNC password (which could be same password). You will enter 
a linux terminal inside UserLand app, which runs a arm64 version of Ubuntu 18.04. 

Here we are recommending running through SSH (linux terminal) only, not VNC.  For linux GUI, it is much better to run remotely 
through putty and you can display all linux GUI software in windows 10 with a few mouse clicks of free software download and installs. See optional 
item at bottom of the page.

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

### optional - "screen" command to run cheetah_cpuminer

"screen" is useful linux command for background running in linux, you can start screen session job in the phone and log out. 
When you re-login into phone, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
####  start a screen session: type "screen" command in linux terminal
####  detach screen: Ctrl-A-D
####  re-attach screen: type "screen -r" command
####  re-attach specfic screen session when multiple sessions are running (say 3145.pts-1.localhost session):  screen -r 31

  Inside screen, run below in cheetah to mine NENG, detach screen
```
   screen

   python main.py --interval 10 --cpu 6

   CTRL-A-D

```

For more information on CPU mining with cheetah_Cpuminer, please checkout:
https://github.com/ShorelineCrypto/cheetah_cpuminer



   
