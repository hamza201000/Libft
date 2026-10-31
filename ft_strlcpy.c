/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:02 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/31 01:27:17 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t src_len;
    size_t i;

    src_len=0;
    i=0;
    while (src[src_len]!=0)
        src_len++;
    if (size!=0){    
        while (src[i]&&i<size-1)
        {
            dst[i]=src[i];
            i++;
        }
    dst[i]=0;
    }
    return src_len;
}
