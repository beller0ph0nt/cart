#ifndef __WRAP_STDLIB_H
#define __WRAP_STDLIB_H

#include <stdlib.h>

void
w_exit(int status);

void*
w_malloc(size_t size);

void
w_free(void* ptr);

void*
w_calloc(size_t nmemb, size_t size);

void*
w_realloc(void* ptr, size_t size);

#endif // __WRAP_STDLIB_H
