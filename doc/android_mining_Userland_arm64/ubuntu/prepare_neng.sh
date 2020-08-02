sudo apt-get -y install build-essential g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils  libboost-all-dev

sudo apt-get -y install software-properties-common
 
sudo add-apt-repository -y ppa:bitcoin/bitcoin
 
sudo apt-get -y update
 
sudo apt-get -y install libdb4.8-dev libdb4.8++-dev
 
sudo apt-get -y install libzmq3-dev libbz2-dev 
 
## sometimes zlib will generate error, reinstall this
sudo apt-get -y install --reinstall zlib1g
 
sudo apt-get -y install libminiupnpc-dev

sudo apt -y install git
sudo apt -y install python-pip
sudo pip install python-bitcoinrpc
