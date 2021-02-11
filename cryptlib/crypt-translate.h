//
// Created by GROSA5 on 2/7/2021.
//

#ifndef CRYPT_TOOL_CRYPT_TRANSLATE_H
#define CRYPT_TOOL_CRYPT_TRANSLATE_H

int getOffsetSeed(const char *);
void translateChar(void *, int);
void *translate(void *, char *, size_t);
void *untranslate(void *, char *, size_t);
void *translateAll(void *, int, size_t);

#endif //CRYPT_TOOL_CRYPT_TRANSLATE_H
