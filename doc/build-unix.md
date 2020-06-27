Copyright (c) 2009-2013 Bitcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.



# Dependencies for Ubuntu


 Library     Purpose           Description
 -------     -------           -----------
 libssl      SSL Support       Secure communications
 libdb4.8    Berkeley DB       Blockchain & wallet storage
 libboost    Boost             C++ Library
 miniupnpc   UPnP Support      Optional firewall-jumping support

[miniupnpc](http://miniupnp.free.fr/) may be used for UPnP port mapping.  It can be downloaded from [here](
http://miniupnp.tuxfamily.org/files/).  UPnP support is compiled in and
turned off by default.  Set USE_UPNP to a different value to control this:

	USE_UPNP=     No UPnP support miniupnp not required
	USE_UPNP=0    (the default) UPnP support turned off by default at runtime
	USE_UPNP=1    UPnP support turned on by default at runtime

IPv6 support may be disabled by setting:

	USE_IPV6=0    Disable IPv6 support


Linux Compilcation Guide

Licenses of statically linked libraries:
 Berkeley DB   New BSD license with additional requirement that linked
               software must be free open source
 Boost         MIT-like license
 miniupnpc     New (3-clause) BSD license


### Versions used in this release in Ubuntu 16.04

-  GCC           5.4
-  OpenSSL       1.0.2g
-  Berkeley DB   4.8.30.NC
-  Boost         1.58.0
-  miniupnpc     1.9
-  Qt 4.8

## Dependency Build Instructions: Ubuntu 16.04 / Ubuntu 18.04


Build requirements:

```
sudo apt-get install build-essential g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils  libboost-all-dev

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libzmq3-dev libbz2-dev 

sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler 

sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler
```

## sometimes zlib will generate error, reinstall this

sudo apt-get install --reinstall zlib1g

Optional:

	sudo apt-get install libminiupnpc-dev (see USE_UPNP compile flag)


Notes
-----
The release is built with GCC and then "strip bitcoind" to strip the debug
symbols, which reduces the executable size by about 90%.



## NewEnglandcoin Linux BUILD NOTES on Ubuntu 16.04

Headless newenglandcoin CLI

```
cd src
make -f makefile.unix USE_UPNP=1
strip newenglandcoind

```

 Qt GUI Wallet
```
   cd ..
   qmake USE_UPNP=1 
   make
``` 

# Ubuntu 18.04 Compile from source

There are three ways to obtain Ubuntu 18.04 compatible binary. The first approach is to follow similar steps above to compile everything in Ubuntu 18.04.  This could be complicated. Without custome method, a simple apt-get and same steps like Ubuntu 16.04 will fail on boost version incompatible with NENG wallet.

The easiest way is to take  Ubuntu 16.04 compiled binary files including the boost libary files version  1.58.0  and use it in Ubuntu 18.04. This should work in AMD64 and ARM64 64 bits machines.  However this approach is likely to fail on 32 bits arm android hardware because of hardware incompatibility issue.

A third way in the middle ground is simply using Ubuntu 16.04 compiled NENG binary files only, then compile a boost library version 1.58.0 in Ubuntu 18.04 tailored to hardware in Ubuntu 18.04. This is likely to be useful in arm 32 bits hardware where hardware compatibility on boost or library is issue across different Ubuntu version even on same hardware platform. Detailed steps:

* (1) Download Ubuntu 16.04 binary files from release from https://github.com/ShorelineCrypto/NewEnglandCoin/releases

* (2) Compile boost v1.58.0 library in Ubuntu 18.04 with below steps:

```
    wget -O boost_1_58_0.tar.bz2 http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.bz2/download
    tar xvfj boost_1_58_0.tar.bz2
    cd boost_1_58_0
    ./bootstrap.sh --with-libraries=all --with-toolset=gcc 
    ./b2 toolset=gcc 
    sudo ./b2 install --prefix=/usr 
    sudo ldconfig 
```

* (3) Re-run either QT or command line Ubuntu 16.04 files, all should work in Ubuntu 18.04
