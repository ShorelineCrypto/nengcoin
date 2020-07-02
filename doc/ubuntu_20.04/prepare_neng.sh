sudo apt-get update
sudo apt-get -y install build-essential 
sudo apt-get -y install g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils 
sudo apt-get -y install libboost-all-dev

sudo apt-get -y install software-properties-common
sudo apt-get -y  install python-software-properties
sudo apt-get update

 
sudo apt-get -y install libzmq3-dev libbz2-dev zlib1g 
 
 
sudo apt-get -y install openssl
sudo apt-get -y install libminiupnpc-dev

sudo apt-get -y install python-pip
pip install python-bitcoinrpc

sudo apt-get -y install git
#git clone https://github.com/ShorelineCrypto/NewEnglandCoin.git
#git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git


# Berkeley DB: http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
# This can not be compiled and used for NENG wallet
# we obtained binaries from Ubuntu 18.04 and bundled in one folder

wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu20.04_x86_64_db-4.8.30.NC.tgz
tar xvfz ubuntu20.04_x86_64_db-4.8.30.NC.tgz 
sudo mv db-4.8.30.NC  /opt/
sudo cp bitcoin.conf /etc/ld.so.conf.d/
sudo ldconfig

cat >> ~/.bashrc  << EOF

export LDFLAGS="-L/opt/db-4.8.30.NC/build_unix"
export CPPFLAGS="-I/opt/db-4.8.30.NC/build_unix"

EOF
