/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 17:08:14 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpush(t_list *head, t_list *new)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		head = new;
}
