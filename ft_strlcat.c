/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 01:55:21 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/31 02:23:16 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dest_len;
    size_t src_len;
    size_t i;

    dest_len=0;
    src_len=0;
    i=0;
    while (dst[dest_len] && dest_len < size)
        dest_len++;
    while (src[src_len])
        src_len++;
    if (dest_len == size)
        return (size + src_len);
    while (src[i]&&dest_len<size-1){
        dst[dest_len]=src[i];
        dest_len++;
        i++;
    }
    dst[dest_len]=0;
    return (dest_len+src_len-size);
}
