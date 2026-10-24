#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ft_striteri(char *s, void (*f)(unsigned int,char*))
{
    int i;

    i=0;
    while(s[i])
    {
        f(i,&s[i]);
        i++;
    }
}



void uppercase(unsigned int i, char *c)
{
    (void)i;
    *c = (char)toupper((unsigned char)*c);
}

void replace_with_index(unsigned int i, char *c)
{
    *c = (char)('0' + i % 10);
}

void uppercase_even(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = (char)toupper((unsigned char)*c);
}

void replace_with_star(unsigned int i, char *c)
{
    (void)i;
    *c = '*';
}

void alternate_xy(unsigned int i, char *c)
{
    *c = (i % 2 == 0) ? 'X' : 'Y';
}

void do_nothing(unsigned int i, char *c)
{
    (void)i;
    (void)c;
}

int main(void)
{
    char s1[] = "hello";
    char s2[] = "abcdef";
    char s3[] = "abcdef";
    char s4[] = "";
    char s5[] = "hi there";
    char s6[] = "testing";
    char s7[] = "abcdefghijk";
    char s8[] = "Hello 42!";

    ft_striteri(s1, uppercase);
    printf("Test 1: %s (expected HELLO)\n", s1);

    ft_striteri(s2, replace_with_index);
    printf("Test 2: %s (expected 012345)\n", s2);

    ft_striteri(s3, uppercase_even);
    printf("Test 3: %s (expected AbCdEf)\n", s3);

    ft_striteri(s4, uppercase);
    printf("Test 4: \"%s\" (expected empty)\n", s4);

    ft_striteri(s5, replace_with_star);
    printf("Test 5: %s (expected ********)\n", s5);

    ft_striteri(s6, do_nothing);
    printf("Test 6: %s (expected testing)\n", s6);

    ft_striteri(s7, alternate_xy);
    printf("Test 7: %s (expected XYXYXYXYXYX)\n", s7);

    ft_striteri(s8, uppercase);
    printf("Test 8: %s (expected HELLO 42!)\n", s8);

    return 0;
}
