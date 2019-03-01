/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:57:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/26 23:36:11 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_intmove(char *str, int len, int64_t number)
{
	uint64_t num;

	if (number < 0)
		num = number * -1;
	else
		num = number;
	len--;
	if (num == 0)
	{
		str[len] = '0';
		return (str);
	}
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (number < 0)
		str[len] = '-';
	return (str);
}
