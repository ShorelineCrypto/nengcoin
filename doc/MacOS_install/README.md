

# Supported - macOS on x86_64 or M1 chip

## Installation Guide of Nengcoin MacOS Wallet for mining

 Step 1: For first time NENG user only to create data folder
      If you have never ran NENG wallet before, double click QT wallet file first, run for a 1 minute, then shut down the w
allet. 

 Step 2: Copy 'nengcoin.conf' to your path '~/Library/'Application Support'/Nengcoin/'

```
  cp  nengcoin.conf  ~/Library/'Application Support'/Nengcoin/
```

 Step 3: Restart GUI wallet or CLI wallet.  The conf file contains a lot of live nodes ip addresses that will help your wal
let to sync. 
     Note for CPU/GPU/USB ASIC solo miners: your wallet needs to be fully synced to latest block before you can solo mine NENG. 


## Light Wallet as Reserve Wallet

The current recommended method is to use light wallet such as Komodo Wallet or Electrum-NENG wallet as light wallet
instead of below full node 2nd wallet method.



## Installation Guide of Nengcoin macOS Wallet for Reserve Wallet

Mining wallet can go bad quickly. It is recommended to transfer your mined coin to reserve wallet for backup daily. 
The reserve wallet shall have no mining. Put password and backup the reserve wallet regularly. 
Every month or two when the mining wallet goes bad, empty it, then delete the wallet file to start a fresh wallet. 

To setup a reserve wallet, below are the steps

Step 1:  copy the data folder from ~/Library/'Application Support'/Nengcoin/  to  ~/Library/'Application Support'/Nengcoin2/. 
Delete the "wallet.dat"  in the Nengcoin2 folder so that you get a new wallet file. 
Step 2:  Modify the batch script "reserve_neng.sh" with your proper username in conf file.
Step 3:  Run "reserve_neng.sh". You should have second reserve QT wallet running in macOS
