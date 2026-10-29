
#include "libft.h"


char *ft_strdup(const char *s)
{
    int i;
    char *copy;

    copy=malloc((ft_strlen((char *)s)+1)*sizeof(char));
    i=0;
    while(s[i]!=0)
    {
        copy[i]=s[i];
        i++;
    }
    copy[i]=0;
    return copy;
}
