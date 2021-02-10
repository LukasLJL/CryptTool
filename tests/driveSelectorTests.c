#include <stdio.h>
#include "../src/driveSelector.h"
#include <string.h>
#define keyPathSize 300

int main() {
    //Just for testing purpose, you can ignore that lol
    int numberOfDrives = getNumberOfDrives();
    //Where DriveList is saved
    char test[numberOfDrives][20];
    //Where the path to the key is saved
    char paths[keyPathSize];
    getAllDrives(test);
    for (int i = 0; i < numberOfDrives; i++) {
        //Print DriveLetters test
        for (int k = 0; k < strlen(test[numberOfDrives]); k++) {
            printf("%c", test[i][k]);
        }
        printf("\n");
        //get path for masterkey just input the drive and where the path should be saved
        getMasterKeyPath(test[i], paths);
        printf("%s\n", paths);
    }

}
