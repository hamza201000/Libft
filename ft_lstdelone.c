/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:53:48 by haghomar          #+#    #+#             */
/*   Updated: 2026/10/30 18:53:49 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
    {
        return;
    }
    del(lst->content);
    del(lst);
}
