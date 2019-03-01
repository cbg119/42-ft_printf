/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:30:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 17:41:07 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i) && i < n - 1)
		i++;
	return (*((unsigned char *)(s1 + i)) - *(((unsigned char *)s2 + i)));
}
