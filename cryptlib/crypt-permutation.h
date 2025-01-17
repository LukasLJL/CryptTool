//
// Created by GROSA5 on 2/4/2021.
//

#ifndef CRYPT_TOOL_CRYPT_PERMUTATION_H
#define CRYPT_TOOL_CRYPT_PERMUTATION_H

int *getUnitOfOffset(const char *);
int* getOffsetMap(const char *);
void performOffsetRow(int *, int);
void performOffsetColumn(int*, int, int);
void *permute(void *, char *, size_t);
void *permuteFromMap(void *, const int *, size_t);
void *unpermute(void *, char *, size_t);
void *unpermuteFromMap(void *, const int *, size_t);
void* createCopy(void *, size_t);

#endif //CRYPT_TOOL_CRYPT_PERMUTATION_H
