/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:13 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:55:14 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int ft_check_char(const char character,char const *set){

    int i;

    i=0;
    while(set[i]){
        if (set[i]==character){
            return 1;
        }
        i++;
    }

    return 0;
}


char *ft_strtrim(char const *s1, char const *set){
    char *str;
    size_t i;
    size_t s_len;
    int     in;

    i=0;
    in=0;
    s_len=ft_strlen((char *)s1);
    
    while(s1[i])
    {
        if (ft_check_char(s1[i],set))
            i++;
        else
            break;
    }
    while(s_len>i)
    {
        if (ft_check_char(s1[s_len-1],set))
            s_len--;
        else
            break;
    }
    str=malloc((s_len-i+1)*(sizeof(char)));
    if (!str)
    {
        return NULL;
    }
    while(i<s_len){
        str[in]=s1[i];
        in++;
        i++;
    }
    str[in]=0;
    return str;
}


