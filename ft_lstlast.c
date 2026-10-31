/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:53 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:54 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"
t_list *ft_lstlast(t_list *lst)
{
    if (lst==NULL)
    {
        return NULL;
    }
    while(lst->next!=NULL){
        lst=lst->next;
    }
    return lst;
}