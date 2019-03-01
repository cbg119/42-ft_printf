/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:56:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 14:03:06 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*my_haystack;
	char		*my_needle;
	size_t		count;
	size_t		c2;

	if (!*needle)
		return ((char *)haystack);
	count = 0;
	while (*haystack && count < len)
	{
		my_haystack = (char *)haystack;
		my_needle = (char *)needle;
		c2 = count;
		while (*haystack && *my_needle && *haystack == *my_needle && c2 < len)
		{
			haystack++;
			my_needle++;
			c2++;
		}
		if (!*my_needle)
			return (my_haystack);
		haystack = my_haystack + 1;
		count++;
	}
	return (NULL);
}
