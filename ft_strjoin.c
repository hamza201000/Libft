#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t i_s2;
    char *str;

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
