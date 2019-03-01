/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:59:16 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 16:02:32 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*pointer;

	i = 0;
	pointer = b;
	while (i < len)
	{
		pointer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
