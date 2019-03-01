/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:50:06 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 13:53:10 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Yeah, the way I convert the number to an octal in string format
**	is inefficient. It possibly allocates more mem than needed. I don't care.
*/

#include "../includes/ft_printf.h"

static char						*make_octal(unsigned long long number)
{
	int		i;
	char	*result;
	char	*octal_string;

	i = 0;
	MEM_CHK((result = (char *)malloc(sizeof(char) * OCTAL_MAX + 1)));
	octal_string = "01234567";
	if (!number)
		result[i] = '0';
	while (number)
	{
		result[i] = octal_string[number % 8];
		number /= 8;
		i++;
	}
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}

static char						*c_o(unsigned long long num, t_opts options)
{
	char	*new;
	char	*result;
	char	*octal;
	int		len;

	result = NULL;
	octal = make_octal(num);
	if (*octal == '0' && options.precision == 0)
		return (ft_strdup(""));
	if (options.flags.pound == 1)
	{
		new = ft_strnew(ft_strlen(octal) + 1);
		ft_memset(new, '0', ft_strlen(octal) + 1);
		octal = ft_stroverlap(new, octal);
	}
	len = ft_strlen(octal);
	if (options.precision > len)
	{
		len = options.precision;
		result = ft_strnew(len);
		ft_memset(result, '0', len);
		result = ft_stroverlap(result, octal);
		return (result);
	}
	return (octal);
}

static void						zero_pad(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
}

int								convert_o(t_opts options, va_list ap)
{
	unsigned long long	number;
	char				*result;

	number = fetch_number(options.length, ap);
	result = c_o(number, options);
	result = ft_pad(result, options.field_width,
			ft_strlen(result), options.flags.minus);
	if (options.flags.zero == 1 && options.flags.minus == 0)
		zero_pad(result);
	ft_putstr(result);
	return (ft_strlen(result));
}
