#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

// Include your blockchain-related headers here
#include "blockchain.c"

int main(int argc, char const *argv[]) {

    struct Block* genesis = createGenesisBlock();

    struct Block* newBlock1 = createBlock(1,"data1",genesis->hash);
    struct Block* newBlock2 = createBlock(2,"data2",newBlock1->hash);
    struct Block* newBlock3 = createBlock(3,"data3",newBlock2->hash);

    insertBlock(genesis,newBlock1);
    insertBlock(genesis,newBlock2);
    insertBlock(genesis,newBlock3);

    struct Block* newBlock4 = createBlock(4,"data4",newBlock3->hash);;
    mineBlock(newBlock4);
    insertBlock(genesis,newBlock4);

    displayBlockchain(genesis);

    return 0;
}