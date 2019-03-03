/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:54:55 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/02 22:13:31 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int64_t		fetch_numberi(int length, va_list ap)
{
	int64_t		n;

	if (length == 'h' + 'h')
	{
		n = va_arg(ap, int);
		return ((signed char)n);
	}
	else if (length == 'h')
	{
		n = va_arg(ap, int);
		return ((short)n);
	}
	else if (length == 'l')
		n = va_arg(ap, long);
	else if (length == 'l' + 'l')
		n = va_arg(ap, long long);
	else
		n = va_arg(ap, int);
	return (n);
}

static char			*convert_i_precision(long long number, t_opts options)
{
	int					len;
	char				*result;
	int					negative;
	unsigned long long	num;

	negative = 0;
	if (number == 0 && options.precision == 0)
		return (ft_strdup(""));
	num = (number < 0) ? -number : number;
	if (number < 0)
		negative++;
	len = ft_numlen(num);
	if (options.precision > len)
	{
		result = ft_strnew(options.precision + negative);
		ft_memset(result, '0', options.precision + negative);
		ft_intmove(result, options.precision + negative, num, negative);
		return (result);
	}
	result = ft_strnew(len + negative);
	ft_intmove(result, len + negative, num, negative);
	return (result);
}

static char			*convert_i_fieldwidth(char *str, t_opts options)
{
	str = ft_pad(str, options.field_width, ft_strlen(str), options.flags.minus);
	return (str);
}

static void			zero_pad(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
}

int					convert_i(t_opts options, va_list ap)
{
	int			count;
	char		*result;
	int64_t		number;

	count = 0;
	number = fetch_numberi(options.length, ap);
	result = convert_i_precision(number, options);
	result = convert_i_fieldwidth(result, options);
	if (options.precision == -1 && options.flags.zero && !options.flags.minus)
		zero_pad(result);
	if (options.flags.space == 1 && options.flags.plus == 0 && number > 0)
	{
		ft_putchar(' ');
		count++;
	}
	if (options.flags.plus == 1)
	{
		if (number >= 0)
		{
			ft_putchar('+');
			count++;
		}
	}
	ft_putstr(result);
	return (count + ft_strlen(result));
}
