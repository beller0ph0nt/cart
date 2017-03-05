#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ATTR_TYPE_NUMERICAL      0x1
#define ATTR_TYPE_CATEGORICAL    0x2

typedef uint8_t     ATTR_TYPE_T;
typedef uint32_t    ATTR_COUNT_T;

typedef float       ATTR_NUMERIC_VAL_T;
typedef uint32_t    ATTR_CATEGORIC_VAL_T;

typedef struct __attribute__((packed, aligned(1)))
{
    ATTR_TYPE_T     type;
    ATTR_COUNT_T    count;
} ATTR_HEADER_T;

typedef struct
{
    ATTR_HEADER_T   header;
    void*           val;
} ATTR_T;

typedef struct
{
    uint32_t        attr_count;
} TABLE_HEADER_T;

typedef struct
{
    TABLE_HEADER_T  header;
    ATTR_T*         attr;
} TABLE_T;


void
split(TABLE_T* table, TABLE_T* left_split, TABLE_T* right_split)
{
}


/*
void
calc_num_attr_gini_index(ATTR_NUMERIC_T *vals, ATTR_COUNT_T count)
{
}

void
calc_cat_attr_gini_index(ATTR_CATEGORIC_T *vals, ATTR_COUNT_T count)
{
}
*/

int
main()
{
    FILE*   fd    = stdin;
    TABLE_T table = { 0 };

    fread(&table.header, sizeof(TABLE_HEADER_T), 1, fd);
    table.attr = calloc(table.header.attr_count, sizeof(ATTR_T));

    int i;
    for (i = 0; i < table.header.attr_count; i++)
    {
        fread(&table.attr[i].header, sizeof(ATTR_HEADER_T), 1, fd);

        size_t size_of_val;
        switch (table.attr[i].header.type)
        {
        case ATTR_TYPE_NUMERICAL:
            size_of_val = sizeof(ATTR_NUMERIC_VAL_T);
        case ATTR_TYPE_CATEGORICAL:
            size_of_val = sizeof(ATTR_CATEGORIC_VAL_T);
        }

        table.attr[i].val = calloc(table.attr[i].header.count, size_of_val);
        fread(table.attr[i].val, size_of_val, table.attr[i].header.count, fd);
    }

    // Разбиение...

//    ATTR_HEADER_T attr_header;

//    fread(&attr_header, sizeof(ATTR_HEADER_T), 1, fd);

//    printf("*******************\n");
//    printf("* ATTRIBUT HEADER *\n");
//    printf("*******************\n");
//    printf("type:  %x\n", attr_header.type);
//    printf("count: %x\n", attr_header.count);

    /*

    Функция разбиения таблицы(указатель на таблицу,
                              указатель на левое разбиение,
                              указатель на правое разбиение)
    {
        current_gini_index = 0;
        current_attribute  = 0;

        Цикл по всем аттрибутам
        {
            Для текущего аттрибута вычисляем Индекс Гини
            Если текущий Индекс Гини лучше временного
            {
                Cохраняем текущий
                Сохраняем 
            }
        }
    }

    */

/*
    if (attr_header.type == ATTR_TYPE_NUMERICAL)
    {
        ATTR_NUMERIC_T *num_vals = calloc(attr_header.count, sizeof(ATTR_NUMERIC_T));
        fread(num_vals, sizeof(ATTR_NUMERIC_T), attr_header.count, fd);
        calc_num_attr_gini_index(num_vals, attr_header.count);
    }
    else if (attr_header.type == ATTR_TYPE_CATEGORICAL)
    {
    }
*/

    return 0;
}