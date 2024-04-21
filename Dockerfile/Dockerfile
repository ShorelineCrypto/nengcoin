FROM ubuntu:16.04
RUN apt-get update  && apt-get clean

#install libbost, gcc and g++ compilers
RUN apt-get -y install build-essential
RUN apt-get -y install wget unzip
RUN apt-get -y install g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils
RUN apt-get -y install libboost-all-dev
RUN apt-get -y install software-properties-common
RUN add-apt-repository -y ppa:bitcoin/bitcoin
RUN apt-get update
RUN apt-get -y install libdb4.8-dev libdb4.8++-dev
RUN apt-get -y install libzmq3-dev libbz2-dev zlib1g libminiupnpc-dev
 
# install and compile NENG Core CLI wallet
WORKDIR /usr/local/

RUN apt-get -y install git
RUN git clone https://github.com/ShorelineCrypto/NengCoin.git

WORKDIR /usr/local/NengCoin/src
RUN make -f makefile.unix USE_UPNP=1
RUN strip nengcoind && cp  nengcoind /usr/local/bin/

# install and compile GUI QT wallet
RUN apt-get -y install libqt4-dev libprotobuf-dev protobuf-compiler
WORKDIR /usr/local/NengCoin
RUN qmake USE_UPNP=1
RUN make && cp nengcoin-qt /usr/local/bin/

WORKDIR /usr/local/
RUN rm -rf NengCoin

