/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:08:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/15 13:52:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_pointer;
	unsigned char	*dst_pointer;

	i = 0;
	src_pointer = (unsigned char *)src;
	dst_pointer = (unsigned char *)dst;
	while (i < n)
	{
		dst_pointer[i] = src_pointer[i];
		i++;
	}
	return (dst);
}
