/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:51:28 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 19:57:11 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	if (!(fresh = (void *)malloc(sizeof(void *) * size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
