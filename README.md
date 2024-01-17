Simple Blockchain Simulation Project
This C project simulates a simple blockchain using linked lists. The project structure is organized into several files, each handling different aspects of the simulatio

Step 1: Set Up the Project

    Create a new C project with the following folders and files: src, include.
    Project structure includes main.c, linkedlist.c, linkedlist.h, blockchain.c, blockchain.h, ledger.c, and ledger.h.

Step 2: Implement Linked List

    Define a linked list node structure in linkedlist.h with data and a pointer to the next node.
    Implement basic linked list operations in linkedlist.c such as createNode, insertNode, deleteNode, and displayList.

Step 3: Implement Blockchain Structure

    Define a blockchain node structure in blockchain.h with data like block index, timestamp, data, hash, nonce, and a pointer to the next block.
    Implement basic blockchain operations in blockchain.c such as createBlock, insertBlock, mineBlock, validateChain, and displayBlockchain.

Step 4: Block Hashing

    Implement a hashing function in blockchain.c to calculate the hash of a block based on its data, nonce, and the previous block's hash.
    Ensure each block in the blockchain contains its hash, nonce, and the hash of the previous block.

Step 5: Blockchain Initialization

    Implement a function in blockchain.c to initialize the blockchain with the genesis block (the first block in the blockchain).

Step 6: Mining New Blocks

    Create a function in blockchain.c that simulates the mining process to find a valid hash satisfying certain criteria for a new block.
    Update the mineBlock function to incorporate the mining process.

Step 7: Display Blockchain Information

    Implement a function to display information about the entire blockchain, including each block's index, timestamp, data, nonce, and hash.

Step 8: Validation

    Implement a function to validate the integrity of the blockchain by checking if the hash of each block matches the hash stored in the next block.

Step 9: Saving Blockchain to Binary Ledger

    Define a structure for a ledger entry in ledger.h, which includes block information.
    Implement functions in ledger.c to write and read the blockchain to/from a binary ledger file.

Step 10: Testing

    Write a main function in main.c to test the implemented linked list, blockchain, mining, validation, and ledger functionalities.
    Demonstrate the creation of the blockchain, mining of new blocks, validation of the blockchain, and saving/loading the blockchain to/from a binary ledger.

Feel free to customize and extend the functionalities based on your requirements.
