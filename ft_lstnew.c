/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:59 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:54:00 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content){
    t_list *Node;

    Node=malloc(sizeof(t_list));
    if (Node==NULL)
    {
        return NULL;
    }
    (*Node).content=content;
    (*Node).next=NULL;
    return Node;
}

