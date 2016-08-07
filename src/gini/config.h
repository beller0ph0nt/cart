#ifndef __CONFIG_H
#define __CONFIG_H

typedef union
{
    struct
    {
        __uint8_t b1;
        __uint8_t b2;
        __uint8_t b3;
        __uint8_t b4;
    };
    __uint32_t val;
} ip_t;

typedef __uint32_t port_t;

typedef struct
{
    ip_t   ip;
    port_t port;
} server_t;



#endif // __CONFIG_H
