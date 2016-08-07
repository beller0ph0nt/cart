#ifndef __PROTOCOL_H
#define __PROTOCOL_H

#define GINI_ACK            0
#define GINI_REQ_STATUS     1
#define GINI_ANS_STATUS     2
#define GINI_REQ_DATA       3
#define GINI_ANS_GINIINDEX  4

#define GINI_STATUS_IDLE        1
#define GINI_STATUS_DATA_WAIT   2
#define GINI_STATUS_CALC        3

typedef __uint8_t  cmd_t;
typedef __uint8_t  status_t;
typedef __uint64_t data_len_t;
typedef double     gini_index_t;

typedef union
{
    status_t     status;
    data_len_t   data_len;
    gini_index_t gini_index;
} arg_t;

typedef struct
{
    cmd_t cmd;
    arg_t arg;
} gini_msg_t;

#endif // __PROTOCOL_H
