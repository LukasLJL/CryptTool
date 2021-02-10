#include <stdio.h>
#include "../cryptlib/cryptlib.h"


int main() {
    char *pathToKey = "C:\\crypt\\key.dat";
    char *file = "C:\\crypt\\testfile.blub";
    encrypt(pathToKey, file);
}
