# Change Log
All notable changes to this project will be documented in this file.
 

## [2.4.0] - 2024-04-27
 
Hard fork on and after block height 5438386. This is major release that all users are required to upgrade. 
 
### Added
- [Deep Reorg Protection](https://github.com/ShorelineCrypto/nengcoin/commit/e13c632bb5d36ce26c7320848ca5ee05177a2c16)
  Added the finalized block concept on rolling 96 blocks. Finalized blocks cannot be reorged, which protects the network against deep reorgs. This feature was ported from Bitcoin Cash v0.18.5 code base.
- [randomSpike 13x](https://github.com/ShorelineCrypto/nengcoin/commit/3965a8860d85a22a9ddfafe4491592a18074f0f9)
  Added randomSpike v1.13x difficulty aglorithm.  Compared to prior version of randomSpike (v1.12x), cheetah difficulty value will drop by 20x to 0.000244 while spike difficulty will rise 2x to 244k.
  
### Changed
- [Hard Fork Height](https://github.com/ShorelineCrypto/nengcoin/commit/5b7b11ee8035fa2da64bc8d9dd6f2f48a1382698)
  Added hard fork block height 5438386.  After this block height, this new release will form a new chain on the first cheetah block mined by the network. 

### Fixed
 
## [2.3.0] - 2022-06-06
  
Activate three soft forks - BIP68/BIP112/BIP113. Hard fork on and after block height 3800810. (Note, the actual NENG chain hard forked on height 3807405 off the prior old version).
 
### Added
- [randomSpike 12x](https://github.com/ShorelineCrypto/nengcoin/commit/9e216f2984f40345273a77847faea8a34dc25191)
  Added randomSpike v1.12x difficulty aglorithm.  Compared to prior version of randomSpike (v1.11x), cheetah difficulty value dropped 5% to  0.00488.
- [activate BIP68/BIP112/BIP113](https://github.com/ShorelineCrypto/nengcoin/commit/9e216f2984f40345273a77847faea8a34dc25191)
  Activate BIP34 at 100 blocks after hard fork height.  Enable deployment_csv 3 soft forks: BIP68/BIP112/BIP113.
 
### Changed
  
- [Hard Fork Height](https://github.com/ShorelineCrypto/nengcoin/commit/7fde8342303564a3551041fc88604a4b85e18088)
  Added hard fork block height 3800810.  After this block height, this new release will form a new chain on the first cheetah block mined by the network. 
 
- [Future timestamp 30 seconds rule](https://github.com/ShorelineCrypto/nengcoin/commit/df517fe74395d82e998c9e7b95c317a11dd32dfb)
 Enforced future timestamp 30 seconds rule after v1.12.x hard fork. Any new block received by full node with timestamp by more than 30 seconds in the future will be rejected.
 
 
## [2.2.0] - 2022-02-23
Reversed the 51% attack on SXC with this hard fork, cheetah difficulty rise by 5%.
### Changed
- [Hard fork](https://github.com/ShorelineCrypto/nengcoin/commit/0150f2206305acf64868adfbbcec73c945f57386)
Reversed the 51% attack on SXC in Feb 2022 with hard fork. Successfully eleminated double spending by orphaning the attacking chain with hard forked
chain at height prior to the attacking forked height with community consensus support of NENG users, miners, and centralized exchange. 

 
## [2.1.0] - 2022-02-17
Hard fork attempt to reverse the 51% attack on SXC, bitcoin 2 hours rule shortened to 2 minutes rule, cheetah diff drop 8x, spike diff cut in half.
### Changed
- [Hard fork](https://github.com/ShorelineCrypto/nengcoin/commit/c3fa11dd9e3e8af2e192f2b8ccbb7636268d6ddc)
 1st hard fork attemp to fix the 51% attack on SXC in Feb 2022, bitcoin 2 hours rule changed to 2 minutes rule, cheetah diff drop 8x, spike diff cut in half.
 
## [2.0.0] - 2022-02-04
NENG core code base rebased off litecoin core v0.13.3 on v1.9.x randomSpike
### Changed
- [Rebase Code Swap](https://github.com/ShorelineCrypto/nengcoin/commit/740d62ad86173e75443478059f15b3da2d5d8894)
  Old litecoin v0.8.7.5 code was replaced with new code based off litecoin v0.13.3 code.  The new core wallet can sync with v1.9.1 old wallet on randomSpike v1.9.x. 
- [MinWork Bug](https://github.com/ShorelineCrypto/nengcoin/commit/2e8ba0499a9ae027c430af41e30dbf7579fada42)
 Fix the same minimum work bug on litecoin core v0.13.3 new code base
 
## [1.9.1] - 2021-11-07
Fix the minimum work bug that caused mutiple public chains splitting. This is last old core wallet version on litecoin v0.8.7.5 code base.
### Fixed
- [MinWork Bug](https://github.com/ShorelineCrypto/nengcoin/commit/361053688176803d3bcacc4e067e91e539e2876a)
  Cheetah blocks have low difficulty, allowed to sync to fix MinWork Bug.
 
 ## [1.9.0] - 2021-10-31
Fix the 51% attack on SXC, cheetah diff drop by 20%, spike diff decrease by 10x
### Added
- [randomSpike v1.9.x](https://github.com/ShorelineCrypto/nengcoin/commit/77a9d9d0d727e661bbf1127234516fe07d59f5bf)
   
   
## [1.7.0] - 2021-04-03
Hard fork on block height 2759040, cheetah difficulty rise by 6x, spike difficulty rise by 10x.
### Added
- [randomSpike v1.7.x](https://github.com/ShorelineCrypto/nengcoin/commit/5e8736e242300005d86fb427d50884d3164764ae)
   

## [1.6.0] - 2021-02-21
Hard fork on block height 2655920, cheetah difficulty rise by 3x.
### Added
- [randomSpike v1.6.x](https://github.com/ShorelineCrypto/nengcoin/commit/013f7458aaace190edb46273bb12bb66b033d5fc)
   
 
## [1.5.0] - 2020-12-15
Hard fork on block height 2354920, cheetah difficulty rise by 10x, android phone mining feature upgraded.
### Added
- [randomSpike v1.5.x](https://github.com/ShorelineCrypto/nengcoin/commit/879fabbbbdfd9cf98a74c4c04d524be46aee59d9)
   
## Older NewEnglandcoin Versions
Nengcoin was renamed from formerly NewEnglandcoin. For NENG core versions older than v1.5.0, please check out NewEnglandcoin repo at
https://github.com/ShorelineCrypto/NewEnglandCoin
