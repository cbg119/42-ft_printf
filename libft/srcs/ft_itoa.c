/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:47:13 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 13:41:55 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	int				len;
	int				negative;
	unsigned int	number;
	char			*string;

	if (n == 0)
		return (ft_strdup("0"));
	negative = (n < 0) ? 1 : 0;
	number = (n < 0) ? -n : n;
	len = ft_intlen(number) + negative;
	if (!(string = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	string[len--] = '\0';
	while (len >= 0)
	{
		string[len] = number % 10 + '0';
		number /= 10;
		len--;
	}
	if (negative)
		string[0] = '-';
	return (string);
}
