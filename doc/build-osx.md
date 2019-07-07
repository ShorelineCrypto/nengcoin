Mac OS X newenglandcoind build instructions
====================================

Authors
-------

* Laszlo Hanyecz <solar@heliacal.net>
* Douglas Huff <dhuff@jrbobdobbs.org>
* Colin Dean <cad@cad.cx>
* Gavin Andresen <gavinandresen@gmail.com>
* Hong Lu <DISCORD/Bitcointalk/Marinecoin Forum ID: honglu69>

License
-------

Copyright (c) 2009-2012 Bitcoin Developers
Copyright (c) 2011-2014 Litecoin Developers
Copyright (c) 2018-2019 NewEnglandcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.

This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).

This product includes cryptographic software written by
Eric Young (eay@cryptsoft.com) and UPnP software written by Thomas Bernard.

Notes
-----


Tested on OS X 10.11 (El Capitan)/ macOS 10.14.4 (Mojave) on Intel processors only.  The compilation was 
done for OSX 10.7 or later version of MacOS. 

All of the commands should be executed in a Terminal application. The
built-in one is located in `/Applications/Utilities`.

### Preparation in OSX 10.11
-----------

Type below in terminal to install Xcode command line tools:
   ` xcode-select --install`

Open up browser such as firefox,  register for an apple developer
account and search web and download Xcode version 7.3.1.  Install dmg
file into Application of your Mac.

In below compiling steps in brew, there migh be warning that Xcode 7.3.1 is outdated, please upgrade to Xcode 8.x.x , ignore that. 

### Preparation in macOS 10.14

Type below in terminal to install Xcode command line tools:
   ` xcode-select --install`

### Required Package and Library for both OSX 10.11 and macOS 10.14

Perform below command line steps within terminal

#### Install HomeBrew

Follow brew:
https://brew.sh/


----------------------

#### Install dependencies using Homebrew

```
        brew install gcc@5
        brew install boost@1.55 miniupnpc openssl berkeley-db4
```

Note: After you have installed the dependencies, you should check that the Brew installed version of OpenSSL is the one available for compilation. You can check this by typing
```
        openssl version
```
into Terminal. You should see  "OpenSSL 1.0.2s  28 May 2019".

If not, you can ensure that the Brew OpenSSL is correctly linked by running

```
       brew link openssl --force
```

Rerunning "openssl version" should now return the correct version.

Above step may not work for macOS El Capitan or Mojave, insert below into ~/.bash_profile  file
and reboot the machine.


```
export PATH="/usr/local/Cellar/gcc@5/5.5.0_3/bin:/Library/Developer/CommandLineTools/usr/bin:/usr/local/opt/openssl/bin:$PATH"
export LDFLAGS="-L/usr/local/opt/openssl/lib"
export CPPFLAGS="-I/usr/local/opt/openssl/include"
```


Install Qt4.8  with below commands

```
    brew tap cartr/qt4
    brew tap-pin cartr/qt4
    brew install qt@4
```


### Building command line  and QT wallet

1. Clone the github tree to get the source code and go into the
   directory.

```
   git clone  https://github.com/ShorelineCrypto/NewEnglandCoin.git
   cd NewEnglandCoin/src
   make -f makefile.osx USE_UPNP=-
```

Special Note for macOS Mojave: a confusing error might pop up on first try, "fatal error: string.h: No such file or directory".
The string.h file might be there and look normal.  Follow below URL guide to fix the issue:
https://stackoverflow.com/questions/39736728/fatal-error-string-h-no-such-file-or-directory

```
   open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```

2. After successful compilcation, a file 'newenglandcoind' should show
up in the folder. This is command line wallet

3.  Run below to compile QT wallet under main folder

```
    cd ..
    cp bitcoin-qt.pro.osx bitcoin-qt.pro
    qmake USE_UPNP=-
    make
```




Running command line wallet
-------

It's now available at `./newenglandcoind`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./newenglandcoind` to get the filename where it should be put, or just try these
commands:

```
  echo -e "rpcuser=newenglandcoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/NewEnglandcoin/newenglandcoin.conf"
  chmod 600 "/Users/${USER}/Library/Application Support/NewEnglandcoin/newenglandcoin.conf"
```

When next you run it, it will start downloading the blockchain, but it won't
output anything while it's doing this. This process may take several hours.

Other commands:

```
    ./newenglandcoind --help  # for a list of command-line options. 
    ./newenglandcoind -daemon # to start the newenglandcoin daemon.
    ./newenglandcoind help    # When the daemon is running, to get a list of RPC commands
```


Running Qt wallet
-------

Use mouse to find the folder "NewEnglandcoin-Qt.app",  double click
and launch the GUI wallet "NewEnglandcoin-Qt.app".   QT wallet and command line wallet share
the same folder for configuration file and synced blockchain files.  They can not be running
together within same account, only one at a time.
