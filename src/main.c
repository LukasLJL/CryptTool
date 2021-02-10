#include <stdio.h>
#include "driveSelector.h"
#include <string.h>
//ToDo Text in Englisch schreiben.

int main(void)
{
    int selectionCryptMode;
    int numberOfDrives = getNumberOfDrives();
    char writeDriveLetter[2];
    char writeFilePath[100];
    char writePathEncryptDecrypt[100];
    char drive[numberOfDrives][20];

    printf("Select CryptMode:\n");
    printf("(1) Encrypt");
    printf("(2) Decrypt\n");

    getAllDrives(drive);

    for (int i = 0; i < numberOfDrives; i++)
    {
        for (int k = 0; k < strlen(drive[i]); k++)
        {
            printf("%c", drive[i][k]);
        }
    }

    scanf("%d", selectionCryptMode);

    switch(selectionCryptMode)
    {
        case 1:
            //ToDo Fehler abfangen bei eingabe.
            //ToDo Doppelten Code in Funktion schreiben
            printf("Enter the Number drive letter, where keyfile is saved:\n");
            scanf("%s", &writeDriveLetter);

            printf("Enter Path, where keyfile is saved:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);

            printf("Path for the encryptfile:");
            scanf("%s", &writePathEncryptDecrypt);
            break;

        case 2:
            printf("Eingabe von Laufwerksbuchstaben, wo die Key-Datei liegt:\n");
            scanf("%s", &writeDriveLetter);

            printf("Eingabe von Pfad, wo die Key-Datei liegt:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);

            printf("Wo liegt die zu verschlüsselnde Datei: ");
            scanf("%s", &writePathEncryptDecrypt);
            break;
    }
}