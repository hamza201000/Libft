/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:54:37 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/04 00:50:13 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"

static char	*ft_char_to_str(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static char	**ft_split_words(char const *s, char c, char **arr,
		unsigned int i)
{
	size_t	size;
	char	*str;
	char	*tmp;
	char	*new_str;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	size = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			arr[size] = ft_strdup(str);
			if (!arr[size++])
				return (free(str), NULL);
			free(str);
			str = ft_strdup("");
			if (!str)
				return (NULL);
		}
		else if (s[i] != c)
		{
			tmp = ft_char_to_str(s[i]);
			if (!tmp)
				return (free(str), NULL);
			new_str = ft_strjoin(str, tmp);
			free(tmp);
			free(str);
			if (!new_str)
				return (NULL);
			str = new_str;
		}
		i++;
	}
	if (ft_strlen(str) != 0)
	{
		arr[size] = ft_strdup(str);
		if (!arr[size++])
			return (free(str), NULL);
	}
	arr[size] = NULL;
	free(str);
	return (arr);
}

static char	**ft_alloc(unsigned int size)
{
	char	**arr;

	arr = malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			set[2];
	unsigned int	size;
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	str = ft_strtrim(s, set);
	if (!str)
		return (NULL);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			size++;
		i++;
	}
	if (str[0] != '\0')
		size++;
	arr = ft_alloc(size);
	if (!arr)
		return (free(str), NULL);
	arr = ft_split_words(str, c, arr, 0);
	free(str);
	if (!arr)
		return (NULL);
	return (arr);
}
