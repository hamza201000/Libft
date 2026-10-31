/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:16 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:54:17 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char  *new_dest;
    const unsigned char *new_src;
    size_t i;

    new_dest=dest;
    new_src=src;
    i=0;
    while(i<n){
        new_dest[i]=new_src[i];
        i++;
    }
    return dest;
}
