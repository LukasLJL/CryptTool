//
// Created by GROSA5 on 2/4/2021.
//

#ifndef CRYPT_TOOL_CRIPT_PERMUTATION_H
#define CRYPT_TOOL_CRIPT_PERMUTATION_H

int *getUnitOfOffset(const char *);
int hashKey(const char *);
int* getOffsetMap(const char *);
void performOffsetRow(int *, int);
void performOffsetColumn(int*, int, int);

#endif //CRYPT_TOOL_CRIPT_PERMUTATION_H
