#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    size_t s_len;
    size_t i;

    if (s == NULL || f == NULL)
        return (NULL);
    i=0;
    s_len=ft_strlen((char *)s);
    str=malloc((s_len+1)*sizeof(char));
    if (str==NULL)
    {
        return NULL;
    }
    while(s[i])
    {
        str[i]=f(i,s[i]);
        i++;
    }
    str[i]=0;
    return str;
}



char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Test 1: Convert lowercase letters to uppercase */
char    to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

/* Test 2: Use the index AND the character */
char    index_transform(unsigned int i, char c)
{
    return (c + i);
}

/* Test 3: Alternate uppercase and lowercase */
char    alternate_case(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return (c - 32);
    if (i % 2 != 0 && c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

/* Test 4: Replace every character with its index digit */
char    index_digit(unsigned int i, char c)
{
    (void)c;
    return ('0' + (i % 10));
}

/* Test 5: Replace every character with a null byte */
char    null_char(unsigned int i, char c)
{
    (void)i;
    (void)c;
    return ('\0');
}

static void run_test(char const *name, char const *input,
    char (*f)(unsigned int, char), char const *expected)
{
    char    *result;
    int     passed;

    result = ft_strmapi(input, f);
    if (result == NULL)
    {
        printf("[FAIL] %s: returned NULL\n", name);
        return ;
    }
    passed = (memcmp(result, expected, strlen(expected) + 1) == 0);
    if (passed)
        printf("[PASS] %s\n", name);
    else
        printf("[FAIL] %s\n", name);
    if (!passed)
    {
        printf("  Expected: \"%s\"\n", expected);
        printf("  Got:      \"%s\"\n", result);
    }
    free(result);
}

int main(void)
{
    char    *result;

    printf("=== ft_strmapi tests ===\n");

    run_test("Basic uppercase", "hello", to_upper, "HELLO");
    run_test("Empty string", "", to_upper, "");
    run_test("Single character", "z", to_upper, "Z");
    run_test("Already uppercase", "HELLO", to_upper, "HELLO");
    run_test("Digits and punctuation", "a1!b?9", to_upper, "A1!B?9");
    run_test("Index + character", "abcd", index_transform, "aceg");
    run_test("Alternating case", "hELLo", alternate_case, "HeLlO");
    run_test("Index beyond 9", "abcdefghijkl", index_digit,
        "012345678901");

    /*
     * A result may contain '\0' in the middle.
     * Check bytes directly, not with printf("%s").
     */
    result = ft_strmapi("abc", null_char);
    if (result != NULL && result[0] == '\0'
        && result[1] == '\0' && result[2] == '\0'
        && result[3] == '\0')
        printf("[PASS] Embedded null bytes\n");
    else
        printf("[FAIL] Embedded null bytes\n");
    free(result);

    /*
     * Optional robustness test. Only run if your implementation
     * is intended to handle NULL input.
     */
    result = ft_strmapi(NULL, to_upper);
    if (result == NULL)
        printf("[PASS] NULL input (optional)\n");
    else
    {
        printf("[FAIL] NULL input (optional)\n");
        free(result);
    }

    return (0);
}
