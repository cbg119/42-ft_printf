/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:57:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/02 22:11:04 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_intmove(char *str, int len, unsigned long long number, int negative)
{
	len--;
	if (number == 0)
	{
		str[len] = '0';
		return ;
	}
	while (number > 0)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	if (negative == 1)
		str[len] = '-';
}
