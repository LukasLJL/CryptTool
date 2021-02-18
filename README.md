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

Our CryptTool has the functionality to en- and decrypt files. How you can use it or achieve it, we describe in the following:

1. 	As you start the program.  Our user can choose between four options:

      - 1st: You want to encrypt a file.

      - 2nd: You want to decrypt a file.

      - 3rd: You want to create a key for the en- or decryption.
        
      - 4th: Exit Tool
      
2. After that the user gets an overview of his drives. The user have to chose a drive, on which his Decrypt/Encrypt Key is stored.
   
3. Also, its necessary to tell the program in which path your file is saved. For example: ``C:\CryptTool\ImportantDocument.txt``
      
      - Be aware not to type double slash instead of a single one.
      
4.1 On encrypt mode, an encrypted file will be created with the file extension .encrypted <br>
4.2 On decrypt mode, a new folder will be created with the name "Decrypted", where the decrypted file is then located


## Developer Documentation
We have a documentation for every part of the CryptTool program
- [DriveSelector](https://github.com/LukasLJL/CryptTool/blob/master/src/README.md)
- [CryptLib](https://github.com/LukasLJL/CryptTool/blob/master/cryptlib/README.md)

Build and installation instructions
- Option A: in CLion press refresh cmake-lists choose main from run configs to run
- Option B: 
	1. make sure you have cmake installed on your machine
	2. from the root directory run ``cmake --build ".\cmake-build-debug" --target main -- -j 6``
	3. run ``.\cmake-build-debug\src\main.exe``
