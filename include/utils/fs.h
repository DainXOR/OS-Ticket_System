#ifndef FS_H
#define FS_H

#include <stdio.h>

typedef struct {
    char **lines;
    size_t count;
} file_lines;

int fs_write(const char *path, size_t n, ...);
file_lines fs_read(const char *path);

void fs_freeLines(file_lines *fl);

#endif
