#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cryptlib/cryptlib-io.h"


#ifdef __linux
#define PATH_TO_KEY "/mnt/c/crypt/key.dat"
#define FILE "/mnt/c/crypt/testfile.blub"
#define NEW_FILE "/mnt/c/crypt/newfile.bin"
#elif _WIN64 || _WIN32
#define PATH_TO_KEY "C:\\crypt\\key.dat"
#define FILE "C:\\crypt\\testfile.blub"
#define NEW_FILE "C:\\crypt\\newfile.bin"
#endif

void readTest();
void writeTest();

int main() {
    printf("-------- CryptIo Tests --------\n");
    readTest();
    writeTest();
}

void readTest() {
    printf("  --- Test Read Function ---\n");
    char *data = NULL;
    int size = 0;
    readBinDataFromFile(FILE, &data, &size);
    printf("Content of file:\n");
    for (int i = 0; i < size; i++) {
        printf("%c", data[i]);
    }
    printf("\n");
    printf("Size: %d\n", size);
    free(data);
}

void writeTest() {
    printf("  --- Test Write Function ---\n");
    char *test = NULL;
    int size = 0;
    readBinDataFromFile(FILE, &test, &size);
    writeBinDataToFile(NEW_FILE, test, size);
}