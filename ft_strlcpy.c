#include <stdio.h>
// #include <string.h>
#include <stddef.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t src_len;
    size_t i;

    src_len=0;
    i=0;
    while (src[src_len]!=0)
    {
        src_len++;
    }
    if (size>0){
        while (i<size-1){
            dst[i]=src[i];
            i++;
        }
        dst[i]=0;
    }
    printf("dst:%s,  src:%s,  size:%zu\n",dst,src,size);
    return src_len;
}

// #define DST_CAP 64

// typedef struct s_test
// {
//     const char *src;
//     size_t      size;
//     size_t      expected_ret;
// } t_test;

// int run_test(const t_test *test, int number)
// {
//     char    dst[DST_CAP];
//     char    expected[DST_CAP];
//     size_t  src_len;
//     size_t  copy_len;
//     size_t  ret;
//     size_t  i;

//     memset(dst, 'X', sizeof(dst));
//     memset(expected, 'X', sizeof(expected));

//     src_len = strlen(test->src);
//     copy_len = 0;

//     if (test->size > 0)
//     {
//         copy_len = src_len;
//         if (copy_len >= test->size)
//             copy_len = test->size - 1;

//         memcpy(expected, test->src, copy_len);
//         expected[copy_len] = '\0';
//     }

//     ret = ft_strlcpy(dst, test->src, test->size);

//     if (ret != test->expected_ret)
//     {
//         printf("FAIL #%d: return %zu, expected %zu\n",
//             number, ret, test->expected_ret);
//         return 1;
//     }

//     for (i = 0; i < DST_CAP; i++)
//     {
//         if (dst[i] != expected[i])
//         {
//             printf("FAIL #%d: dst differs at byte %zu\n",
//                 number, i);
//             return 1;
//         }
//     }

//     printf("PASS #%d\n", number);
//     return 0;
// }

// int main(void)
// {
//     const t_test tests[] = {
//         {"Hello", 10, 5},
//         {"", 10, 0},
//         {"AB", 4, 2},
//         {"abcdefghij", 12, 10},
//     };

//     size_t count = sizeof(tests) / sizeof(tests[0]);
//     size_t i;
//     int failures = 0;

//     for (i = 0; i < count; i++)
//         failures += run_test(&tests[i], (int)i + 1);

//     printf("\n%d/%zu tests failed.\n", failures, count);
//     return failures != 0;
// }

int main(void)
{
    char dest[10];
    size_t n=ft_strlcpy(dest,"Hello",10);//5
    printf("size expted:%zu\n",n);
    return 0;
}

