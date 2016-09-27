#ifndef __WRAP_STDIO_H
#define __WRAP_STDIO_H

#include <stdio.h>

FILE*
w_fopen(const char* path, const char* mode);

void
w_fclose(FILE *fp);

#endif // __WRAP_STDIO_H
