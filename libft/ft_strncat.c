/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:13:52 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 13:51:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (*s2)
	{
		i = 0;
		len = 0;
		while (s1[len])
			len++;
		while (s2[i] && i < n)
		{
			s1[len + i] = s2[i];
			i++;
		}
		s1[len + i] = '\0';
	}
	return (s1);
}
