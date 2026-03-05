#include "utils/fs.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#include <sys/types.h>
#define MKDIR(path) mkdir(path, 0755)
#endif

static int ensure_dir(const char *path){
    char tmp[1024];
    char *p;

    snprintf(tmp, sizeof(tmp), "%s", path);

    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = 0;
            MKDIR(tmp);
            *p = '/';
        }
    }

    if (MKDIR(tmp) && errno != EEXIST)
        return -1;

    return 0;
}


int fs_write(const char *path, size_t n, ...){
	char dir[1024];

    if (snprintf(dir, sizeof(dir), "%s", path) >= (int)sizeof(dir))
        return -1;

    char *slash = strrchr(dir, '/');
    if (slash) {
        *slash = '\0';
        if (ensure_dir(dir) != 0)
            return -1;
    }

    FILE *f = fopen(path, "a");
    if (!f)
        return -1;

    va_list args;
    va_start(args, n);

    for (size_t i = 0; i < n; i++) {
        const char *str = va_arg(args, const char *);
        if (str)
            fprintf(f, "%s\n", str);
    }

    va_end(args);

    fclose(f);
    return 0;
}
file_lines fs_read(const char *path){
    file_lines fl = {0};

    FILE *f = fopen(path, "r");
    if (!f)
        return fl;

    size_t cap = 8;
    fl.lines = malloc(sizeof(char*) * cap);

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), f)) {

        if (fl.count >= cap) {
            cap *= 2;
            fl.lines = realloc(fl.lines, sizeof(char*) * cap);
        }

        size_t len = strlen(buffer);
        char *line = malloc(len + 1);

        strcpy(line, buffer);

        fl.lines[fl.count++] = line;
    }

    fclose(f);
    return fl;
}
