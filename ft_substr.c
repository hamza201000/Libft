/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:18 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:55:19 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t s_len;

    s_len=ft_strlen((char *)s);
    i=0; 
    if (start>s_len){
        sub=malloc((sizeof(char)));
        sub[0]=0;
        return sub;
    }
    sub=malloc((s_len-start+1)*sizeof(s));
    if (!sub)
    {
        return NULL;
    }
    
    while((size_t )start<len)
    {
        sub[i]=s[start];
        start++;
        i++;
    }
    sub[i]=0;
    return sub;
}
