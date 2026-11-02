/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:18 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/01 22:57:37 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void *ft_calloc(size_t nmemb, size_t size)
{
    void  *ptr;

    if (nmemb==0 || size==0)
        return  malloc(1);
    ptr = malloc(nmemb*size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr,nmemb*size);
    return ptr;
}
