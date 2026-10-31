/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:41 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 23:07:00 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
char *ft_strchr(const char *s, int c)
{
    int i;
    i=0;
    while(s[i])
    {
        if (s[i]==(unsigned char)c)
            return (( char *)&s[i]);
        i++;
    }
    if (c==0)
        return ((char *)&s[i]);
    return NULL;
}
