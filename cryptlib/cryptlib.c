#include <stdlib.h>
#include <string.h>
#include "cryptlib.h"
#include "crypt-permutation.h"
#include "crypt-translate.h"

cryptData *encryptBinDataInMemory(char *key, size_t len, void *binData) {
    void *permutedData = permute(binData, key, len);
    len = len  + (16 - ((len % 16)) % 16);
    void *translatedData = translate(permutedData, key, len);
    // free(permutedData);
    cryptData *data = malloc(sizeof(cryptData));
    data->binData = translatedData;
    data->len = len;
    return data;
}

cryptData *decryptBinDataInMemory(char *key, size_t len, void *binData) {
    void *untranslatedData = untranslate(binData, key, len);
    void *unpermutedData = unpermute(untranslatedData, key, len);
    // free(unpermutedData);
    cryptData *data = malloc(sizeof(cryptData));
    data->binData = unpermutedData;
    data->len = len;
    return data;
}

void encrypt(char *masterKey, char *pathToFile) {
    char *newFile = getNewEncryptedFileName(pathToFile);
    int sizeData = 0;
    char *inputData = NULL;
    //read file
    readBinDataFromFile(pathToFile, &inputData, &sizeData);

    //Key stuff
    int sizeKey = 0;
    char *keyContent = NULL;
    readBinDataFromFile(masterKey, &keyContent, &sizeKey);

    //encrypt data
    cryptData *encryptedBinData;
    encryptedBinData = encryptBinDataInMemory(keyContent, sizeData, inputData);

    //write new file
    writeBinDataToFile(newFile, encryptedBinData->binData, encryptedBinData->len);

    //Clearing Memory
    free(inputData);
    free(encryptedBinData);
    free(keyContent);
    free(newFile);
}

void decrypt(char *masterKey, char *pathToFile) {
    char *newFile =getNewDecryptedFileName(pathToFile);
    int sizeData = 0;
    char *inputData = NULL;

    //read file
    readBinDataFromFile(pathToFile, &inputData, &sizeData);

    //Key stuff
    int sizeKey = 0;
    char *keyContent = NULL;
    readBinDataFromFile(masterKey, &keyContent, &sizeKey);

    //decrypt data
    cryptData *decryptedBinData;
    decryptedBinData = decryptBinDataInMemory(keyContent, sizeData, inputData);

    //write new file
    writeBinDataToFile(newFile, decryptedBinData->binData, decryptedBinData->len);

    //Clearing Memory
    free(inputData);
    free(decryptedBinData);
    free(keyContent);
    free(newFile);
}

