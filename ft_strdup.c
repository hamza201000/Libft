/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:44 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:54:45 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char *ft_strdup(const char *s)
{
    int i;
    char *copy;

    copy=malloc((ft_strlen((char *)s)+1)*sizeof(char));
    i=0;
    while(s[i]!=0)
    {
        copy[i]=s[i];
        i++;
    }
    copy[i]=0;
    return copy;
}
