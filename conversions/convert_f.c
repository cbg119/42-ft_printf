/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:42:38 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 00:00:27 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double		fetch_numberf(int length, va_list ap)
{
	long double		number;

	if (length == 'L')
		number = va_arg(ap, long double);
	else
	{
		number = va_arg(ap, double);
		return ((double)number);
	}
	return (number);
}

static int				f_len(long double number, t_opts options)
{
	int						len;
	unsigned long long		whole;

	len = 0;
	number = (number < 0) ? -number : number;
	whole = (unsigned long long)number;
	len += ft_numlen(whole);
	len += (options.precision > 0 || options.flags.pound) ? 1 : 0;
	len += options.precision;
	return (len);
}

static int				width_f(int f_len, t_opts options, char *to_print,
		int is_negative)
{
	int		len;

	*to_print = (options.flags.zero && (options.precision == 6 &&
				!options.flags.minus)) ? '0' : ' ';
	len = f_len + ((is_negative || options.flags.space ||
				options.flags.plus) ? 1 : 0);
	return ((options.field_width > len) ? options.field_width - len : 0);
}

static void				f_putsign(int *count, long double number,
		t_opts options)
{
	if (number < 0)
	{
		ft_putchar('-');
		*count += 1;
	}
	else if (options.flags.plus && number >= 0)
	{
		ft_putchar('+');
		*count += 1;
	}
}

int						convert_f(t_opts options, va_list ap)
{
	int				count;
	long double		number;
	int				spaces;
	char			to_print;

	count = 0;
	number = fetch_numberf(options.length, ap);
	if (options.precision == -1)
		options.precision = 6;
	count += f_len(number, options);
	spaces = width_f(count, options, &to_print, number < 0);
	if (!options.flags.minus && !options.flags.zero)
		ft_imsorry(to_print, &count, spaces);
	if (number >= 0 && options.flags.space && !options.flags.plus)
	{
		ft_putchar(' ');
		count++;
	}
	f_putsign(&count, number, options);
	if (!options.flags.minus && options.flags.zero)
		ft_imsorry(to_print, &count, spaces);
	pf_putfloat(number, options);
	if (options.flags.minus)
		ft_imsorry(to_print, &count, spaces);
	return (count);
}
