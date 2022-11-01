/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamelialaksi <kamelialaksi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:53:39 by klaksi            #+#    #+#             */
/*   Updated: 2022/10/30 14:09:23 by kamelialaks      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_loop(void *dst, const void *src, size_t i, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (i < len)
	{
		cdst[i] = csrc[i];
		i++;
	}
}

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (!(dst || src))
		return (NULL);
	if (cdst > csrc)
	{
		while (i < len)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	else
		ft_loop(cdst, csrc, i, len);
	return (dst);
}
