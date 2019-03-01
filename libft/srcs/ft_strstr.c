/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:23:30 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 13:52:10 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*my_haystack;
	char	*my_needle;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		my_haystack = (char *)haystack;
		my_needle = (char *)needle;
		while (*haystack && *my_needle && *haystack == *my_needle)
		{
			haystack++;
			my_needle++;
		}
		if (!*my_needle)
			return (my_haystack);
		haystack = my_haystack + 1;
	}
	return (NULL);
}
