#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cryptlib.h"
#include "crypt-permutation.h"
#include "crypt-translate.h"

cryptData *encryptBinDataInMemory(char *key, size_t len, void *binData) {
    void *permutedData = permute(binData, key, len);
    void *translatedData = translate(permutedData, key, len);
//    free(permutedData);
    cryptData *data = malloc(sizeof(cryptData));
    data->binData = translatedData;
    data->len = len;
    return data;
}

cryptData *decryptBinDataInMemory(char *key, size_t len, void *binData) {
    void *untranslatedData = untranslate(binData, key, len);
    void *unpermutedData = unpermute(untranslatedData, key, len);
//    free(unpermutedData);
    cryptData *data = malloc(sizeof(cryptData));
    data->binData = unpermutedData;
    data->len = len;
    return data;
}

void encrypt(char *masterKey, char *pathToFile) {
    char *newFile = "C:\\crypt\\newfile.encrypted";
    //strcat(pathToFile, "_encrypted");
    int sizeData = 0;
    char *inputData = NULL;
    //read file
    readBinDataFromFile(pathToFile, &inputData, &sizeData);

    //Key stuff
    int sizeKey = 0;
    char *keyContent = NULL;
    getContentOfKey(masterKey, &sizeKey, &keyContent);


    //encrypt data
    cryptData *encryptedBinData;
    encryptedBinData = encryptBinDataInMemory(keyContent, sizeData, inputData);

    //write new file
    char *encryptedData = encryptedBinData->binData;
    int sizeEncryptedData = encryptedBinData->len;
    writeBinDataToFile(newFile, encryptedData, sizeEncryptedData);

    //Clearing Memory
    free(inputData);
    free(encryptedData);
    free(keyContent);
}

void decrypt(char *masterKey, char *pathToFile) {

}

//ToDo create function to create magickey

void getContentOfKey(const char *masterKeyPath, int *size, char **masterKeyContent) {
    FILE *pFile;

    //ToDo maybe change to text mode
    pFile = fopen(masterKeyPath, "rb");

    if (pFile == NULL) {
        printf((const char *) stderr, "Could not open key file...");
    } else {
        fseek(pFile, 0, SEEK_END);
        int fileSize = ftell(pFile);
        *size = fileSize;
        *masterKeyContent = malloc(fileSize);
        rewind(pFile);
        while (!feof(pFile)) {
            fread(*masterKeyContent, fileSize, 1, pFile);
        }
    }
    fclose(pFile);
}