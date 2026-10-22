#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i;
    size_t i_s2;

    i_s2=0;
    i=0;
    str=malloc((ft_strlen((char *)s1)+ft_strlen((char *)s2)+1)*(sizeof(char)));
    if (!str){
        return NULL;
    }
    while(s1[i])
    {
        str[i]=s1[i];
        i++;
    }
    while(s2[i_s2])
    {
        str[i]=s2[i_s2];
        i_s2++;
        i++;
    }
    str[i]=0;
    return str;
}


// static int test_strjoin(
//     const char *name,
//     const char *s1,
//     const char *s2,
//     const char *expected)
// {
//     char *result;

//     result = ft_strjoin(s1, s2);
//     if (result == NULL)
//     {
//         printf("FAIL: %s (returned NULL)\n", name);
//         return (0);
//     }
//     if (result == s1 || result == s2)
//     {
//         printf("FAIL: %s (did not return a new string)\n", name);
//         free(result);
//         return (0);
//     }
//     if (strcmp(result, expected) != 0)
//     {
//         printf("FAIL: %s | expected: [%s] got: [%s]\n",
//             name, expected, result);
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

// #define TEST(name, s1, s2, expected) \
//     do { \
//         total++; \
//         passed += test_strjoin(name, s1, s2, expected); \
//     } while (0)

//     /* Basic tests */
//     TEST("normal concatenation", "Hello", "World", "HelloWorld");
//     TEST("space between words", "Hello ", "World", "Hello World");
//     TEST("empty prefix", "", "World", "World");
//     TEST("empty suffix", "Hello", "", "Hello");
//     TEST("both empty", "", "", "");
//     TEST("single characters", "a", "b", "ab");
//     TEST("spaces only", " ", " ", "  ");
//     TEST("same strings", "Hello", "Hello", "HelloHello");
//     TEST("numbers", "123", "456", "123456");
//     TEST("suffix starts with space", "abc", " def", "abc def");
//     TEST("spaces on both sides", "abc ", " def", "abc  def");
//     TEST("42 School", "42", " School", "42 School");
//     TEST("newline", "Hello\n", "World", "Hello\nWorld");
//     TEST("tab", "Hello\t", "World", "Hello\tWorld");
//     TEST("long suffix", "abc", "123456789", "abc123456789");
//     TEST("long prefix", "123456789", "abc", "123456789abc");
//     TEST("special characters", "!", "@#$%^&*", "!@#$%^&*");
//     TEST("foo and bar", "foo", "bar", "foobar");
//     TEST("suffix empty", "end", "", "end");
//     TEST("prefix empty", "", "start", "start");

//     /* Edge cases */
//     TEST("one char and empty suffix", "a", "", "a");
//     TEST("empty prefix and one char", "", "a", "a");
//     TEST("two single chars", "a", "b", "ab");
//     TEST("two plus one", "ab", "c", "abc");
//     TEST("one plus two", "a", "bc", "abc");
//     TEST("long strings", "abcdef", "ghijkl", "abcdefghijkl");
//     TEST("digits", "12345", "67890", "1234567890");
//     TEST("two newline endings", "line1\n", "line2\n", "line1\nline2\n");
//     TEST("six spaces", "   ", "   ", "      ");
//     TEST("spaces within strings", "abc def", " ghi jkl", "abc def ghi jkl");
//     TEST("uppercase then lowercase", "UPPER", "lower", "UPPERlower");
//     TEST("lowercase then uppercase", "lower", "UPPER", "lowerUPPER");
//     TEST("symbols", "!@#", "$%^", "!@#$%^");
//     TEST("multiple newlines", "first\nsecond", "\nthird", "first\nsecond\nthird");
//     TEST("repeated strings", "abc", "abc", "abcabc");

// #undef TEST

//     printf("\nResult: %d/%d tests passed\n", passed, total);
//     if (passed == total)
//         printf("ALL TESTS PASS!\n");
//     else
//         printf("SOME TESTS FAILED!\n");

//     return (passed == total) ? 0 : 1;
// }
