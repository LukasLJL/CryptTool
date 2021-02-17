#include <stdio.h>
#include "driveSelector.h"
#include <string.h>
#include "../cryptlib/cryptlib-io.h"
#include "../cryptlib/cryptlib.h"
//ToDo Text in Englisch schreiben.
//ToDo Fehler abfangen bei eingabe.
//ToDo Doppelten Code in Funktion schreiben

int main(void)
{
    int selectionCryptMode = 0;
    int numberOfDrives = getNumberOfDrives();
    int writeDrivePos;
    char writeKeyFilePath[100];
    char writePathEncryptDecrypt[100];
    char drive[numberOfDrives][20];

    printf("Select CryptMode:\n");
    printf("(1) Encrypt\n");
    printf("(2) Decrypt\n");

    scanf("%d", &selectionCryptMode);

    getAllDrives(drive);

    printf("\nDrives:\n");
    for (int i = 0; i < numberOfDrives; i++)
    {
        for (int k = 0; k < strlen(drive[i]); k++)
        {
            printf("Drive %d: %c\n", k, drive[i][k]);
        }
    }

    if(selectionCryptMode == 1)
    {
        printf("\nEingabe der Zahl, wo die KeyDatei ist:\n");
        scanf("%d", &writeDrivePos);

        getMasterKeyPath(drive[writeDrivePos], writeKeyFilePath);

        printf("Path for the encryptfile:\n");
        scanf("%s", &writePathEncryptDecrypt);

        encrypt(&writeKeyFilePath, &writePathEncryptDecrypt);
    }
    else if(selectionCryptMode == 2)
    {
        printf("\nEingabe von Laufwerksbuchstaben, wo die Key-Datei liegt:\n");
        scanf("%s", &writeDrivePos);

        getMasterKeyPath(drive[writeDrivePos], writeKeyFilePath);

        printf("Wo liegt die zu verschlüsselnde Datei:\n");
        scanf("%s", &writePathEncryptDecrypt);

        decrypt(&writeKeyFilePath, &writePathEncryptDecrypt);
    }
}