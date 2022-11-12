/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamelialaksi <kamelialaksi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:19:36 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/11 21:02:43 by kamelialaks      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = *lst->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
}
