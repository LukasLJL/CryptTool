#include <stdio.h>

char *getOSTyp();

void listAllDrives() {
    printf("OS-Typ: %s\n", getOSTyp());

}

char *getMasterKeyPath() {

}

char *getOSTyp() {
#ifdef __linux
    return "Linux";
#elif _WIN64
    return "Windows";
#else
    return "Unkown";
#endif
}