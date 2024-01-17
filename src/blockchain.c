#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "blockchain.h"
#define HASH_LENGTH 64
#define TARGET_DIFFICULTY 4  
#define MAX_NONCE 1000000   


struct Block* createBlock(uint32_t index, char* data, char* prevHash) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    if (newBlock == NULL) {
        printf("Memory allocation failed for a new block\n");
        return NULL;
    }

    newBlock->index = index;
    newBlock->timestamp = time(NULL);
    strcpy(newBlock->data, data);
    strcpy(newBlock->prevHash, prevHash);
    newBlock->nonce = 0; // Initialize nonce to zero for mining
    strcpy(newBlock->hash, calculateHash(newBlock));

    return newBlock;
}

struct Block *createGenesisBlock() {
    struct Block *genesisBlock = (struct Block *)malloc(sizeof(struct Block));

    if (genesisBlock == NULL) {
        printf("Memory allocation failed for the genesis block.\n");
        return NULL;
    }

    // Initialize values for the genesis block
    genesisBlock->index = 0;
    genesisBlock->timestamp = time(NULL);
    strncpy(genesisBlock->data, "Genesis Block", sizeof(genesisBlock->data));
    strncpy(genesisBlock->prevHash, "0", sizeof(genesisBlock->prevHash));
    strcpy(genesisBlock->hash,calculateHash(genesisBlock));
    genesisBlock->nonce= 0;
    genesisBlock->next = NULL;
    printf("created successfuly\n");
    return genesisBlock;
}

// Function to insert a block into the blockchain
void insertBlock(struct Block* blockchain, struct Block* newBlock) {
    
    if (blockchain==NULL || newBlock==NULL)
    {
        printf("Invalid Blockchain\n");
        return;
    }

    struct Block* current = blockchain; 
    while(current->next != NULL)
        current=current->next;
    
    current->next=newBlock;
    newBlock->next=NULL;
    
    printf("Block instrted \n");
}

// Function to calculate hash of a block (sample implementation, not real hashing)
char* calculateHash(struct Block* block) {
    char* hash = (char*)malloc(sizeof(char) * (HASH_LENGTH + 1)); // Assuming HASH_LENGTH is defined
    // Sample hash calculation (e.g., concatenation of block data)
    sprintf(hash, "%d%s%s%d", block->index, block->data, block->prevHash, block->nonce);
    return hash;
}

struct Block* mineBlock(struct Block* block) {
    // Initialize variables
    char difficultyPattern[TARGET_DIFFICULTY + 1];
    memset(difficultyPattern, '0', TARGET_DIFFICULTY);
    difficultyPattern[TARGET_DIFFICULTY] = '\0';

    int nonce = 0;

    // Mine the block until a valid hash is found
    while (nonce <= MAX_NONCE) {
        block->nonce = nonce;
        char* hash = calculateHash(block);

        if (strncmp(hash, difficultyPattern, TARGET_DIFFICULTY) == 0) {
            // Valid hash found, block mined
            printf("Block mined! Hash: %s\n", hash);

            // Update the block's hash
            strncpy(block->hash, hash, sizeof(block->hash));
            free(hash);

            return block;
        }

        free(hash);
        nonce++;
    }

    printf("Mining unsuccessful.\n");
    return NULL;
}


// Function to validate the integrity of the blockchain
int validateChain(struct Block* chain) {
    struct Block* current = chain;
    struct Block* prev = NULL;

    while (current != NULL) {
        if (prev != NULL && strcmp(current->prevHash, calculateHash(prev)) != 0) {
            return 0; // Invalid chain if hashes don't match
        }
        prev = current;
        current = current->next;
    }
    return 1; // Valid chain
}

// Function to display the entire blockchain
void displayBlockchain(struct Block* chain) {
    struct Block* current = chain;
    while (current != NULL) {
        printf("Index: %d\n", current->index);
        printf("Timestamp: %ld\n", current->timestamp);
        printf("Data: %s\n", current->data);
        printf("Previous Hash: %s\n", current->prevHash);
        printf("Nonce: %d\n", current->nonce);
        printf("Hash: %s\n", current->hash);
        printf("\n");
        current = current->next;
    }
}
