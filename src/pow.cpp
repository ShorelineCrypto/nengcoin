// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "pow.h"

#include "arith_uint256.h"
#include "chain.h"
#include "primitives/block.h"
#include "uint256.h"
#include "util.h"

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    unsigned int nProofOfWorkLimit = UintToArith256(params.powLimit).GetCompact();
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    
    // Genesis block
    if (pindexLast == NULL)
        return nProofOfWorkLimit;

    // Only change once per difficulty adjustment interval, both mainnet and testnet allow min diff
    if (((pindexLast->nHeight+1) % params.DifficultyAdjustmentInterval() != 0) && params.fPowAllowMinDifficultyBlocks )
    {
        // Special difficulty rule for testnet/mainnet on Nengcoin:
        // If the new block's timestamp is more than 2* 10 minutes
        // then allow mining of a cheetah block for CPU/mobile miners on PC or android phones
        
        const CBlockIndex* pindex = pindexLast;
        const int64_t nInterval = params.DifficultyAdjustmentInterval();
        const int64_t nTargetSpacing = params.nPowTargetSpacing;

        // v1.13.x hard fork after block  5287700
        if (pindex->nHeight > 5287700) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 1;
            unsigned int nCheetah = bnCheetah.GetCompact();

            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 1000000000;
            unsigned int nSpike = bnSpike.GetCompact();

            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 40) || (pblock->nTime < pindexLast->nTime - 40))
            {
                // Return the last non-special-min-difficulty-rules-block

                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 30) || (pblock->nTime < pindexLast->nTime - 30))
            {
                // 50% random chance on Spike difficulty between  +- 30 to 40 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 10) || (pblock->nTime < pindexLast->nTime - 10))
            {
                // 75% random chance on Spike difficulty between  +- 10 to 30 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 87.5% random chance on Spike difficulty between  +- 2 to 10 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 98% random chance on Spike difficulty between +- 1 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 50 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }  
        // v1.12.x hard fork after block  3800810
        else if (pindex->nHeight > 3800810) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 20;
            unsigned int nCheetah = bnCheetah.GetCompact();

            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 500000000;
            unsigned int nSpike = bnSpike.GetCompact();

            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 40) || (pblock->nTime < pindexLast->nTime - 40))
            {
                // Return the last non-special-min-difficulty-rules-block

                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 30) || (pblock->nTime < pindexLast->nTime - 30))
            {
                // 50% random chance on Spike difficulty between  +- 30 to 40 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 10) || (pblock->nTime < pindexLast->nTime - 10))
            {
                // 75% random chance on Spike difficulty between  +- 10 to 30 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 87.5% random chance on Spike difficulty between  +- 2 to 10 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 98% random chance on Spike difficulty between +- 1 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 50 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }        
        // randomSpike fork after 10 emergency blocks on default litecoin style
        // v1.11.x hard fork after block  3539310 and fix 51% attack on SXC
        else if (pindex->nHeight > 3539310) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 21;
            unsigned int nCheetah = bnCheetah.GetCompact();

            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 500000000;
            unsigned int nSpike = bnSpike.GetCompact();

            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 40) || (pblock->nTime < pindexLast->nTime - 40))
            {
                // Return the last non-special-min-difficulty-rules-block

                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 30) || (pblock->nTime < pindexLast->nTime - 30))
            {
                // 50% random chance on Spike difficulty between  +- 30 to 40 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 10) || (pblock->nTime < pindexLast->nTime - 10))
            {
                // 75% random chance on Spike difficulty between  +- 10 to 30 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 87.5% random chance on Spike difficulty between  +- 2 to 10 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 98% random chance on Spike difficulty between +- 1 seconds

                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 50 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }        
       // Emergency hard fork after block  3539300
       // hard fork and fix 51% attack on SXC to new chain for 10 blocks on default litecoin style
        else if (pindex->nHeight > 3539300) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            unsigned int nCheetah = bnCheetah.GetCompact();

            return nCheetah;
        }
        // randomSpike fork after 1000 emergency blocks on default litecoin style
        // v1.10.x hard fork after block  3537500 and fix 51% attack on SXC
        else if (pindex->nHeight > 3537500) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 20;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 500000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 40) || (pblock->nTime < pindexLast->nTime - 40))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 30) || (pblock->nTime < pindexLast->nTime - 30))
            {
                // 50% random chance on Spike difficulty between  +- 30 to 40 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 10) || (pblock->nTime < pindexLast->nTime - 10))
            {
                // 75% random chance on Spike difficulty between  +- 10 to 30 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 87.5% random chance on Spike difficulty between  +- 2 to 10 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 98% random chance on Spike difficulty between +- 1 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 50 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }        
       // Emergency hard fork after block  3536500
       // hard fork and fix 51% attack on SXC to new chain for 1000 blocks on default litecoin style
        else if (pindex->nHeight > 3536500) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            return nCheetah;
        }
        // randomSpike fork after 1000 emergency blocks on default litecoin style
        // v1.9.x hard fork after block  3244060 and fix 51% attack on SXC
        else if (pindex->nHeight > 3244060) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 160;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 1000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 40) || (pblock->nTime < pindexLast->nTime - 40))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 30) || (pblock->nTime < pindexLast->nTime - 30))
            {
                // 50% random chance on Spike difficulty between  +- 30 to 40 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 10) || (pblock->nTime < pindexLast->nTime - 10))
            {
                // 75% random chance on Spike difficulty between  +- 10 to 30 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 87.5% random chance on Spike difficulty between  +- 2 to 10 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 98% random chance on Spike difficulty between +- 1 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 50 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }

       // Emergency hard fork after block  3243060
       // hard fork and fix 51% attack on SXC to new chain for 1000 blocks on default litecoin style
        else if (pindex->nHeight > 3243060) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 40000;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            return nCheetah;
        }
       // v1.7.0 randomSpike fork after block 2759040
       // fixed CPU+FPGA miner timestamp attack on shallow reset diff = 0.03 range
        else if (pindex->nHeight > 2759040) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 200;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 10000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 9) || (pblock->nTime < pindexLast->nTime - 9))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else
            {
                // randomSpike difficulty between +- 9 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
       // v1.6.0 randomSpike fork after block 2655920 
       // fixed big CPU miner timestamp attack
        else if (pindex->nHeight > 2655920) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 32;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 1000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 9) || (pblock->nTime < pindexLast->nTime - 9))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if  ((pblock->nTime > pindexLast->nTime - 2) && (pblock->nTime < pindexLast->nTime + 2))
            {
                // Spike difficulty
                return nSpike;
            }
            else
            {
                // randomSpike difficulty between 2 - 9 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
        // v1.5.0 hard fork after blocks 2354920
        else if (pindex->nHeight > 2354920) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 10;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 1000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if ((pblock->nTime > pindexLast->nTime + nTargetSpacing*2) || (pblock->nTime < pindexLast->nTime - nTargetSpacing*2))
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 9) || (pblock->nTime < pindexLast->nTime - 9))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if  ((pblock->nTime > pindexLast->nTime - 2) && (pblock->nTime < pindexLast->nTime + 2))
            {
                // Spike difficulty
                return nSpike;
            }
            else
            {
                // randomSpike difficulty between 2 - 9 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
        // v1.3.0 randomSpike fork after blocks 1303000
        else if (pindex->nHeight > 1303000) {
            if ((pblock->nTime > pindexLast->nTime + nTargetSpacing*2) || (pblock->nTime < pindexLast->nTime - nTargetSpacing*2))
                return nProofOfWorkLimit;
            else if  ((pblock->nTime > pindexLast->nTime + 9) || (pblock->nTime < pindexLast->nTime - 9))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nProofOfWorkLimit)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if  ((pblock->nTime > pindexLast->nTime - 2) && (pblock->nTime < pindexLast->nTime + 2))
            {
                // Spike difficulty
                arith_uint256 bnSpike;
                bnSpike = bnPowLimit;
                bnSpike /= 1000000000;
                return bnSpike.GetCompact();
            }
            else
            {
                // randomSpike difficulty between 2 - 9 seconds
                arith_uint256 bnSpike;
                bnSpike = bnPowLimit;
                bnSpike /= 1000000000;
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return bnSpike.GetCompact();
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nProofOfWorkLimit)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
        // v1.2.0 fork after blocks 273501
        // If the new block's timestamp is less than 3 seconds
        // then apply mining difficulty spike.
        else if (pindex->nHeight > 273500) {
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nProofOfWorkLimit;
            else if  (pblock->nTime > pindexLast->nTime + 3) 
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nProofOfWorkLimit)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else
            {
                // Spike difficulty
                arith_uint256 bnSpike;
                bnSpike = bnPowLimit;
                bnSpike /= 1000000000;
                return bnSpike.GetCompact();
            }
        }
        // v1.1.1 fork after blocks 94772
        else if (pindex->nHeight > 94771) {
            // If the new block's timestamp is more than 2 * 1 minutes
            // then allow mining of a min-difficulty block.
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nProofOfWorkLimit;
            else
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nProofOfWorkLimit)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
        }

        return pindexLast->nBits;
    }

    // Go back by what we want to be 14 days worth of blocks
    // Nengcoin: This fixes an issue where a 51% attack can change difficulty at will.
    // Go back the full period unless it's the first retarget after genesis. Code courtesy of Art Forz
    int blockstogoback = params.DifficultyAdjustmentInterval()-1;
    if ((pindexLast->nHeight+1) != params.DifficultyAdjustmentInterval())
        blockstogoback = params.DifficultyAdjustmentInterval();

    // Go back by what we want to be 14 days worth of blocks
    const CBlockIndex* pindexFirst = pindexLast;
    for (int i = 0; pindexFirst && i < blockstogoback; i++)
        pindexFirst = pindexFirst->pprev;

    assert(pindexFirst);

    return CalculateNextWorkRequired(pindexLast, pindexFirst->GetBlockTime(), params);
}

unsigned int CalculateNextWorkRequired(const CBlockIndex* pindexLast, int64_t nFirstBlockTime, const Consensus::Params& params)
{
    if (params.fPowNoRetargeting)
        return pindexLast->nBits;

    // Limit adjustment step
    int64_t nActualTimespan = pindexLast->GetBlockTime() - nFirstBlockTime;
    if (nActualTimespan < params.nPowTargetTimespan/4)
        nActualTimespan = params.nPowTargetTimespan/4;
    if (nActualTimespan > params.nPowTargetTimespan*4)
        nActualTimespan = params.nPowTargetTimespan*4;

    // Retarget
    arith_uint256 bnNew;
    arith_uint256 bnOld;
    bnNew.SetCompact(pindexLast->nBits);
    bnOld = bnNew;
    // Nengcoin: intermediate uint256 can overflow by 1 bit
    bool fShift = bnNew.bits() > 235;
    if (fShift)
        bnNew >>= 1;
    bnNew *= nActualTimespan;
    bnNew /= params.nPowTargetTimespan;
    if (fShift)
        bnNew <<= 1;

    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    if (bnNew > bnPowLimit)
        bnNew = bnPowLimit;

    return bnNew.GetCompact();
}

bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    bool fNegative;
    bool fOverflow;
    arith_uint256 bnTarget;

    bnTarget.SetCompact(nBits, &fNegative, &fOverflow);

    // Check range
    if (fNegative || bnTarget == 0 || fOverflow || bnTarget > UintToArith256(params.powLimit))
        return false;

    // Check proof of work matches claimed amount
    if (UintToArith256(hash) > bnTarget)
        return false;

    return true;
}
