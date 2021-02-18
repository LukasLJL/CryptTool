#include <stdio.h>
#include "driveSelector.h"
#include <string.h>
#include "../cryptlib/cryptlib-io.h"
#include "../cryptlib/cryptlib.h"
#include "main.h"

int main(void) {
    //Start screen
    printf(" ________  ________      ___    ___ ________  _________  ________  ________  ___   \n");
    printf("|\\   ____\\|\\   __  \\    |\\  \\  /  /|\\   __  \\|\\___   ___\\\\   __  \\|\\   __  \\|\\  \\         \n");
    printf("\\ \\  \\___|\\ \\  \\|\\  \\   \\ \\  \\/  / | \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\        \n");
    printf(" \\ \\  \\    \\ \\   _  _\\   \\ \\    / / \\ \\   ____\\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\       \n");
    printf("  \\ \\  \\____\\ \\  \\\\  \\|   \\/  /  /   \\ \\  \\___|    \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\____ \n");
    printf("   \\ \\_______\\ \\__\\\\ _\\ __/  / /      \\ \\__\\        \\ \\__\\ \\ \\_______\\ \\_______\\ \\_______\\\n");
    printf("    \\|_______|\\|__|\\|__|\\___/ /        \\|__|         \\|__|  \\|_______|\\|_______|\\|_______|\n");
    printf("\n");

    //Print menu
    menu();
}

int menu() {
    while (1) {
        int selectionCryptMode = 0;

        //Menu for CryptMode
        printf("Select CryptMode:\n");
        printf("(1) Encrypt\n");
        printf("(2) Decrypt\n");
        printf("(3) Create Key\n");
        printf("(4) Exit\n");

        //Selection for CryptMode
        scanf("%d", &selectionCryptMode);

        switch (selectionCryptMode) {
            case 1:
                user_encrypt();
                break;
            case 2:
                user_decrypt();
                break;
            case 3:
                genKey();
                break;
            case 4:
                return EXIT_SUCCESS;
            default:
                return EXIT_SUCCESS;
        }
    }
}

void user_encrypt() {
    char *pathToFile = NULL;
    char *keyFile = getKeyLocation();

    pathToFile = (char *) malloc(sizeof(char) * 256);
    //Write Path include file without the quotations: "C:\CryptTool\MAGIC.KEY"
    printf("Enter the path to the file you want to encrypt:\n");
    scanf("%s", pathToFile);

    encrypt(keyFile, pathToFile);
}

void user_decrypt() {
    char *pathToFile = NULL;
    char *keyFile = getKeyLocation();

    pathToFile = (char *) malloc(sizeof(char) * 256);
    //Write Path include file without the quotations: "C:\CryptTool\MAGIC.KEY"
    printf("Enter the path to the file you want to decrypt:\n");
    scanf("%s", pathToFile);

    decrypt(keyFile, pathToFile);
}

char *getKeyLocation() {
    int numberOfDrives = getNumberOfDrives();
    char drive[numberOfDrives][20];

    //Search and Save files in array
    getAllDrives(drive);

    //Print all drives out: (Position): (Drive)
    printf("\nDrives:\n");
    for (int i = 0; i < numberOfDrives; i++) {
        printf("Drive %d:", i);
        for (int k = 0; k < strlen(drive[i]); k++) {
            printf("%c", drive[i][k]);
        }
        printf("\n");
    }
    printf("Option %d: Enter Path to Key Manually", numberOfDrives + 1);


    int selectedDrive = 0;
    char *keyFilePath = NULL;

    //Get desired drive number
    keyFilePath = (char *) malloc(sizeof(char) * 256);
    printf("\n--##--##--");
    printf("\nChose %d to %d to Select the Key Path\n", 0, numberOfDrives + 1);
    scanf("%d", &selectedDrive);

    if (selectedDrive == numberOfDrives + 1) {
        printf("Enter Key Path Manually:\n");
        scanf("%s", keyFilePath);
    } else {
        //get key path
        getMasterKeyPath(drive[selectedDrive], keyFilePath);
    }
    return keyFilePath;
}

void genKey() {
    char *keyPath = getKeyLocation();
    generateKeyFile(keyPath);
}