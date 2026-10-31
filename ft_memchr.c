/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:05 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:54:06 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *new_s;
    unsigned char new_c;
    
    i=0;
    new_s=(unsigned char *)s;
    new_c=(unsigned char )c;
    while (i<n)
    {
        if (new_s[i]==new_c)
        {
            return ((void *)&new_s[i]);
        }
        i++;
    }
    if (new_c==0&& i<n){
        return ((void *)&new_s[i]);
    }
    return NULL;
}
