#include <stdio.h>
#include "driveSelector.h"

int main(void)
{
    int selectionCryptMode;
    char writeDriveLetter [2];
    char writeFilePath[100];
    char writePathEncryptDecrypt[100];

    printf("Auswahl von CryptMode:\n");
    printf("(1) Entschlüsseln");
    printf("(2) Verschlüsseln");

    scanf("%d", selectionCryptMode);

    switch(selectionCryptMode)
    {
        case 1:
            printf("Eingabe von Laufwerksbuchstaben, wo die Key-Datei liegt:\n");
            scanf("%s", &writeDriveLetter);

            printf("Eingabe von Pfad, wo die Key-Datei liegt: C:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);

            printf("Wo liegt die zu entschlüsselnde Datei");
            scanf("%s", &writePathEncryptDecrypt);
            break;

        case 2:
            printf("Eingabe von Pfad, wo die Key-Datei liegt:\n");
            scanf("%s", &writeFilePath);

            printf("Eingabe von Pfad, wo die Key-Datei liegt: C:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);

            printf("Wo liegt die zu verschlüsselnde Datei: ");
            scanf("%s", &writePathEncryptDecrypt);
            break;
    }
}