/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:27:25 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 14:41:30 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar('-');
		number = -n;
	}
	else
		number = n;
	if (number >= 10)
		ft_putnbr(number / 10);
	ft_putchar((number % 10) + '0');
}
