/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:14:34 by vlyubick          #+#    #+#             */
/*   Updated: 2021/10/22 16:34:53 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*bonus;
	t_list	*dublist;
	t_list	*dubrez;

	if (!f || !lst)
		return (0);
	dublist = lst;
	bonus = NULL;
	while (dublist)
	{
		dubrez = ft_lstnew(f(dublist-> content));
		if (!dubrez)
		{
			ft_lstclear(&bonus, del);
			return (0);
		}
		ft_lstadd_back(&bonus, dubrez);
		dublist = dublist->next;
	}
	return (bonus);
}
