/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 22:08:39 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/02 20:42:29 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Yeah, the way I convert the number to an octal in string format
**	is inefficient. It possibly allocates more mem than needed. I don't care.
*/

#include "../includes/ft_printf.h"

static char		*make_hex(unsigned long long number)
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
	hex_string = "0123456789abcdef";
	result[size--] = '\0';
	while (number)
	{
		result[size] = hex_string[number % 16];
		number /= 16;
		size--;
	}
	return (result);
}

static void		precision_x(char *hex, t_opts options)
{
	int		len;
	char	*result;

	result = NULL;
	len = ft_strlen(hex);
	if (*hex == '0' && options.precision == 0)
	{
		free(hex);
		hex = ft_strdup("");
		return ;
	}
	if (options.precision > len)
	{
		result = ft_strnew(options.precision);
		ft_memset(result, '0', options.precision);
		ft_stroverlap(result, hex);
		free(hex);
		hex = result;
	}
}

static int		width_x(char *str, t_opts options,
		unsigned long long number, char *to_print)
{
	int		len;
	int		to_apply;

	to_apply = 0;
	*to_print = (options.flags.zero &&
			(options.precision == -1 && !options.flags.minus)) ? '0' : ' ';
	len = ft_strlen(str);
	if (options.flags.pound && number)
		options.field_width -= 2;
	if (options.field_width > len)
		to_apply += (options.field_width - len);
	return (to_apply);
}

static void		ft_imsorry(char to_print, int *len, int spaces)
{
	while (spaces-- > 0)
	{
		ft_putchar(to_print);
		*len += 1;
	}
}

int				convert_x(t_opts options, va_list ap)
{
	char				width_c;
	int					spaces;
	int					len;
	unsigned long long	number;
	char				*result;

	len = 0;
	number = fetch_number(options.length, ap);
	result = make_hex(number);
	precision_x(result, options);
	spaces = width_x(result, options, number, &width_c);
	if (!options.flags.minus && !options.flags.zero)
		ft_imsorry(width_c, &len, spaces);
	if (options.flags.pound && number)
	{
		ft_putstr("0x");
		len += 2;
	}
	if (!options.flags.minus && options.flags.zero)
		ft_imsorry(width_c, &len, spaces);
	ft_putstr(result);
	if (options.flags.minus)
		ft_imsorry(width_c, &len, spaces);
	len += ft_strlen(result);
	return (len);
}
