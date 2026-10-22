#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char **ft_split_words(char const *s, char c ,char **arr)
{
    char *str;
    unsigned int i;
    char s2[2];
    size_t size;

    i=0;
    str="";
    size=0;
    while(s[i])
    {
        if ((s[i]==c&&s[i+1]!=c))
        {
            arr[size]=ft_strdup((const char *)str);
            str=ft_strjoin("", "");
            size++;
        }else if (s[i]!=c){
            s2[0]=s[i];
            s2[1]='\0';
            str=ft_strjoin((char const *) str, s2);
        }
        i++;
    }
    if (ft_strlen(str)!=0)
    {
        arr[size]=ft_strdup((const char *)str);
        size++;
    }
    arr[size]=NULL;
    return arr;
}




char **ft_alloc(unsigned int size, char *s)
{
    char **arr;
    size_t s_len;

    s_len=ft_strlen(s);
    if (s_len==0)
    {
        arr=malloc((1)*(sizeof(char *)));
        if (arr==NULL)
            return NULL;
        arr[0]=NULL;
        return  arr;
    }
    arr=malloc((size+2)*(sizeof(char *)));
    if (arr==NULL)
        return NULL;
    return arr;
}

char **ft_split(char const *s, char c)
{
    char **arr;
    char set[2];
    int i;
    unsigned int size;

    i=0;
    size=0;
    set[0] = c;
    set[1] = '\0';
    while(s[i])
    {
        if (s[i]==c)
            size++;
        i++;
    }
    arr=ft_alloc(size,(char *)s);
    if(arr==NULL){
        return arr;
    }
    return ft_split_words(ft_strtrim(s, set),  c ,arr);
}

static int check_split(char const *input, char delimiter,
    char **expected, int test_number)
{
    char **result;
    int i;
    int passed;

    result = ft_split(input, delimiter);
    if (!result)
    {
        printf("FAIL: Test %d (returned NULL)\n", test_number);
        return (0);
    }
    i = 0;
    passed = 1;
    while (expected[i])
    {
            //  printf("expected[%d]: %s,result[i]:%s\n",i, expected[i],result[i]);
        if (!result[i] || strcmp(result[i], expected[i]) != 0)
        {
            passed = 0;
            break;
        }
        i++;
    }
    if (result[i] != NULL)
        passed = 0;
    if (passed)
        printf("PASS: Test %d\n", test_number);
    else
    {
        printf("FAIL: Test %d\n", test_number);
        printf("  Input: \"%s\", delimiter: '%c'\n",
            input, delimiter);
        printf("  Expected words:\n");
        i = 0;
        while (expected[i])
        {
            printf("expected[%d] = \"%s\"\n", i, expected[i]);
            i++;
        }
    }
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    return (passed);
}

int main(void)
{
    int passed;
    int total;

    passed = 0;
    total = 15;

    //Test 1: Normal split
    {
        char *expected[] = {"hello", "world", "42", NULL};
        passed += check_split("hello world 42", ' ', expected, 1);
    }

    // Test 2: Multiple consecutive delimiters
    {
        char *expected[] = {"hello", "world", NULL};
        passed += check_split("hello,,,world", ',', expected, 2);
    }

    // Test 3: Leading delimiters
    {
        char *expected[] = {"hello", "world", NULL};
        passed += check_split(",,,hello,,,world", ',', expected, 3);
    }

    // Test 4: Trailing delimiters
    {
        char *expected[] = {"hello", "world", NULL};
        passed += check_split("hello,,,world,,,", ',', expected, 4);
    }

    // Test 5: Leading, trailing, and repeated delimiters
    {
        char *expected[] = {"a", "b", "c", NULL};
        passed += check_split(",,,a,,b,,,,c,,,", ',', expected, 5);
    }

    // Test 6: Empty input
    {
        char *expected[] = {NULL};
        passed += check_split("", ',', expected, 6);
    }

    // Test 7: Input contains only delimiters
    {
        char *expected[] = {NULL};
        passed += check_split(",,,,,,,", ',', expected, 7);
    }

    // Test 8: No delimiter in input
    {
        char *expected[] = {"supercalifragilistic", NULL};
        passed += check_split("supercalifragilistic", ',', expected, 8);
    }

    // Test 9: Single character, not delimiter
    {
        char *expected[] = {"X", NULL};
        passed += check_split("X", ',', expected, 9);
    }

    // Test 10: Single character, is delimiter
    {
        char *expected[] = {NULL};
        passed += check_split(",", ',', expected, 10);
    }

    // Test 11: Delimiter is a letter
{
    char *expected[] = {"h", "lloXworld", NULL};
    passed += check_split("helloXworld", 'e', expected, 11);
}

    // Test 12: Tabs are ordinary characters unless selected
    {
        char *expected[] = {"one\ttwo", "three", NULL};
        passed += check_split("one\ttwo:three", ':', expected, 12);
    }

    // Test 13: Spaces are preserved when delimiter is a comma
    {
        char *expected[] = {"  hello ", " world  ", NULL};
        passed += check_split("  hello , world  ", ',', expected, 13);
    }

    // Test 14: Alternating delimiters and characters
    {
        char *expected[] = {"a", "b", "c", "d", NULL};
        passed += check_split("a,b,c,d", ',', expected, 14);
    }

    // Test 15: Long string with many delimiters
    {
        char *expected[] = {"alpha", "beta", "gamma", "delta",
            "epsilon", NULL};
        passed += check_split(
            ",,alpha,,,,beta,,gamma,,,,,delta,epsilon,,,",
            ',', expected, 15);
    }

    printf("\nResult: %d/%d tests passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
