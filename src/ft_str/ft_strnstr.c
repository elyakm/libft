/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamelialaksi <kamelialaksi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:36:33 by klaksi            #+#    #+#             */
/*   Updated: 2022/10/30 14:09:23 by kamelialaks      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		while ((haystack[i + j] == needle[j] && haystack[i + j] != '\0')
			&& len > 0)
		{
			j++;
			len--;
		}
		len += j;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
		len--;
		j = 0; 
	}
	return (NULL);
}

