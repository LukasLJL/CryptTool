# CryptTool

## Contents
- [CryptTool](#crypttool)
- [Requirements](#requirements)
- [Features](#features)
- [User Documentation](#user-documentation)
- [Developer Documentation](#developer-documentation)

## Requirements
- OS: Linux or Windows
- For Development purpose IDE: CLion
- Enough RAM to Encrypt or Decrypt

## Features
- Detect all mounted drives on Windows
- Detect all mounted drives at ``/mnt/..`` on Linux
- Encrypt with a generated Key
- Decrypt with a generated Key

## User Documentation 
User Documentation

Our CryptTool has the functionality to en- and decrypt files. How you can use it or achive it, we describe in the following:

1. 	As you start the program. The user gets an overview of his drives. Our user can choose between three options:

      - 1st: You want to encrypt a file.

      - 2nd: You want to decrypt a file.

      - 3rd: You want to create a key for the en- or decryption.


2. 	Afterwards the program need to know, in which drive you want to save/decrypt/encrypt your file.


3. 	Also, its necessary to tell the program in which path your file is saved or want to be saved. For example: C:\CryptTool\BEISPIELDATEI.TXT
      
      - Be aware not to type double slash instead of a single one.


4.  Its important to mention that, if you want to create a key, you have to create an folder by yourself and name it "CryptTool". And at the time you create the key, you have to put it inside the "CryptTool" folder.



## Developer Documentation
We have a documentation for every part of the CryptTool program
- [DriveSelector](https://github.com/LukasLJL/CryptTool/blob/master/src/README.md)
- [CryptLib](https://github.com/LukasLJL/CryptTool/blob/master/cryptlib/README.md)
