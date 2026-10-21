
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **arr;
    // char *str;
    int i;
    int size;
    int i_arr;

    i=0;
    size=0;
    i_arr=0;
    //0123456789
    //hello world 42
    while(s[i])
    {
        if (s[i]==c){
            size++;
        }
        i++;
    }
    if (i!=0)
    {
        arr=malloc((size+1)*(sizeof(char *)));
        if (arr==NULL){
            return NULL;
        }
    }
    i=0;
    size=0;
    while(s[i])
    {
        if (s[i]==c)
        {
            arr[i_arr]=ft_substr((char const *)s,(unsigned int) size, (size_t )i);
            size=i+1;
            i_arr++;
        }
        i++;
    }
        
        
    
    return arr;
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
             printf("expected[%d]: %s\n",i, expected[i]);
        // if (!result[i] || strcmp(result[i], expected[i]) != 0)
        // {
        //     passed = 0;
        //     break;
        // }
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
            printf("    [%d] = \"%s\"\n", i, expected[i]);
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

    // Test 1: Normal split
    {
        char *expected[] = {"hello", "world", "42", NULL};
        passed += check_split("hello world 42", ' ', expected, 1);
    }

    // // Test 2: Multiple consecutive delimiters
    // {
    //     char *expected[] = {"hello", "world", NULL};
    //     passed += check_split("hello,,,world", ',', expected, 2);
    // }

    // // Test 3: Leading delimiters
    // {
    //     char *expected[] = {"hello", "world", NULL};
    //     passed += check_split(",,,hello,,,world", ',', expected, 3);
    // }

    // // Test 4: Trailing delimiters
    // {
    //     char *expected[] = {"hello", "world", NULL};
    //     passed += check_split("hello,,,world,,,", ',', expected, 4);
    // }

    // // Test 5: Leading, trailing, and repeated delimiters
    // {
    //     char *expected[] = {"a", "b", "c", NULL};
    //     passed += check_split(",,,a,,b,,,,c,,,", ',', expected, 5);
    // }

    // // Test 6: Empty input
    // {
    //     char *expected[] = {NULL};
    //     passed += check_split("", ',', expected, 6);
    // }

    // // Test 7: Input contains only delimiters
    // {
    //     char *expected[] = {NULL};
    //     passed += check_split(",,,,,,,", ',', expected, 7);
    // }

    // // Test 8: No delimiter in input
    // {
    //     char *expected[] = {"supercalifragilistic", NULL};
    //     passed += check_split("supercalifragilistic", ',', expected, 8);
    // }

    // // Test 9: Single character, not delimiter
    // {
    //     char *expected[] = {"X", NULL};
    //     passed += check_split("X", ',', expected, 9);
    // }

    // // Test 10: Single character, is delimiter
    // {
    //     char *expected[] = {NULL};
    //     passed += check_split(",", ',', expected, 10);
    // }

    // // Test 11: Delimiter is a letter
    // {
    //     char *expected[] = {"h", "llo", "world", NULL};
    //     passed += check_split("helloXworld", 'e', expected, 11);
    // }

    // // Test 12: Tabs are ordinary characters unless selected
    // {
    //     char *expected[] = {"one\ttwo", "three", NULL};
    //     passed += check_split("one\ttwo:three", ':', expected, 12);
    // }

    // // Test 13: Spaces are preserved when delimiter is a comma
    // {
    //     char *expected[] = {"  hello ", " world  ", NULL};
    //     passed += check_split("  hello , world  ", ',', expected, 13);
    // }

    // // Test 14: Alternating delimiters and characters
    // {
    //     char *expected[] = {"a", "b", "c", "d", NULL};
    //     passed += check_split("a,b,c,d", ',', expected, 14);
    // }

    // // Test 15: Long string with many delimiters
    // {
    //     char *expected[] = {"alpha", "beta", "gamma", "delta",
    //         "epsilon", NULL};
    //     passed += check_split(
    //         ",,alpha,,,,beta,,gamma,,,,,delta,epsilon,,,",
    //         ',', expected, 15);
    // }

    printf("\nResult: %d/%d tests passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
