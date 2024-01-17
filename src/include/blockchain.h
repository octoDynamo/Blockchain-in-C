#ifndef blockchain_h
#define blockchain_h

#include <stdint.h>
#include <time.h>

struct Block {
    uint32_t index;
    time_t timestamp;
    char data[255];     // Placeholder for block data;
    char prevHash[65];  // Hash of the previous block
    char hash[65];      // Hash of the current block
    uint32_t nonce;     // Nonce for proof of work
    struct Block* next; // Pointer to the next block
};

char* calculateHash(struct Block* block);
struct Block* createBlock(uint32_t index, char* data, char* prevHash);
struct Block *createGenesisBlock();
void insertBlock(struct Block* blockchain, struct Block* newBlock);
int validateChain(struct Block* chain);
void displayBlockchain(struct Block* chain);
struct Block* mineBlock(struct Block* block);

#endif