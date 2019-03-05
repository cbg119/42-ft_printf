/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:06:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 00:06:25 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_putfloat(long double number, t_opts options)
{
	long double			num;
	int					negative;
	long long			whole;

	num = (number < 0) ? -number : number;
	negative = (number < 0) ? -1 : 1;
	whole = (unsigned long long)num;
	if (num - whole >= 0.5 && options.precision == 0)
		whole += 1;
	num -= whole;
	ft_putnbr(whole);
	if (options.precision <= 15)
		num += 0.0000000000000001;
	if (options.precision > 0 || options.flags.pound)
		ft_putchar('.');
	if (options.precision != 0)
		while (options.precision)
		{
			num *= 10;
			whole = (unsigned long long)num;
			num -= whole;
			whole %= 10;
			ft_putchar(whole + '0');
			options.precision--;
		}
}
