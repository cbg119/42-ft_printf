/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:09:57 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 13:55:12 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return ((*c1 - *c2));
		c1++;
		c2++;
	}
	if ((!*c2 && *c1) || (*c2 && !*c1))
		return ((*c1 - *c2));
	return (0);
}
