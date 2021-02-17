#include <stdio.h>
#include "../cryptlib/cryptlib.h"

#ifdef __linux
#define PATH_TO_KEY "/mnt/c/crypt/key.dat"
#define FILE_TO_ENCRYPT "/mnt/c/crypt/test.txt"
#define FILE_TO_DECRYPT "/mnt/c/crypt/test.txt.encrypted"
#elif _WIN64 || __WIN32
#define PATH_TO_KEY "C:\\crypt\\key.dat"
#define FILE_TO_ENCRYPT "C:\\crypt\\test.txt"
#define FILE_TO_DECRYPT "C:\\crypt\\test.txt.encrypted"
#endif

int main() {
    //generateKeyFile(PATH_TO_KEY);
    encrypt_test(PATH_TO_KEY, FILE_TO_ENCRYPT, (void *(*)(char *)) "0");
    decrypt_test(PATH_TO_KEY, FILE_TO_DECRYPT, (void *(*)(char *)) "0");
}

void encrypt_test(char *key, char *path, void *algorithm(char *)) {
    encrypt(key, path);
}

void decrypt_test(char *key, char *path, void *algorithm(char *)) {
    decrypt(key, path);
}
