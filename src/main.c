#include <stdio.h>
#include "driveSelector.h"
#include <string.h>
#include "../cryptlib/cryptlib-io.h"
#include "../cryptlib/cryptlib.h"
//ToDo Text in Englisch schreiben.
//ToDo Fehler abfangen bei eingabe.

int main(void)
{
    //Declare and Initialize vars.
    int selectionCryptMode = 0;
    int numberOfDrives = getNumberOfDrives();
    int writeDrivePos = 0;
    char writeKeyFilePath [256];
    char writePathEncryptDecrypt [256];
    char drive[numberOfDrives][20];

    //Menu for CryptMode
    printf("Select CryptMode:\n");
    printf("(1) Encrypt\n");
    printf("(2) Decrypt\n");

    //Selection for CryptMode
    scanf("%d", &selectionCryptMode);

    //Search and Save files in array
    getAllDrives(drive);

    //Print all drives out: (Position): (Drive)
    printf("\nDrives:\n");
    for (int i = 0; i < numberOfDrives; i++)
    {
        for (int k = 0; k < strlen(drive[i]); k++)
        {
            printf("Drive %d: %c\n", k, drive[i][k]);
        }
    }

    //Get desired drive number
    printf("\nEnter the number of your desired drive:\n");
    scanf("%d", &writeDrivePos);

    //Get path from key file
    getMasterKeyPath(drive[writeDrivePos], writeKeyFilePath);

    //Write Path include file without the quotations: "C:\CryptTool\MAGIC.KEY"
    printf("Path for the encrypted / decrypted file:\n");
    scanf("%s", &writePathEncryptDecrypt);

    //Encrypt / Decrypt Mode
    if(selectionCryptMode == 1)
    {
        encrypt(writeKeyFilePath, writePathEncryptDecrypt);
    }
    else if(selectionCryptMode == 2)
    {
        decrypt(writeKeyFilePath, writePathEncryptDecrypt);
    }
}