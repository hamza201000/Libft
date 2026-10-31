/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:52:23 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/31 00:26:05 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
char *ft_strrchr(const char *s, int c)
{
    int i;
    char *last;

    i=0;
    last=NULL;
    while(s[i])
    {
        if (s[i]==(unsigned char)c)
            last=((char *)&s[i]);
        i++;
    }
    if (c==0)
        return ((char *)&s[i]);
    return last;
}
