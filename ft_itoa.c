/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:03:32 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/19 12:47:22 by klaksi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_num(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill_str(char *result, int n, size_t count_num)
{
	int	negative;

	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	while (count_num > 0)
	{
		result[count_num - 1] = (n % 10) + '0';
		n /= 10;
		count_num--;
	}
	if (negative)
		result[0] = '-';
	result[ft_strlen(result)] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	count_num;

	count_num = ft_count_num(n);
	if (n < -2147483647)
	{
		result = (char *)ft_calloc(12, sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
		return (result);
	}
	result = (char *)ft_calloc(count_num + 1, sizeof(char));
	if (!result)
		return (NULL);
	return (ft_fill_str(result, n, count_num));
}
