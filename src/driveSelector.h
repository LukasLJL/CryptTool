void getMasterKeyPath_CharDriveLetter(char, char *);
void getMasterKeyPath_StringDriveLetter(char *, char *);
#define getMasterKeyPath(driveLetter, pathToMasterKey) _Generic(driveLetter, char: getMasterKeyPath_CharDriveLetter, char*: getMasterKeyPath_StringDriveLetter)(driveLetter, pathToMasterKey)
int getNumberOfDrives();
void getAllDrives(char [][20]);
char *getOSTyp();
