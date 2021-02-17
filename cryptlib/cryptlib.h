//
// Created by GROSA5 on 2/7/2021.
//

#ifndef CRYPT_TOOL_CRYPTLIB_H

#include "cryptlib-io.h"
#include <stdlib.h>

#define CRYPT_TOOL_CRYPTLIB_H

void encrypt_test(char *key, char *path, void *algorithm(char *));

void decrypt_test(char *key, char *path, void *algorithm(char *));

// internal prototypes
typedef struct {
    void *binData;
    size_t len;
} cryptData;

void encrypt(char *key, char *path);

void decrypt(char *key, char *path);

cryptData *encryptBinDataInMemory(char *key, size_t len, void *binData);

cryptData *decryptBinDataInMemory(char *key, size_t len, void *binData);

#endif //CRYPT_TOOL_CRYPTLIB_H
