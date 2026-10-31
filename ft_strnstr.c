/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:07 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:55:08 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{


    size_t i_b;
    size_t i_l;
    char *ptr;
    int find;

    i_b=0;
    i_l=0;
    find=0;
    
    if(!little[i_l]){
        return (char *)big;
    }
    while(little[i_l] && big[i_b] )
    {   
        i_l=0;
        while (little[i_l] && big[i_b]&&little[i_l]==big[i_b]&& i_b<len)
        {
            if (!find){
                ptr=(char *)&big[i_b];
                find=1;
            }
            i_b++;
            i_l++;
        }
        i_b++;
    }
    if (little[i_l]){
        return NULL;
    }
    return ptr;
}

