#include "utils/str.h"

#include <stdlib.h>
#include <string.h>

char* str_clone(char* original){
    if (!original)
        return NULL;

    size_t len = strlen(original) + 1;

    char *copy = malloc(len);
    if (!copy)
        return NULL;

    memcpy(copy, original, len);

    return copy;
}
