/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:52:57 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:52:58 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while(s1[i] && s2[i] && i<n)
    {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    if((s1[i] ||  s2[i]) && i<n)
    {
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return 0;
}

