#include <stdio.h>
#include <stdlib.h>
#include "cryptlib-io.h"

void catchMemoryAllocationFailure(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "criptlib: memory allocation failed");
        exit(1);
    }
}

void readBinDataFromFile(char *pathToFile, char **data, int *size) {
    FILE *pFile;
    int fileContentSize;

    //reads file in binary mode
    pFile = fopen(pathToFile, "rb");

    //reads content of file
    if (pFile == NULL) {
        printf((const char *) stderr, "Could not open source file...");
    } else {
        //get size of file content
        fseek(pFile, 0, SEEK_END);
        fileContentSize = ftell(pFile);
        *size = fileContentSize;
        *data = malloc(fileContentSize);
        //reset pos of file
        rewind(pFile);
        //loop through the file
        while (!feof(pFile)) {
            fread(*data, fileContentSize, 1, pFile);
        }
        fclose(pFile);
    }
}

void writeBinDataToFile(char *pathToFile, char *data, int size) {
    FILE *pFile;

    //write new file in binary mode
    pFile = fopen(pathToFile, "wb");

    if (pFile == NULL) {
        printf((const char *) stderr, "Could not write new file...");
    } else {
        fwrite(data, size, 1, pFile);
        rewind(pFile);
    }
    fclose(pFile);
}