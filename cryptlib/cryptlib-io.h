//
// Created by GROSA5 on 2/5/2021.
//

#ifndef CRYPT_TOOL_CRYPTLIB_IO_H
#define CRYPT_TOOL_CRYPTLIB_IO_H

void catchMemoryAllocationFailure(void *);

void readBinDataFromFile(char *, char **, int *);

void writeBinDataToFile(char *, char *, int);

#endif //CRYPT_TOOL_CRYPTLIB_IO_H
