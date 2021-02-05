#include <stdio.h>
#include <string.h>
#include "driveSelector.h"

#ifdef __linux
char *osTyp = "Linux";
char *pathToKey = "/CryptTool/MAGIC.KEY";
#elif _WIN64
char *osTyp = "Windows";
char *pathToKey = ":/CryptTool/MAGIC.KEY";
#else
char *osTyp = "Unkown";
#endif


void getAllDrives(char drives[][20]) {
    FILE *fp;
    char cmd_results[100];
    int driveCounter = 0;
    if (getOSTyp() == "Windows") {
        //Safes Output of cmd in "file"
        fp = popen("wmic logicaldisk get name", "r");
        //Loop through output of command to list all drives
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            if (strcmp(cmd_results, "Name") != 1) {
                memset(drives[driveCounter], 0, sizeof(drives[driveCounter]));
                drives[driveCounter][0] = cmd_results[0];
                driveCounter++;
            }
        }
    } else if (getOSTyp() == "Linux") {
        //Safes Output of shell cmd in "file"
        fp = popen("ls /mnt", "r");
        //Loop through output of command to list all drives
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            int i = 0;
            //Clear the current String
            memset(drives[driveCounter], 0, sizeof(drives[driveCounter]));
            while (cmd_results[i] != '\n') {
                drives[driveCounter][i] = cmd_results[i];
                i++;
            }
            driveCounter++;
        }
    }
}

//Code executes the same commands on the os, but is just counting the drives now
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
        driveCounter--;
    } else if (getOSTyp() == "Linux") {
        fp = popen("ls /mnt", "r");
        while (fgets(cmd_results, sizeof(cmd_results), fp) != NULL) {
            driveCounter++;
        }
    }
    return driveCounter;
}


void getMasterKeyPath_StringDriveLetter(char *driveLetter, char *pathToMasterKey) {
    //Clearing PathTo..
    memset(pathToMasterKey, 0, sizeof(pathToMasterKey));
    strcat(pathToMasterKey, driveLetter);
    strcat(pathToMasterKey, pathToKey);
}

void getMasterKeyPath_CharDriveLetter(char driveLetter, char *pathToMasterKey) {
    //Clearing PathTo..
    memset(pathToMasterKey, 0, sizeof(pathToMasterKey));
    strncat(pathToMasterKey, &driveLetter, 1);
    strcat(pathToMasterKey, pathToKey);
}

char *getOSTyp() {
    return osTyp;
}