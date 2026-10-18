#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c){
    int i;
    i=0;
    while(s[i]){
        if (s[i]==c){
            return ((char *)&s[i]);
        }
        i++;
    }
    if (c==0){
        return ((char *)&s[i]);
    }
    return NULL;
}





static void test_strchr(const char *s, int c)
{
    char *expected = strchr(s, c);
    char *actual = ft_strchr(s, c);

    if (expected == actual)
        printf("OK   | s=\"%s\", c=%d\n", s, c);
    else{
        printf("FAIL | s=\"%s\", c=%d\n", s, c);
        printf("expected=%s, actual=%s\n", expected, actual);
    }
}

int main(void)
{
    test_strchr("hello", 'h');
    test_strchr("hello", 'l');
    test_strchr("hello", 'z');
    test_strchr("", 'a');
    test_strchr("hello", '\0');
    test_strchr("aaaaa", 'a');
    test_strchr("abcabc", 'c');
    test_strchr("hello", 256 + 'h');
    test_strchr("hello", -1);
    test_strchr("123456789", '5');
    test_strchr("abc", 0);
    test_strchr("abc", '\n');

    return 0;
}
