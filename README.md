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
    git clone https://github.com/octoDynamo/Blockchain-in-C
    ```

2. Navigate to the project directory:

    ```
    cd Blockchain-in-C
    ```

3. Compile the source code:

    ```
    gcc -o blockchain main.c -lm
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


## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

###### rr3ed