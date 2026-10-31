/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:36 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:37 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t nmb_len(long n)
{
    size_t cou;

    cou=0;
    if (n<0){
        cou++;
        n*=-1;
    }else if(n==0){
        cou++;
    }
    while(n>0)
    {
        n/=10; 
        cou++;
    }
    return cou;
}

char *ft_cnv(char *nmb ,long n,size_t n_len)
{
    size_t i;

    i=n_len-1;
    if (n<0)
    {
        n*=-1;
        nmb[0]='-';
    }else if (n==0){
        nmb[0]='0';
    }
    while(n>0)
    {
        nmb[i]=n%10+'0';
        n/=10;
        i--;
    }
    nmb[n_len]=0;
    return nmb;
}


char *ft_itoa(int n)
{
    char *nmb;
    size_t n_len;
    
    n_len=nmb_len(n);
    nmb=malloc((n_len+1)*(sizeof(char)));
    if (nmb==NULL)
    {
        return NULL;
    }
    return ft_cnv(nmb ,(long) n,n_len);
}
