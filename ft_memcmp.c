#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>



int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *new_s1;
    unsigned char *new_s2;
    size_t i;

    i=0;
    new_s1=(unsigned char *)s1;
    new_s2=(unsigned char *)s2;
    while(new_s1[i]&&new_s2[i]&&i<n){
        if (new_s1[i]!=new_s2[i]){
            return new_s1[i]-new_s2[i];
        }
        i++;
    }
    if((new_s1[i] || new_s2[i]) && i<n)
    {
        if (new_s1[i]!=new_s2[i]){
            return new_s1[i]-new_s2[i];
        }
    }
    return 0;
}


int ft_memcmp(const void *s1, const void *s2, size_t n);

int main(void)
{
    // 1. Identical strings
    char str1[] = "Hello World";
    char str2[] = "Hello ";
    printf("%d",memcmp(str1, str2, 11) );
    // assert(ft_memcmp(str1, str2, 11) == 0);

    // // 2. Different characters at the beginning
    // char a[] = "Hello";
    // char b[] = "Jello";

    // assert(ft_memcmp(a, b, 5) < 0);
    // assert(ft_memcmp(b, a, 5) > 0);

    // // 3. Different characters in the middle
    // char str3[] = "Hello World";
    // char str4[] = "Hello Xorld";

    // assert(ft_memcmp(str3, str4, 11) < 0);
    // assert(ft_memcmp(str4, str3, 11) > 0);

    // // 4. Different characters at the end of the range
    // char str5[] = "abcd";
    // char str6[] = "abce";

    // assert(ft_memcmp(str5, str6, 4) < 0);
    // assert(ft_memcmp(str6, str5, 4) > 0);

    // // 5. Difference exists outside the compared range
    // char str7[] = "Hello";
    // char str8[] = "Helxo";

    // assert(ft_memcmp(str7, str8, 3) == 0);

    // // 6. Compare zero bytes
    // assert(ft_memcmp(str7, str8, 0) == 0);

    // // 7. Identical memory blocks
    // char data1[] = {1, 2, 3, 4, 5};
    // char data2[] = {1, 2, 3, 4, 5};

    // assert(ft_memcmp(data1, data2, 5) == 0);

    // // 8. Different memory blocks
    // char data3[] = {1, 2, 3, 4, 5};
    // char data4[] = {1, 2, 9, 4, 5};

    // assert(ft_memcmp(data3, data4, 5) < 0);
    // assert(ft_memcmp(data4, data3, 5) > 0);

    // // 9. Compare memory containing null bytes
    // char null1[] = {'a', '\0', 'b', 'c'};
    // char null2[] = {'a', '\0', 'b', 'd'};

    // assert(ft_memcmp(null1, null2, 3) == 0);
    // assert(ft_memcmp(null1, null2, 4) < 0);
    // assert(ft_memcmp(null2, null1, 4) > 0);

    // // 10. First difference determines the result
    // char first1[] = {10, 20, 30};
    // char first2[] = {10, 25, 1};

    // assert(ft_memcmp(first1, first2, 3) < 0);
    // assert(ft_memcmp(first2, first1, 3) > 0);

    // // 11. Unsigned byte values: 128 and 255
    // unsigned char bytes1[] = {0, 127, 128, 200, 255};
    // unsigned char bytes2[] = {0, 127, 128, 200, 255};

    // assert(ft_memcmp(bytes1, bytes2, 5) == 0);

    // unsigned char bytes3[] = {128};
    // unsigned char bytes4[] = {127};

    // assert(ft_memcmp(bytes3, bytes4, 1) > 0);
    // assert(ft_memcmp(bytes4, bytes3, 1) < 0);

    // unsigned char bytes5[] = {255};
    // unsigned char bytes6[] = {0};

    // assert(ft_memcmp(bytes5, bytes6, 1) > 0);
    // assert(ft_memcmp(bytes6, bytes5, 1) < 0);

    // // 12. Repeated bytes
    // char repeated1[] = "aaaab";
    // char repeated2[] = "aaaac";

    // assert(ft_memcmp(repeated1, repeated2, 4) == 0);
    // assert(ft_memcmp(repeated1, repeated2, 5) < 0);

    // // 13. Compare only the common prefix
    // char prefix1[] = "abc";
    // char prefix2[] = "abcdef";

    // assert(ft_memcmp(prefix1, prefix2, 3) == 0);

    // // 14. Compare against the standard function
    // char cmp1[] = {1, 2, 200, 4};
    // char cmp2[] = {1, 2, 100, 4};

    // int result_ft = ft_memcmp(cmp1, cmp2, 4);
    // int result_std = memcmp(cmp1, cmp2, 4);

    // assert((result_ft < 0 && result_std < 0) ||
    //        (result_ft > 0 && result_std > 0) ||
    //        (result_ft == 0 && result_std == 0));

    // // 15. Compare identical pointers
    // assert(ft_memcmp(data1, data1, 5) == 0);

    // printf("All tests passed!\n");
    // return 0;
}