/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:37 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:54:38 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
