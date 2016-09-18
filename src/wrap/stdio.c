#include <wrap/stdio.h>
#include <wrap/stdlib.h>

#include <debug/trace.h>

FILE*
w_fopen(const char* path, const char* mode)
{
    FILE* fd = fopen(path, mode);
    if (fd == NULL)
    {
        TRACE_ERROR("fopen failure");
        w_exit(EXIT_FAILURE);
    }

    return fd;
}

void
w_fclose(FILE *fp)
{
    if (fclose(fp) == EOF)
    {
        TRACE_ERROR("fclose failure");
        w_exit(EXIT_FAILURE);
    }
}
