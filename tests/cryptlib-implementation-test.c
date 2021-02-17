//
// Created by GROSA5 on 2/14/2021.
//

#include "cryptlib-implementation-test.h"
#include "../cryptlib/cryptlib.h"
#include <stdio.h>
#include <stddef.h>
#include <io.h>
#include <stdlib.h>

/*
 *
 * DEBUG: to find the mother of all Bugs
 *
 */

char displayMenu();
void generateKeyInFolder();
void encryptSomething();
void decryptSomething();

int main(){
    while (1){
        char selection = displayMenu();
        switch (selection) {
            case '1':
                generateKeyInFolder();
                break;
            case '2':
                encryptSomething();
                break;
            case '3':
                decryptSomething();
                break;
            case '4':
                return 0;
            default:
                break;
        }
    }
}

char displayMenu(){
    printf("|   What action do you want to test?\n");
    printf("|     [1] Key Generation\n");
    printf("|     [2] File Encryption\n");
    printf("|     [3] File Decryption\n");
    printf("|     [4] Exit\n");
    printf("|\n");
    printf("|   ->");

    char selection;
    while ((scanf("%c", &selection)) != 1 ||
            (selection != '1' && selection != '2' && selection != '3' && selection != '4')){
        printf("|   Please try again\n");
        printf("|   ->");
    }
    return selection;
}

char *getSomePath(char *msg){
    printf("|\n", msg);
    printf("|   %s\n", msg);
    printf("|   ->");
    char *fileName = malloc(100);
    scanf("%s", fileName);
    getc(stdin);
    return fileName;
}

void generateKeyInFolder() {
    // check if Key gen works
    generateKeyFile(getSomePath("Please enter the File Name for your key"));
    printf("|\n");
}

void encryptSomething() {
    // check if bug is in encryption
    encrypt(getSomePath("Enter the path to your key"), getSomePath("Enter the path to your file"));
    printf("|\n");
}

void decryptSomething() {
    // check if bug is in decrypt function
    decrypt(getSomePath("Enter the path to your key"), getSomePath("Enter the path to your file"));
    printf("|\n");
}

