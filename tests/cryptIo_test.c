#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cryptlib/cryptlib-io.h"

void readTest();
void writeTest();

//Testing Variables
char *pathToKey = "C:\\crypt\\key.dat";
char *file = "C:\\crypt\\testfile.blub";
char *newFile = "C:\\crypt\\newfile.bin";

int main() {
    printf("-------- CryptIo Tests --------\n");
    readTest();
    writeTest();
}

void readTest() {
    printf("  --- Test Read Function ---\n");
    char *data = NULL;
    int size = 0;
    readBinDataFromFile(file, &data, &size);
    printf("Content of file:\n");
    for (int i = 0; i < size; i++) {
        printf("%c", data[i]);
    }
    printf("\n");
    printf("Size: %d\n", size);
    free(data);
}

void writeTest() {
    printf("  --- Test Read Function ---\n");
    char *test = "test";
    writeBinDataToFile(newFile, test, strlen(test));
}