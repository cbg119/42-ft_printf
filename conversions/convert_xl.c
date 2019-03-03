/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:01:19 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 19:11:11 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Yeah, the way I convert the number to an octal in string format
**	is inefficient. It possibly allocates more mem than needed. I don't care.
*/

#include "../includes/ft_printf.h"

static char						*make_hex(unsigned long long number)
{
	int					size;
	unsigned long long	temp;
	int					i;
	char				*result;
	char				*hex_string;

	i = 0;
	size = 1;
	temp = number;
	if (!number)
		return (ft_strdup("0"));
	while (temp /= 16)
		size++;
	MEM_CHK((result = (char *)malloc(sizeof(char) * size + 1)));
	hex_string = "0123456789ABCDEF";
	result[size--] = '\0';
	while (number)
	{
		result[size] = hex_string[number % 16];
		number /= 16;
		size--;
	}
	return (result);
}

static char						*c_xl(unsigned long long num, t_opts options)
{
	char	*new;
	char	*result;
	char	*hex;
	int		len;

	result = NULL;
	hex = make_hex(num);
	if (*hex == '0' && options.precision == 0)
		return (ft_strdup(""));
	if (options.flags.pound == 1 && num != 0)
		new = ft_strjoin("0X", hex);
	else
		new = hex;
	len = ft_strlen(new);
	if (options.precision > len)
	{
		len = options.precision;
		result = ft_strnew(len);
		ft_memset(result, '0', len);
		result = ft_stroverlap(result, new);
		return (result);
	}
	return (new);
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
	int					len;
	unsigned long long	number;
	char				*result;

	number = fetch_number(options.length, ap);
	result = c_xl(number, options);
	result = ft_pad(result, options.field_width,
			ft_strlen(result), options.flags.minus);
	if (options.flags.zero == 1 && options.flags.minus == 0)
		zero_pad(result);
	ft_putstr(result);
	len = ft_strlen(result);
	free(result);
	return (len);
}
