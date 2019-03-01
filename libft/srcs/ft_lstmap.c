/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:44:57 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 17:12:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;

	if (lst)
	{
		new_list = (*f)(lst);
		lst = lst->next;
		while (lst)
		{
			ft_lstpush(new_list, (*f)(lst));
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}
