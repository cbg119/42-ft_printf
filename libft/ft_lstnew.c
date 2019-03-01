/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:51:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/15 14:13:08 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*pointer;

	if (!(pointer = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		pointer->content = NULL;
		pointer->content_size = 0;
	}
	else
	{
		if (!(pointer->content = (void *)malloc(content_size)))
		{
			free(pointer);
			return (NULL);
		}
		ft_memcpy(pointer->content, content, content_size);
		pointer->content_size = content_size;
	}
	pointer->next = NULL;
	return (pointer);
}
