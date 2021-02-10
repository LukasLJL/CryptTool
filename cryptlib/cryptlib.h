//
// Created by GROSA5 on 2/7/2021.
//

#ifndef CRYPT_TOOL_CRYPTLIB_H
#define CRYPT_TOOL_CRYPTLIB_H

void encrypt_test(char *key, char *path, void *algorithm(char *));
void decrypt_test(char *key, char *path, void *algorithm(char *));

void encrypt(char *key, char *path);
void decrypt(char *key, char *path);

// internal prototypes
void *toCrypt(char *key, size_t len, void *binData);
void *fromCrypt(char *key, size_t len, void *binData);

#endif //CRYPT_TOOL_CRYPTLIB_H
