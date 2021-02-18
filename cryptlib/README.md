## Cryptlib

#### Overview
This Project relies on a custom encryption library to handle its files and the encryption thereof
Functionality:
- The core encryption algorithm is built from two dependencies
    1. a permutation cypher
    2. a translation cypher
- The interface of the library contains internal memory encryption and external file encryption methods to handle different streams of data

#### Permutation cypher
Goal the permutation cypher is to take in blocks of bytes and rearage them in a pattern, that is reproducable (when the key is known) and differs for every keyset as much as possible
- Sample Transformation (Before)

 data | A  | B  | C  | D   
------|----|----|----|---
1     | 1  | 2  | 3  | 4
2     | 5  | 6  | 7  | 8
3     | 9  | 10 | 11 | 12
4     | 13 | 14 | 15 | 16

- Sample Transformation (After)

data | A  | B  | C  | D   
-----|----|----|----|---
1    | 7  | 12 | 3  | 6
2    | 15 | 5  | 2  | 8
3    | 9  | 13 | 11 | 14
4    | 4  | 10 | 16  | 1

This is done by spliting the file up into 16 byte blocks, hashing the key, creating an offset cypher and repeatedly applying different offsets to all rows and collumns of each block. Given that a file does not fit into a block, the remaining bytes that would be needed are assumed to be NULL bytes and are eventually removed during decryption.
The reversal simply takes the same algorithm and applies it in reverse order.

#### Translation cypher
Goal of the translation cypher is to take and map certain bytes to other reproducable patterns (and back).
This is done in a comparatively primitive manner, taking the raw value of bytes and computing what that would result to after adding a certain key-specific offset to it.
Example:
- 00 -> 0f
- 01 -> 11
- etc.

#### Usage
To use the library, four functions are given
- ``void encrypt(char *key, char *path);``
- ``void decrypt(char *key, char *path);``
- ``cryptData *encryptBinDataInMemory(char *key, size_t len, void *binData);``
- ``cryptData *decryptBinDataInMemory(char *key, size_t len, void *binData);``
The last two directly work with binary data in memory, returning a copy of the data given in it's encrypted form and new length (if needed).
The first two then implement this function and abstract away file handling and other IO needed to decrypt and encrypt a certain file at some path.
