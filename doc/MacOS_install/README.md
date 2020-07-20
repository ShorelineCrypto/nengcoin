# macOS 10.15 (Catalina) - Not Supported
macOS Catalina was also tested but failed to work or build because of Apple's decision to discontinue support on 32 bits software.

We recommend to run a virtual machine of Mojave in Catalina in order to run NewEnglandcoin (NENG) full node for CPU mining or other 
purposes.  

# Supported - macOS 10.11 El Capitan to 10.14 Mojave

For full guide of building own wallet from source, please follow steps at:
 https://github.com/ShorelineCrypto/NewEnglandCoin/blob/master/doc/build-osx.md

Here below we describe an easier way to install macOS wallet on NENG v1.4.0.1 


### Step 1:  Install xcode
In all mac versions, type below in terminal to install Xcode command line tools:
```
    xcode-select --install
```

In older version of OSX such as 10.11, above one command may not be enough. Open up browser such as firefox, register for an apple developer account and search web and download Xcode version 7.3.1. Install dmg file into Application of your Mac.  In below compiling steps in brew, there might be warning that Xcode 7.3.1 is outdated, please upgrade to Xcode 8.x.x , ignore that.


### Step 2: Install HomeBrew

Follow brew Installation Guide:
https://brew.sh/


### Step 3:  Install Required Library Dependencies using Homebrew, download wallet files

Open up terminal, type
```
     brew update
     brew install wget     
     bash prepare_darwin.sh
```

Sometimes Mojave will have header errors because of updates,  like below:
```
upnpc.c:8:10: fatal error: 'stdio.h' file not found
#include <stdio.h>
         ^~~~~~~~~
1 error generated.
make: *** [upnpc.o] Error 1
``` 

Fix the errors by running: 
```
    open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```

rerun "prepare_darwin.sh" should fix the issue. 


CLI and GUI wallet files are downloaded in "Downloads" folder


### Step 4:  Switch openssl/miniupnpc to older version

Brew now installed newer and imcompatible versions.  Older version of libraries are enabled as default in order to run NENG.

```
     bash enable_neng.sh    
```


### Step 5 optional:  Restore system on openssl/miniupnpc

When you are running NENG already or after running, you may need to restore system (newer) versions on openssl/miniupnpc to allow 
softwares such as wget etc to work. 
 
```
    bash restore_system.sh

```

