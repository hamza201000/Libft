/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:07 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/01 17:02:58 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i_b;
    int i_l;
    int ptr=0;
    int find;

    i_b=0;
    i_l=0;
    find=0;
    
    if(!(*little))
        return (char *)big;
    // "aaabcabcd";
	// "aabc";
    while(big[i_b]&&little[i_l]&&i_b<len)
    {
        if (big[i_b]==little[i_l]&&(!find))
        {
            find=1;
            ptr=i_b;  
            i_l++;
        }else if (big[i_b]!=little[i_l]&&find){
            find=0;
            i_b=ptr+1;
            i_l=0;
            continue;
        }else if (big[i_b]==little[i_l])
            i_l++;
        i_b++;
    }
    if (little[i_l])
        return NULL;
    return (char *) &big[ptr];
}

