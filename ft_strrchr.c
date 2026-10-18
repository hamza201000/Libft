#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strrchr(const char *s, int c)
{
    int i;
    char *last;

    i=0;
    last=NULL;
    while(s[i]){
        if (s[i]==c){
            last=((char *)&s[i]);
        }
        i++;
    }
    if (c==0){
        return ((char *)&s[i]);
    }
    return last;
}

static void test_strrchr(const char *s, int c)
{
    char *expected = strrchr(s, c);
    char *actual = ft_strrchr(s, c);

    if (expected == actual)
        printf("OK   | s=\"%s\", c=%d\n", s, c);
    else{
        printf("FAIL | s=\"%s\", c=%d\n", s, c);
        printf("expected=%s, actual=%s\n", expected, actual);
    }
}

int main(void)
{
    test_strrchr("hello", 'l');
    test_strrchr("hello", 'h');
    test_strrchr("hello", 'o');
    test_strrchr("hello", 'z');
    test_strrchr("", 'a');
    test_strrchr("", '\0');
    test_strrchr("hello", '\0');
    test_strrchr("aaaaa", 'a');
    test_strrchr("abcabc", 'a');
    test_strrchr("abcabc", 'c');
    test_strrchr("mississippi", 's');
    test_strrchr("abc", 'x');
    test_strrchr("1234512345", '1');
    test_strrchr("hello", 256 + 'h');
    test_strrchr("abc", 353);

    return 0;
}