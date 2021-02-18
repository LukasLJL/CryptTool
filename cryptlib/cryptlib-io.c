#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

char *getNewEncryptedFileName(char *pathToFile) {
    char *newName = ".encrypted";
    char *newFile = malloc(sizeof(char) * 256);
    strcpy(newFile, pathToFile);
    strcat(newFile, newName);
    return newFile;
}

char *getNewDecryptedFileName(char *pathToFile) {
    int size = (int) strlen(pathToFile);
    char *newFolderName = "decrypted";
    char *newFileName = (char *) malloc(size);
    char *newPath = (char *) malloc(sizeof(char) * 512);
    int lastSlash = 0;
    int lastDot = 0;

    if (strcmp(getOSTyp(), "Windows") == 0) {
        for (int i = 0; i < size; i++) {
            if (pathToFile[i] == '\\') {
                lastSlash = i;
            }
            if (pathToFile[i] == '.') {
                lastDot = i;
            }
        }
    } else if (strcmp(getOSTyp(), "Linux") == 0) {
        for (int i = 0; i < size; i++) {
            if (pathToFile[i] == '/') {
                lastSlash = i;
            }
            if (pathToFile[i] == '.') {
                lastDot = i;
            }
        }
    }

    //clearing strings
    memset(newFileName, 0, sizeof(char));
    memset(newPath, 0, sizeof(char));

    strncat(newFileName, pathToFile, lastDot);
    strncat(newPath, pathToFile, lastSlash);
    createNewFolder(newPath, newFolderName);
    if (strcmp(getOSTyp(), "Windows") == 0) strcat(newPath, "\\");
    if (strcmp(getOSTyp(), "Linux") == 0) strcat(newPath, "/");
    strcat(newPath, newFolderName);
    strcat(newPath, newFileName + lastSlash);

    free(newFileName);
    return newPath;
}

void createNewFolder(char *currentPath, char *folderName) {
    char *command = (char *) malloc(sizeof(char) * 256);
    memset(command, 0, sizeof(char));

    strcat(command, "cd ");
    strcat(command, currentPath);

    strcat(command, " && ");

    if (strcmp(getOSTyp(), "Windows") == 0) {
        strcat(command, "md ");
        strcat(command, folderName);
        strcat(command, " >nul 2>&1");
    } else if (strcmp(getOSTyp(), "Linux") == 0) {
        strcat(command, "mkdir ");
        strcat(command, folderName);
        strcat(command, " >/dev/null 2>&1");
    }
    system(command);
    free(command);
}

void generateKeyFile(char *keyPath) {
    FILE *keyFile = fopen(keyPath, "w");
    srand(time(NULL));
    fprintf(keyFile, "hereIsYourKey%d", rand());
    fclose(keyFile);
}

int getRealLength(void *data, int origSize) {
    int calcSize = 0;
    char *tempData = data;

    for (int i = origSize; i > 0; i--) {
        if (tempData[i] == '\0') {
            calcSize++;
        } else{
            break;
        }
    }

    if (calcSize > 1) {
        return origSize - calcSize + 1;
    }
}