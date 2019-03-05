/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:54:55 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 00:04:37 by cbagdon          ###   ########.fr       */
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
	unsigned long long	num;

	if (number == 0 && options.precision == 0)
		return (ft_strdup(""));
	num = (number < 0) ? -number : number;
	len = ft_numlen(num);
	if (options.precision > len)
	{
		result = ft_strnew(options.precision);
		ft_memset(result, '0', options.precision);
		ft_intmove(result, options.precision, num, 0);
		return (result);
	}
	result = ft_strnew(len);
	ft_intmove(result, len, num, 0);
	return (result);
}

static int			width_i(char *str, t_opts options,
							char *to_print, int is_negative)
{
	int		len;
	int		to_apply;

	to_apply = 0;
	to_apply = options.field_width;
	*to_print = (options.flags.zero && (options.precision == -1 &&
								!options.flags.minus)) ? '0' : ' ';
	len = ft_strlen(str) + ((is_negative || options.flags.space ||
				options.flags.plus) ? 1 : 0);
	return ((options.field_width > len) ? options.field_width - len : 0);
}

static void			ft_output_sign(t_opts options,
					int64_t number, int *count)
{
	if ((options.flags.plus && number >= 0) || number < 0)
	{
		if (number < 0)
		{
			ft_putchar('-');
			*count += 1;
		}
		else if (number >= 0 && options.flags.plus)
		{
			ft_putchar('+');
			*count += 1;
		}
	}
}

int					convert_i(t_opts options, va_list ap, int count,
		int negative)
{
	int			spaces;
	char		to_print;
	char		*result;
	int64_t		number;

	number = fetch_numberi(options.length, ap);
	negative = (number < 0) ? 1 : 0;
	result = convert_i_precision(number, options);
	spaces = width_i(result, options, &to_print, negative);
	if (!options.flags.minus && !options.flags.zero)
		ft_imsorry(to_print, &count, spaces);
	if (number >= 0 && options.flags.space && !options.flags.plus)
	{
		ft_putchar(' ');
		count++;
	}
	ft_output_sign(options, number, &count);
	if (!options.flags.minus && options.flags.zero)
		ft_imsorry(to_print, &count, spaces);
	ft_putstr(result);
	if (options.flags.minus)
		ft_imsorry(to_print, &count, spaces);
	count += ft_strlen(result);
	free(result);
	return (count);
}
