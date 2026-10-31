/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:18 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:19 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    int *ptr;
    int i;
    
    i = 0;
    ptr = malloc(nmemb*size);
    if (!ptr)
        return NULL;
    while(ptr[i])
    {
        ptr[i]=0;
        i++;
    }
    return ptr;
}
