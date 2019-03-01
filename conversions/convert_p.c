/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:14:58 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/28 01:20:00 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*make_hex(intptr_t pointer)
{
	int		i;
	char	*result;
	char	*hex_string;

	hex_string = "0123456789abcdef";
	i = 13;
	result = ft_strnew(14);
	result[0] = '0';
	result[1] = 'x';
	if (!pointer)
		result[i] = '0';
	while (pointer)
	{
		result[i] = hex_string[pointer % 16];
		pointer /= 16;
		i--;
	}
	return (result);
}

int				convert_p(t_opts options, va_list ap)
{
	char		*to_print;
	intptr_t	number;

	number = va_arg(ap, intptr_t);
	to_print = make_hex(number);
	to_print = ft_pad(to_print, options.field_width, 14, options.flags.minus);
	ft_putstr(to_print);
	return (ft_strlen(to_print));
}
