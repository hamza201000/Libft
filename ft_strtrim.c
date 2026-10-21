#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int ft_check_char(const char character,char const *set){

    int i;

    i=0;
    while(set[i]){
        if (set[i]==character){
            return 1;
        }
        i++;
    }

    return 0;
}


char *ft_strtrim(char const *s1, char const *set){
    char *str;
    size_t i;
    size_t s_len;
    int     in;

    i=0;
    in=0;
    s_len=ft_strlen((char *)s1);
    
    while(s1[i])
    {
        if (ft_check_char(s1[i],set))
        {
            i++;
        }else
        {
            break;
        }
    }
    while(s_len>i)
    {
        if (ft_check_char(s1[s_len-1],set))
        {
            s_len--;
        }else
        {
            break;
        }
    }
    str=malloc((s_len-i+1)*(sizeof(char)));
    if (!str)
    {
    printf("is here\n");
        return NULL;
    }
    while(i<s_len){
        str[in]=s1[i];
        in++;
        i++;
    }
    str[in]=0;
    return str;
}



int main(void)
{
    char *result;
    int passed = 0;
    int total = 12;

    // Test 1: Trim different characters from both ends
    result = ft_strtrim("xyxyHelloWorldyxyx", "xy");
    if (result && strcmp(result, "HelloWorld") == 0)
        { printf("PASS: Test 1\n"); passed++; }
    else
        printf("FAIL: Test 1\n");
    free(result);

    // Test 2: Entire string consists of trim characters
    result = ft_strtrim("xyzxyzxyz", "xyz");
    if (result && strcmp(result, "") == 0)
        { printf("PASS: Test 2\n"); passed++; }
    else
        printf("FAIL: Test 2\n");
    free(result);

    // Test 3: Empty input string
    result = ft_strtrim("", "abc");
    if (result && strcmp(result, "") == 0)
        { printf("PASS: Test 3\n"); passed++; }
    else
        printf("FAIL: Test 3\n");
    free(result);

    // Test 4: Empty set
    result = ft_strtrim("Hello World", "");
    if (result && strcmp(result, "Hello World") == 0)
        { printf("PASS: Test 4\n"); passed++; }
    else
        printf("FAIL: Test 4\n");
    free(result);

    // Test 5: No characters need trimming
    result = ft_strtrim("Hello", " ");
    if (result && strcmp(result, "Hello") == 0)
        { printf("PASS: Test 5\n"); passed++; }
    else
        printf("FAIL: Test 5\n");
    free(result);

    // Test 6: Only the first character is preserved
    result = ft_strtrim("xxxAxxx", "x");
    if (result && strcmp(result, "A") == 0)
        { printf("PASS: Test 6\n"); passed++; }
    else
        printf("FAIL: Test 6\n");
    free(result);

    // Test 7: Trim characters appear inside the string
    result = ft_strtrim("xxHexlloWorldxx", "x");
    if (result && strcmp(result, "HexlloWorld") == 0)
        { printf("PASS: Test 7\n"); passed++; }
    else
        printf("FAIL: Test 7\n");
    free(result);

    // Test 8: Spaces and tabs in the trim set
    result = ft_strtrim("\t\n  Hello World  \n\t", " \t\n");
    if (result && strcmp(result, "Hello World") == 0)
        { printf("PASS: Test 8\n"); passed++; }
    else
        printf("FAIL: Test 8\n");
    free(result);

    // Test 9: One-character input that must be trimmed
    result = ft_strtrim("a", "a");
    if (result && strcmp(result, "") == 0)
        { printf("PASS: Test 9\n"); passed++; }
    else
        printf("FAIL: Test 9\n");
    free(result);

    // Test 10: One-character input that must be preserved
    result = ft_strtrim("Z", "abc");
    if (result && strcmp(result, "Z") == 0)
        { printf("PASS: Test 10\n"); passed++; }
    else
        printf("FAIL: Test 10\n");
    free(result);

    // Test 11: Long trim set with overlapping characters
    result = ft_strtrim("abcdeKEEPfedcba", "abcdef");
    if (result && strcmp(result, "KEEP") == 0)
        { printf("PASS: Test 11\n"); passed++; }
    else
        printf("FAIL: Test 11\n");
    free(result);

    // Test 12: Repeated trim characters on both sides
    result = ft_strtrim("0000001234500000", "0");
    if (result && strcmp(result, "12345") == 0)
        { printf("PASS: Test 12\n"); passed++; }
    else
        printf("FAIL: Test 12\n");
    free(result);

    printf("\nResult: %d/%d tests passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}

