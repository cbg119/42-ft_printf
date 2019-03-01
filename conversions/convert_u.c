/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:12:04 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/28 22:05:47 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long       fetch_number(int length, va_list ap)
{
    uint64_t        n;

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
        n = va_arg(ap, unsigned int);
    return (n);
}

static char						*c_u(unsigned long long num, t_opts options)
{
	int		len;
	char	*result;

	if (num == 0 && options.precision == 0)
		return (ft_strdup(""));
	len = ft_numlen(num);
	if (options.precision > len)
	{
		len = options.precision;
		result = ft_strnew(len);
		ft_memset(result, '0', len);
		result = ft_intmove(result, len, num);
		return (result);
	}
	result = ft_itoa(num);
	return (result);
}

static void						zero_pad(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
}

int								convert_u(t_opts options, va_list ap)
{
	int					count;
	unsigned long long	number;
	char				*result;

	count = 0;
	number = fetch_number(options.length, ap);
	result = c_u(number, options);
	result = ft_pad(result, options.field_width, ft_strlen(result),
			options.flags.minus);
	if (options.flags.zero == 1 && options.flags.minus == 0)
		zero_pad(result);
	ft_putstr(result);
	return (ft_strlen(result));
}
