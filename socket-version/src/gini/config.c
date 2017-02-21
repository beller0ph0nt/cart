#include <string.h>

#include <debug/trace.h>
#include <debug/profiler.h>

#include <gini/config.h>

#include <wrap/stdio.h>
#include <wrap/stdlib.h>

static servers_count_t servers_count = 0;

servers_list_t
config_cre_server_list(char* fname)
{
    PROFILER_PROLOG
    TRACE_DEBUG("begin");

    FILE* fd = w_fopen(fname, "r");

    servers_count = 0;
    servers_list_t list = NULL;
    char line[CONFIG_LINE_SIZE + 1] = { 0 };

    int line_no;
    for (line_no = 1; !feof(fd); line_no++)
    {
        int line_len = 0;
        fscanf(fd, "%[^\n]\n%n", line, &line_len);
        TRACE_DEBUG("    read line %d: %s len: %d", line_no, line, line_len);

        if (strlen(line) == 0)
            continue;

        if (line_len > CONFIG_LINE_SIZE)
        {
            TRACE_ERROR("(file: %s line: %d): "
                        "too big line size",
                        fname,
                        line_no);
            w_exit(EXIT_FAILURE);
        }

        int ip[4] = { 0 }, port = 0;
        sscanf(line,
               "%d.%d.%d.%d:%d",
               &ip[0],
               &ip[1],
               &ip[2],
               &ip[3],
               &port);

        if (ip[0] < 0 || 255 < ip[0] ||
            ip[1] < 0 || 255 < ip[1] ||
            ip[2] < 0 || 255 < ip[2] ||
            ip[3] < 0 || 255 < ip[3])
        {
            TRACE_ERROR("(file: %s line: %d): "
                        "incorrect ip",
                        fname,
                        line_no);
            w_exit(EXIT_FAILURE);
        }

        if (port < 0 || 65535 < port)
        {
            TRACE_ERROR("(file: %s line: %d): "
                        "incorrect port",
                        fname,
                        line_no);
            w_exit(EXIT_FAILURE);
        }

        int srv_index = servers_count++;
        list = w_realloc(list, sizeof(server_t) * servers_count);

        list[srv_index].ip.b1 = ip[0];
        list[srv_index].ip.b2 = ip[1];
        list[srv_index].ip.b3 = ip[2];
        list[srv_index].ip.b4 = ip[3];
        list[srv_index].port = port;
    }

    w_fclose(fd);

    PROFILER_EPILOG

    return list;
}

servers_count_t
config_get_server_count()
{
    TRACE_DEBUG("begin");
    return servers_count;
}

void
config_del_server_list(servers_list_t list)
{
    TRACE_DEBUG("begin");
    w_free(list);
}
