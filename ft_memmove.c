#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{

    unsigned char *new_dest;
    const unsigned char *new_src;
    size_t i;

    i = 0;
    new_dest = dest;
    new_src = src;

    if (dest > src)
    {
        printf("in");
        while (n > 0)
        {
            n--;
            new_dest[n] = new_src[n];
        }
    }
    else
    {
        while (i < n)
        {
            new_dest[i] = new_src[i];
            i++;
        }
    }
    return dest;
}

int main(void)
{
    char s[] = "ABCDE";

    ft_memmove(s, s + 2, 3);

    printf("%s\n", s);
    char s2[] = "ABCDE";
    memmove(s2, s2 + 2, 3);
    printf("%s\n", s2);
    return 0;
}