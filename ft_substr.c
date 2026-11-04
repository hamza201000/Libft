/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:55:18 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/04 18:16:03 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_allocation_size(size_t s_len, size_t start, size_t len)
{
	size_t	sub_len;

	if (start >= s_len)
		return (1);
	sub_len = s_len - start;
	if (len < sub_len)
		sub_len = len;
	return (sub_len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	size_t	size;

	s_len = ft_strlen((char *)s);
	i = 0;
	size = ft_allocation_size(s_len, (size_t)start, len);
	sub = malloc(size * sizeof(char));
	if (!sub)
		return (NULL);
	if (size != 1)
	{
		while (i < len && s[start])
		{
			sub[i] = s[start];
			start++;
			i++;
		}
	}
	sub[i] = 0;
	return (sub);
}
