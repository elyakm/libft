/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:13:19 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/20 09:12:14 by klaksi           ###   ########.fr       */
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
	if (!str)
		return (NULL);
	*index = j;
	return (str);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	size_t	len;

	len = ft_count(s, c);
	if (!s)
		return (NULL);
	i = 0;
	str = ft_calloc(len + 1, sizeof(char *));
	if (!str)
		return (NULL);
	j = 0;
	while (i < len)
	{
		str[i] = ft_splitted(s, c, &j);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}
