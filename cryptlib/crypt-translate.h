//
// Created by GROSA5 on 2/7/2021.
//

#ifndef CRYPT_TOOL_CRYPT_TRANSLATE_H
#define CRYPT_TOOL_CRYPT_TRANSLATE_H

int getOffsetSeed(const char *);
unsigned char translateChar(unsigned char, int);
int hashKey(const char *);
void *translate(void *, char *, size_t);

#endif //CRYPT_TOOL_CRYPT_TRANSLATE_H
