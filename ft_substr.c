#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include "libft.h"


char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t s_len;

    s_len=ft_strlen((char *)s);
    i=0; 
    if (start>s_len){
        sub=malloc((sizeof(char)));
        sub[0]=0;
        return sub;
    }
    sub=malloc((s_len-start+1)*sizeof(s));
    if (!sub)
    {
        return NULL;
    }
    // printf("s[start]:%zu\n",ft_strlen((char *)s));
    while((size_t )i<len&&start<s_len)
    {
        // printf("size:%c s[start]:%c\n",sub[i],s[start]);
        printf("s[start]:%c\n",s[start]);
        sub[i]=s[start];
        start++;
        i++;
    }
    sub[i]=0;
    return sub;
}


// static int test_substr(
//     const char *name,
//     const char *s,
//     unsigned int start,
//     size_t len,
//     const char *expected)
// {
//     char *result;

//     result = ft_substr(s, start, len);
//     if (result == NULL)
//     {
        
//         printf("FAIL: %s (returned NULL)\n", name);
//         return (0);
//     }
//     if (strcmp(result, expected) != 0)
//     {
//         printf("s:%s ,start:%d , len:%ld\n",s,start,len);
//         printf("FAIL: %s | expected: [", name);
//         printf("%s", expected);
//         printf("] got: [");
//         printf("%s", result);
//         printf("]\n");
//         free(result);
//         return (0);
//     }
//     printf("PASS: %s\n", name);
//     free(result);
//     return (1);
// }

// int main(void)
// {
//     int passed = 0;
//     int total = 0;

// #define TEST(name, s, start, len, expected) \
//     do { \
//         total++; \
//         passed += test_substr(name, s, start, len, expected); \
//     } while (0)

//     TEST("normal start", "Hello World", 0, 5, "Hello");
//     TEST("middle substring", "Hello World", 6, 5, "World");
//     TEST("length too large", "Hello World", 6, 100, "World");
//     TEST("start at end", "Hello World", 11, 1, "");
//     TEST("start past end", "Hello World", 50, 5, "");
//     TEST("zero length", "Hello World", 0, 0, "");
//     TEST("empty string", "", 0, 5, "");
//     TEST("empty string, large start", "", 10, 5, "");
//     TEST("single character result", "abc", 1, 1, "b");
//     TEST("length exceeds remaining", "abc", 2, 10, "c");
//     TEST("start equals length", "abc", 3, 10, "");
//     TEST("start beyond length", "abc", 4, 0, "");
//     TEST("digits", "0123456789", 3, 4, "3456");
//     TEST("repeated characters", "aaaaaa", 2, 3, "aaa");
//     TEST("newline character", "Hello\nWorld", 5, 6, "\nWorld");
//     TEST("leading and trailing spaces", "  hello  ", 2, 5, "hello");
//     TEST("very large len", "abcdef", 0, 1000, "abcdef");
//     TEST("last character", "abcdef", 5, 1, "f");
//     TEST("last character, excess len", "abcdef", 5, 2, "f");
//     TEST("start exactly at end", "abcdef", 6, 1, "");

//     TEST("one-character string", "a", 0, 1, "a");
//     TEST("one character, excess len", "a", 0, 2, "a");
//     TEST("one character, start at end", "a", 1, 1, "");
//     TEST("zero len in middle", "abcdef", 2, 0, "");
//     TEST("whole remaining string", "abcdef", 1, 5, "bcdef");
//     TEST("exact middle range", "abcdef", 2, 3, "cde");
//     TEST("large len near end", "abcdef", 4, 100, "ef");
//     TEST("UINT_MAX start", "abcdef", UINT_MAX, 10, "");
//     TEST("SIZE_MAX length", "abcdef", 0, SIZE_MAX, "abcdef");
//     TEST("substring with spaces", "abc def ghi", 4, 3, "def");
//     TEST("spaces inside result", "a b c", 1, 3, " b ");
//     TEST("last digit", "123456789", 8, 1, "9");
//     TEST("last digit, excess len", "123456789", 8, 2, "9");
//     TEST("start at digit string end", "123456789", 9, 1, "");
//     TEST("short substring", "abcdef", 1, 2, "bc");

// #undef TEST

//     printf("\nResult: %d/%d tests passed\n", passed, total);
//     if (passed == total)
//         printf("ALL TESTS PASS!\n");
//     else
//         printf("SOME TESTS FAILED!\n");

//     return (passed == total) ? 0 : 1;
// }
