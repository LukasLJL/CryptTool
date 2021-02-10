#include <stdio.h>
#include "driveSelector.h"

int main(void)
{
    int selectionCryptMode;
    char writeDriveLetter;
    char writeFilePath;

    printf("Auswahl von CryptMode:\n");
    printf("(1) Entschlüsseln");
    printf("(2) Verschlüsseln");

    scanf("%d", selectionCryptMode);

    switch(selectionCryptMode)
    {
        case 1:
            printf("Eingabe von Laufwerksbuchstaben, wo die Datei liegt:\n");
            scanf("%s", &writeDriveLetter);

            printf("Eingabe von Pfad, wo die Datei liegt: C:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);
            break;

        case 2:
            printf("Eingabe von Pfad, wo die Datei liegt:\n");
            scanf("%s", &writeFilePath);

            printf("Eingabe von Pfad, wo die Datei liegt: C:\n");
            scanf("%s", &writeFilePath);

            getMasterKeyPath(writeDriveLetter, writeFilePath);
            break;
    }
}