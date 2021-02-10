//
// Created by GROSA5 on 2/5/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "cryptlib-io.h"

void catchMemoryAllocationFailure(void *ptr){
    if (ptr == NULL){
        fprintf(stderr, "criptlib: memory allocation failed");
        exit(1);
    }
}