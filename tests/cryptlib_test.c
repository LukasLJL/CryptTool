#include <stdio.h>
#include "../cryptlib/cryptlib.h"

#define PATH_TO_KEY "C:\\crypt\\key.dat"
#define FILE_TO_ENCRYPT "C:\\crypt\\IMG_1402_edit.jpg"
#define FILE_TO_DECRYPT "C:\\crypt\\IMG_1402_edit.jpg.encrypted"


int main() {
    encrypt_test(PATH_TO_KEY, FILE_TO_ENCRYPT, (void *(*)(char *)) "0");
    decrypt_test(PATH_TO_KEY, FILE_TO_DECRYPT, (void *(*)(char *)) "0");
}

void encrypt_test(char *key, char *path, void *algorithm(char *)) {
    encrypt(key, path);
}

void decrypt_test(char *key, char *path, void *algorithm(char *)) {
    decrypt(key, path);
}
