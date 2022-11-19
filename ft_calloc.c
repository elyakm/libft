/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:44:51 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/19 12:47:22 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	memo;
	char	*pointer;
	size_t	i;

	memo = count * size;
	pointer = malloc(memo * sizeof(char));
	i = 0;
	if (!pointer)
	{
		return (NULL);
	}
	while (i < memo)
	{
		pointer[i] = 0;
		i++;
	}
	return ((void *)pointer);
}
