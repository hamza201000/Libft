/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:07 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/03 21:00:14 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_add_index(int *find, int index, int *i_l, size_t *i_b)
{
	*find = 0;
	*i_b = index;
	*i_l = 0;
}

static void	ft_set_index(int *find, int *index, int *i_l, size_t i_b)
{
	*find = 1;
	*index = i_b;
	(*i_l)++;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	int		i_l;
	int		index;
	int		find;

	i_b = 0;
	i_l = 0;
	find = 0;
	index = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i_b] && little[i_l] && i_b < len)
	{
		if (big[i_b] == little[i_l] && (!find))
			ft_set_index(&find, &index, &i_l, i_b);
		else if (big[i_b] != little[i_l] && find)
			ft_add_index(&find, index, &i_l, &i_b);
		else if (big[i_b] == little[i_l])
			i_l++;
		i_b++;
	}
	if (little[i_l])
		return (NULL);
	return ((char *)&big[index]);
}
