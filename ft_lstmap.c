/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:56 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:57 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list *list;
    t_list *new_node;
    
    list=NULL;
    while(lst)
    {
        new_node=ft_lstnew(f(lst->content));
        if (!new_node)
        {
            ft_lstclear(&list,del);
            return NULL;
        }
        ft_lstadd_back(&list,new_node);
        lst=lst->next;
    }
    return list;
}
