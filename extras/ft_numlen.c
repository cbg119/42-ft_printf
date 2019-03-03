/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:02:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/02 21:32:20 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen(long long num)
{
	unsigned long long	number;
	int					i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
	{
		number = -num;
		i++;
	}
	else
		number = num;
	while (number > 0)
	{
		i++;
		number /= 10;
	}
	return (i);
}
