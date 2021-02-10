//
// Created by GROSA5 on 2/10/2021.
//

#include <stdlib.h>
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