#ifndef CRYPT_TOOL_CRYPTLIB_IO_H
#define CRYPT_TOOL_CRYPTLIB_IO_H
#include "cryptlib-osHandling.h"

void catchMemoryAllocationFailure(void *);

void readBinDataFromFile(char *, char **, int *);

void writeBinDataToFile(char *, char *, int);

char *getNewEncryptedFileName(char *);

char *getNewDecryptedFileName(char *);

void createNewFolder(char *, char *);

#endif //CRYPT_TOOL_CRYPTLIB_IO_H
