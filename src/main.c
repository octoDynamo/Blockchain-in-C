# Blockchain Simulation in C

This project is a simple blockchain simulation implemented in the C programming language. It aims to demonstrate the fundamental concepts of blockchain technology and how transactions are added to blocks and then chained together to form a secure and immutable ledger.

## Features

- **Block Structure:** Each block contains a list of transactions, a timestamp, and a hash value.
- **Blockchain Implementation:** The blockchain is implemented as a linked list of blocks.
- **Proof of Work:** Blocks are mined using a simple proof-of-work algorithm.
- **Transaction Validation:** Transactions are validated before being added to a block.
- **Hashing:** SHA-256 hashing algorithm is used to secure the integrity of blocks and transactions.

## Getting Started

To compile and run the blockchain simulation, follow these steps:

1. Clone this repository to your local machine:

    ```
    git clone https://github.com/your-username/blockchain-simulation.git
    ```

2. Navigate to the project directory:

    ```
    cd blockchain-simulation
    ```

3. Compile the source code:

    ```
    gcc -o blockchain blockchain.c -lm
    ```

4. Run the simulation:

    ```
    ./blockchain
    ```

## Usage

Once the simulation is running, you can interact with it using simple commands:

- `add_transaction`: Add a new transaction to the blockchain.
- `mine_block`: Mine a new block containing pending transactions.
- `display_chain`: Display the entire blockchain.

## Example

Here is an example of how to use the simulation:

```c
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

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

