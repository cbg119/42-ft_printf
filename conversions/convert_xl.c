/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:44:52 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 13:54:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Yeah, the way I convert the number to an octal in string format
**	is inefficient. It possibly allocates more mem than needed. I don't care.
*/

#include "../includes/ft_printf.h"

static char						*make_hex(unsigned long long number)
{
	int						size;
	unsigned long long		temp;
	int						i;
	char					*result;
	char					*hex_string;

	i = 0;
	size = 0;
	if (!number)
		return (ft_strdup("0"));
	temp = number;
	while (temp /= 16)
		size++;
	MEM_CHK((result = (char *)malloc(sizeof(char) * size + 1)));
	hex_string = "0123456789ABCDEF";
	while (number)
	{
		result[i] = hex_string[number % 16];
		number /= 16;
		i++;
	}
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}

static char						*c_x(unsigned long long num, t_opts options)
{
	char	*new;
	char	*result;
	char	*hex;
	int		len;

	result = NULL;
	hex = make_hex(num);
	if (*hex == '0' && options.precision == 0)
		return (ft_strdup(""));
	if (options.flags.pound == 1)
	{
		new = ft_strnew(ft_strlen(hex) + 1);
		ft_memset(new, '0', ft_strlen(hex) + 1);
		hex = ft_stroverlap(new, hex);
	}
	len = ft_strlen(hex);
	if (options.precision > len)
	{
		len = options.precision;
		result = ft_strnew(len);
		ft_memset(result, '0', len);
		result = ft_stroverlap(result, hex);
		return (result);
	}
	return (hex);
}

static void						zero_pad(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
}

int								convert_xl(t_opts options, va_list ap)
{
	unsigned long long	number;
	char				*result;

	number = fetch_number(options.length, ap);
	result = c_x(number, options);
	result = ft_pad(result, options.field_width,
			ft_strlen(result), options.flags.minus);
	if (options.flags.zero == 1 && options.flags.minus == 0)
		zero_pad(result);
	ft_putstr(result);
	return (ft_strlen(result));
}
