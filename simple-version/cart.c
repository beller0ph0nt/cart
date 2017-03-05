/********************************************************************************
        Для хранения таблицы необходимо использовать двумерную матрицу. Для
    соблюдения гетерогенности формата данных необходимо предусмотреть, чтобы
    значения категориального и числового атрибутов было одной длинны. Например для
    хранения числовых значений использовать float (4 байта), а для категориальных
    uint32_t (4 байта) или double и uint64_t + соответствующие преобразования из
    сырых данных в формат с плавающей точкой.
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ATTR_TYPE_NUMERICAL      0x1
#define ATTR_TYPE_CATEGORICAL    0x2

typedef uint8_t     ATTR_TYPE_T;
typedef uint32_t    ATTR_COUNT_T;

typedef float       ATTR_NUMERIC_VAL_T;
typedef uint32_t    ATTR_CATEGORIC_VAL_T;

struct __attribute__((packed, aligned(1))) ATTR_HEADER_T
{
    ATTR_TYPE_T     type;
};

struct ATTR_T
{
    struct ATTR_HEADER_T    header;
    void*                   val;
};

struct TABLE_HEADER_T
{
    ATTR_COUNT_T    attr_count;
    ATTR_COUNT_T    attr_vals_count;
};

struct TABLE_T
{
    struct TABLE_HEADER_T   header;
    struct ATTR_T*          attr;
};




void
print_table(struct TABLE_T* table)
{
    ATTR_COUNT_T i, j;
    for (i = 0; i < table->header.attr_vals_count; i++)
    {
        for (j = 0; j < table->header.attr_count; j++)
        {
            //printf("%x\t", table->attr[j].val[i]);
        }
        printf("\n");
    }
}

void
split_table(struct TABLE_T* table,
            struct TABLE_T* left_split,
            struct TABLE_T* right_split)
{
}

size_t
get_attr_val_size_by_type(ATTR_TYPE_T type)
{
    size_t val_size = 0;

    switch (type)
    {
    case ATTR_TYPE_NUMERICAL:
        val_size = sizeof(ATTR_NUMERIC_VAL_T);
    case ATTR_TYPE_CATEGORICAL:
        val_size = sizeof(ATTR_CATEGORIC_VAL_T);
    }

    return val_size;
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
    FILE*          fd    = stdin;
    struct TABLE_T table = { 0 };

    fread(&table.header, sizeof(struct TABLE_HEADER_T), 1, fd);
    table.attr = calloc(table.header.attr_count, sizeof(struct ATTR_T));

    int i;
    for (i = 0; i < table.header.attr_count; i++)
    {
        fread(&table.attr[i].header, sizeof(struct ATTR_HEADER_T), 1, fd);

        size_t size_of_val = get_attr_val_size_by_type(table.attr[i].header.type);
        table.attr[i].val = calloc(table.header.attr_vals_count, size_of_val);
        fread(table.attr[i].val, size_of_val, table.header.attr_vals_count, fd);
    }

    // Разбиение...
    struct TABLE_T left_table;
    struct TABLE_T right_table;
    split_table(&table, &left_table, &right_table);

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