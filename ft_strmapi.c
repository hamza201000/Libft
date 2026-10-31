/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:02 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:55:03 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    size_t s_len;
    size_t i;

    if (s == NULL || f == NULL)
        return (NULL);
    i=0;
    s_len=ft_strlen((char *)s);
    str=malloc((s_len+1)*sizeof(char));
    if (str==NULL)
    {
        return NULL;
    }
    while(s[i])
    {
        str[i]=f(i,s[i]);
        i++;
    }
    str[i]=0;
    return str;
}

