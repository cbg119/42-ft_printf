/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:27:30 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/03 13:37:24 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						is_flag(char c)
{
	return (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0');
}

void					add_flag(t_flags *flags, char c)
{
	if (c == '#')
		flags->pound = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
}

unsigned long long		fetch_number(int length, va_list ap)
{
	unsigned long long		n;

	if (length == 'h' + 'h')
	{
		n = va_arg(ap, unsigned int);
		return ((unsigned char)n);
	}
	else if (length == 'h')
	{
		n = va_arg(ap, unsigned int);
		return ((unsigned short)n);
	}
	else if (length == 'l')
		n = va_arg(ap, unsigned long);
	else if (length == 'l' + 'l')
		n = va_arg(ap, unsigned long long);
	else
	{
		n = va_arg(ap, unsigned int);
		return ((unsigned int)n);
	}
	return (n);
}
