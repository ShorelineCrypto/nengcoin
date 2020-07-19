
macOS Catalina was also tested but failed to work or build so far because of discontinue on 32 bits software support.

Wallet binary files were compiled in OS X 10.11 (El Capitan) for macOS 10.14.4 (Mojave) on Intel processors only. For all MacOs versions between El Capitan and 
Mojave, the below guide should be valid too.    

For full guide of building own wallet on MacOS 10.11 , please follow steps at:
 https://github.com/ShorelineCrypto/NewEnglandCoin/blob/master/doc/build-osx.md


Step 1:  Install xcode
In Majave, type below in terminal to install Xcode command line tools:
    xcode-select --install

In older version of OSX such as 10.11, above one command is not enough. Open up browser such as firefox, register for an apple developer account and search web and download Xcode version 7.3.1. Install dmg file into Application of your Mac.

In below compiling steps in brew, there migh be warning that Xcode 7.3.1 is outdated, please upgrade to Xcode 8.x.x , ignore that.



Step 2: Install HomeBrew

Follow brew Installation Guide:
https://brew.sh/


Step 3:  Install Required Library Dependencies using Homebrew, wallet files are downloaded in "Download" folder
     brew update
     brew install wget     
     bash prepare_darwin.sh

Step 4:  Switch openssl/miniupnpc to older version, this is needed to run NENG wallet.

     bash enable_neng.sh    



Step 5 optional:  Restore system on openssl/miniupnpc for wget etc to work. 

When you are running already or after running, you may need to restore system version on openssl/miniupnpc to allow 
Wget etc software to work. 
 

    bash restore_system.sh