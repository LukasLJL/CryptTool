#ifdef __linux
char *osTyp = "Linux";
#elif _WIN64 || _WIN32
char *osTyp = "Windows";
#else
char *osTyp = "Unkown";
#endif

char *getOSTyp() {
    return osTyp;
}