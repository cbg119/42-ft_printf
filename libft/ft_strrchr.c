/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:56:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 14:04:59 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**I spent way too long debugging this fucking pointer. Turns out if you
**forget to set it to NULL, you have a completely wrong return value
**with non-found chars and empty strings. Feels good.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	char	*pointer2;

	pointer = NULL;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while ((pointer2 = ft_strchr(s, c)) != NULL)
	{
		pointer = pointer2;
		s = pointer2 + 1;
	}
	return ((char *)pointer);
}
