#include <stdio.h>
#include <string.h>

#ifdef __linux
char *osTyp = "Linux";
#elif _WIN64
char *osTyp = "Windows";
#else
char *osTyp = "Unkown";
#endif

char *getOSTyp();


void getAllDrives(char *drives) {
    FILE *fp;
    char cmd_results[100];
    int driveCounter = 0;
    if (getOSTyp() == "Windows") {
        //Safes Output of cmd in "file"
        fp = popen("wmic logicaldisk get name", "r");
        //Loop through output of command to list all drives
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            if (strcmp(cmd_results, "Name") != 1) {
                drives[driveCounter] = cmd_results[0];
                driveCounter++;
            }
        }
    } else if (getOSTyp() == "Linux") {
        //Safes Output of shell cmd in "file"
        fp = popen("ls /mnt", "r");
        //Loop through output of command to list all drives
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            drives[driveCounter] = cmd_results[0];
            driveCounter++;
        }
    }
}

//Does the same thing as getAllDrives, but it just counts the amount of drives to create an array with the correct size
int getNumberOfDrives() {
    FILE *fp;
    int driveCounter = 0;
    char cmd_results[1000];
    if (getOSTyp() == "Windows") {
        fp = popen("wmic logicaldisk get name", "r");
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            if (strcmp(cmd_results, "Name") != 1) {
                driveCounter++;
            }
        }
    } else if (getOSTyp() == "Linux") {
        fp = popen("ls /mnt", "r");
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            driveCounter++;
        }
    }
    return driveCounter;
}

char *getMasterKeyPath() {

}

char *getOSTyp() {
    return osTyp;
}