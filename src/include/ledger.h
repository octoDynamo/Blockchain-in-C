#ifndef LEDGER_H
#define LEDGER_H

#include "blockchain.h" // Include blockchain.h for Block structure
#include <stdint.h>
#include <time.h>

#define FILENAME "blockchain_ledger.bin" // Example ledger file name

// Structure to represent a ledger entry
struct LedgerEntry {
    uint32_t blockIndex;      
    time_t blockTimestamp;   
    char blockData[255];      
    char blockPrevHash[65];  
    char blockHash[65];       
    uint32_t blockNonce;      
};

int writeBlockchainToLedger(struct Block* chain,const char* FILENMAE) ;
struct Block* readBlockchainFromLedger(const char* fileName);

#endif
