#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while(s1[i] && s2[i] && i<n)
    {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    if((s1[i] ||  s2[i]) && i<n)
    {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return 0;
}


int main(void)
{
    char *s1[] = {"abc", "abc", "abc", "", "ab", "abd", "hello","é"};
    char *s2[] = {"abc", "abd", "abc", "a", "abcd", "abc", "Hello","eze"};
    size_t n[] = {3, 3, 0, 1, 10, 2, 5};

    int i = 0;
    int real;
    int mine;

    while (i < 8)
    {
        real = strncmp(s1[i], s2[i], n[i]);
        mine = ft_strncmp(s1[i], s2[i], n[i]);
        printf("s1:%s  s2:%s\n",s1[i],s2[i]);
        printf("Test %d: real = %d, mine = %d : %s\n",
            i + 1, real, mine,
            (real < 0 && mine < 0) ||
            (real > 0 && mine > 0) ||
            (real == 0 && mine == 0) ? "OK" : "FAIL");
        i++;
    }
    return (0);
}