//
// Created by GROSA5 on 2/7/2021.
//

#ifndef CRYPT_TOOL_CRYPT_TRANSLATE_H
#define CRYPT_TOOL_CRYPT_TRANSLATE_H

int getOffsetSeed(const char *);
void translateChar(void *, int);
void *translate(void *binData, char *key, size_t len);
void *untranslate(void *binData, char *key, size_t len);
void *translateAll(void *, int, size_t);

#endif //CRYPT_TOOL_CRYPT_TRANSLATE_H
