#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ledger.h"

// Function to write blockchain to a binary ledger file
int writeBlockchainToLedger(struct Block* chain,const char* FILENMAE) {
    FILE *file = fopen(FILENAME, "wb"); // Open file for writing in binary mode

    if (file == NULL) {
        printf("Error opening ledger file for writing.\n");
        return 0; // Return 0 to indicate failure
    }

    struct Block* currentBlock = chain;

    while (currentBlock != NULL) {
        struct LedgerEntry entry;
        entry.blockIndex = currentBlock->index;
        entry.blockTimestamp = currentBlock->timestamp;
        strncpy(entry.blockData, currentBlock->data, sizeof(entry.blockData));
        strncpy(entry.blockPrevHash, currentBlock->prevHash, sizeof(entry.blockPrevHash));
        strncpy(entry.blockHash, currentBlock->hash, sizeof(entry.blockHash));
        entry.blockNonce = currentBlock->nonce;

        // Write the ledger entry to the file
        fwrite(&entry, sizeof(struct LedgerEntry), 1, file);

        currentBlock = currentBlock->next;
    }

    fclose(file);
    printf("Blockchain written to ledger file successfully.\n");
    return 1; // Return 1 to indicate success
}

// Function to read blockchain from a binary ledger file
struct Block* readBlockchainFromLedger(const char* fileName) {
    FILE* file = fopen(fileName, "rb"); // Open file for reading in binary mode

    if (file == NULL) {
        printf("Error opening ledger file for reading.\n");
        return NULL; // Return NULL to indicate failure
    }

    struct Block* blockchain = NULL;
    struct Block* currentBlock = NULL;

    // Read entries from the file in a loop
    while (1) {
        struct LedgerEntry entry;

        // Read the ledger entry from the file
        size_t bytesRead = fread(&entry, sizeof(struct LedgerEntry), 1, file);

        if (bytesRead != 1) {
            // Break the loop if reading is not successful
            break;
        }

        // Allocate memory for a new block
        struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));

        // Populate the new block with data from the ledger entry
        newBlock->index = entry.blockIndex;
        newBlock->timestamp = entry.blockTimestamp;
        strncpy(newBlock->data, entry.blockData, sizeof(newBlock->data));
        strncpy(newBlock->prevHash, entry.blockPrevHash, sizeof(newBlock->prevHash));
        strncpy(newBlock->hash, entry.blockHash, sizeof(newBlock->hash));
        newBlock->nonce = entry.blockNonce;
        newBlock->next = NULL;

        // Link the new block to the blockchain
        if (blockchain == NULL) {
            blockchain = newBlock;
            currentBlock = newBlock;
        } else {
            currentBlock->next = newBlock;
            currentBlock = newBlock;
        }
    }

    fclose(file);
    return blockchain;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}