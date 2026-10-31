/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:45 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:46 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"






void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp;

    if (!(*lst) || !del)
    {
        return ;
    }
    while(*lst)
    {
        temp=(*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst=temp;
    }
}
