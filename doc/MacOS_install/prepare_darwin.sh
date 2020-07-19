#! /bin/bash

  brew install gcc@5
  brew install boost@1.55 miniupnpc openssl berkeley-db4
  wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.20150206.tar.gz
  tar xvfz "download.php?file=miniupnpc-1.9.20150206.tar.gz"  
  mv miniupnpc-1.9.20150206  /usr/local/Cellar/miniupnpc/1.9
  cd  /usr/local/Cellar/miniupnpc/1.9
  make upnpc-static
  
  brew install openssl@1.0

  brew tap cartr/qt4
  brew install qt@4

## Step 4:  Switch openssl version 1.1 to 1.0
## https://stackoverflow.com/questions/59006602/dyld-library-not-loaded-usr-local-opt-openssl-lib-libssl-1-0-0-dylib

   cd /usr/local/Cellar/openssl@1.1
   ln -s ../openssl@1.0/1.0.2t

## Download GUI/CLI wallet
cd ~/Downloads
wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0.1/newenglandcoin_v1.4.0.1_macOS_GUI.dmg
wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0.1/newenglandcoin_v1.4.0.1_macOS_CLI.zip
