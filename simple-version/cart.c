/********************************************************************************
        Для хранения таблицы необходимо использовать двумерную матрицу. Для
    соблюдения гетерогенности формата данных необходимо предусмотреть, чтобы
    значения категориального и числового атрибутов было одной длинны. Например для
    хранения числовых значений использовать float (4 байта), а для категориальных
    uint32_t (4 байта) или double и uint64_t + соответствующие преобразования из
    сырых данных в формат с плавающей точкой.

    При выделении памяти для таблицы использоват механизм динамического
выравниваня по длинне линии кэша первого уровня. Узнать размер линии кэша данных
первого уровня можно при помощи ф-ии sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    Выделить динамический блок данных с учетом выравнивания пожно ф-ией
    int posix_memalign(void **memptr, size_t alignment, size_t size);
*********************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <time.h>

#define ATTR_TYPE_NUMERICAL      0x1
#define ATTR_TYPE_CATEGORICAL    0x2

typedef uint8_t  attr_type_t;
typedef uint32_t attr_count_t;

typedef float    attr_num_val_t;
typedef uint32_t attr_cat_val_t;

union value_t
{
    attr_num_val_t num;
    attr_cat_val_t cat;
};

struct __attribute__((packed, aligned(1))) attr_header_t
{
    attr_type_t type;
};

struct attr_t
{
    struct attr_header_t header;
};

struct table_header_t
{
    attr_count_t attr_count;
    attr_count_t vals_count;
};

struct table_t
{
    struct table_header_t   header;
    struct attr_t*          attr;
    union  value_t*         val;
};




float
gini_int(int* array, int len)
{
    int i   = 0;
    int min = array[0];
    int max = min;

    for (i = 1; i < len; i++)
    {
        int val = array[i];
        if (val < min)
            min = val;
        else if (val > max)
            max = val;
    }

    int  number_of_groups = max - min + 1;
    int* groups           = calloc(number_of_groups, sizeof(int));

    for (i = 0; i < len; i++)
    {
        int hash = array[i] - min;
        groups[hash]++;
    }

    int sum = 0;
    for (i = 0; i < number_of_groups; i++)
    {
        int val = groups[i];
        if (val != 0)
        {
            sum += (val * val);
        }
    }

    free(groups);

    return 1 - (float) sum / (len * len);
}

#define NSEC_IN_SEC     1000000000
#define CLOCK_ID        CLOCK_REALTIME
#define ITERATIONS      1

void
test_gini_int(int elements)
{
    srandom(666);

//    int test[10] = { 1, 2, 1, 4, 1, 6, 7, 8, 9, 10 };
    int* test = calloc(elements, sizeof(int));
    int i = 0;
    float test_gini = 0;

    for (i = 0; i < elements; i++)
    {
        test[i] = random() % 10000;
    }

    struct timespec start;
    struct timespec stop;

    long   sec       = 0;
    long   nsec      = 0;
    double nsec_diff = 0;
    double sec_diff  = 0;

    double sec_diff_min = 0;
    double sec_diff_max = 0;
    double sec_diff_avg = 0;
    double sec_diff_sum = 0;

    for (i = 0; i < ITERATIONS; i++)
    {
        clock_gettime(CLOCK_ID, &start);
        test_gini = gini_int(test, elements);
        clock_gettime(CLOCK_ID, &stop);

        sec       = stop.tv_sec - start.tv_sec;
        nsec      = stop.tv_nsec - start.tv_nsec;
        nsec_diff = NSEC_IN_SEC * sec + nsec;
        sec_diff  = nsec_diff / NSEC_IN_SEC;

        if (sec_diff_sum == 0)
            sec_diff_min = sec_diff_max = sec_diff;
        else
        {
            if (sec_diff < sec_diff_min)
                sec_diff_min = sec_diff;
            else if (sec_diff > sec_diff_max)
                sec_diff_max = sec_diff;
        }

        sec_diff_sum += sec_diff;
    }
    sec_diff_avg = sec_diff_sum / ITERATIONS;

    printf("min: %.9f (sec)\n"
           "avg: %.9f (sec)\n"
           "max: %.9f (sec)\n",
           sec_diff_min,
           sec_diff_avg,
           sec_diff_max);

    printf("test gini index: %f\n", test_gini);

    free(test);
}








/*
void
print_table(struct TABLE_T* table)
{
    ATTR_COUNT_T i, j;
    for (i = 0; i < t
able->header.vals_count; i++)
    {
        for (j = 0; j < table->header.attr_count; j++)
        {
            //printf("%x\t", table->attr[j].val[i]);
        }
        printf("\n");
    }
}
*/

void
split_table(struct table_t* table,
            struct table_t* left_split,
            struct table_t* right_split)
{
}

/*
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
*/


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
/*
    FILE*          fd    = stdin;
    struct table_t table = { 0 };

    fread(&table.header, sizeof(struct table_header_t), 1, fd);
    table.attr = calloc(table.header.attr_count, sizeof(struct attr_t));
    fread(table.attr, sizeof(struct attr_t), table.header.attr_count, fd);

    int data_size = table.header.attr_count * table.header.vals_count;
    table.val = calloc(data_size, sizeof(union value_t));
    fread(table.val, sizeof(union value_t), data_size, fd);
*/


//    int test[10] = { 1, 2, 1, 4, 1, 6, 7, 8, 9, 10 };
//    float test_gini = gini_int(test, 10);
//    printf("test gini index: %f\n", test_gini);

    test_gini_int(20000000);

/*
    int i;
    for (i = 0; i < table.header.attr_count; i++)
    {
        fread(&table.attr[i].header, sizeof(struct ATTR_HEADER_T), 1, fd);

        size_t size_of_val = get_attr_val_size_by_type(table.attr[i].header.type);
        table.attr[i].val = calloc(table.header.vals_count, size_of_val);
        fread(table.attr[i].val, size_of_val, table.header.attr_vals_count, fd);
    }
*/

    // Разбиение...
//    struct table_t left_table;
//    struct table_t right_table;
//    split_table(&table, &left_table, &right_table);

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