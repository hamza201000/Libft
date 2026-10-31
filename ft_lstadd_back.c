/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:40 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:41 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"



void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (*lst==NULL){
        *lst=new;
        return;
    }
    temp=*lst;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=new;
   
}