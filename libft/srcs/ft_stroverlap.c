/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:29:00 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/24 20:30:51 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_stroverlap(char *dst, const char *src)
{
	int		i;
	int		j;

	i = ft_strlen(src) - 1;
	j = ft_strlen(dst) - 1;
	while (i >= 0)
	{
		dst[j] = src[i];
		i--;
		j--;
	}
	return (dst);
}
