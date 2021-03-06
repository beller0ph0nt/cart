#ifndef __CONFIG_H
#define __CONFIG_H

#include <sys/types.h>

#define CONFIG_LINE_SIZE    512

typedef union
{
    struct
    {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        __uint8_t b4;
        __uint8_t b3;
        __uint8_t b2;
        __uint8_t b1;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        __uint8_t b1;
        __uint8_t b2;
        __uint8_t b3;
        __uint8_t b4;
#elif __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
        __uint8_t b2;
        __uint8_t b1;
        __uint8_t b4;
        __uint8_t b3;
#endif // __BYTE_ORDER__
    };
    __uint32_t val;
} ip_t;

typedef __uint32_t port_t;

typedef struct
{
    ip_t   ip;
    port_t port;
} server_t;

typedef __uint32_t servers_count_t;
typedef server_t*  servers_list_t;

servers_list_t
config_cre_server_list(char* fname);

servers_count_t
config_get_server_count();

void
config_del_server_list(servers_list_t list);

#endif // __CONFIG_H
