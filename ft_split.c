/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:13:19 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/19 12:47:22 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_splitted(char const *s, char c, int *index)
{
	char	*str;
	size_t	i;
	int		j;

	j = *index;
	i = 0;
	while (s[j] == c)
		j++;
	while (s[j] && s[j] != c)
	{
		j++;
		i++;
	}
	str = ft_substr(s, j - i, i);
	*index = j;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	size_t		i;
	int			j;

	if (!s)
		return (NULL);
	i = 0;
	str = ft_calloc(sizeof(char *), ft_count(s, c) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (i < ft_count(s, c))
	{
		str[i] = ft_splitted(s, c, &j);
		i++;
	}
	return (str);
}
