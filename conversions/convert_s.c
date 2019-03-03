/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:47:12 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/02 22:17:36 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	error(void)
{
	ft_putstr("(null)");
	return (6);
}

int		convert_s(t_opts options, va_list ap)
{
	int		i;
	int		length;
	char	*string;
	char	*new_string;

	i = 0;
	string = va_arg(ap, char *);
	if (!string)
		return (error());
	length = ft_strlen(string);
	if (options.precision != -1 && options.precision < length)
		length = options.precision;
	new_string = ft_strndup(string, length);
	new_string = ft_pad(new_string, options.field_width,
			ft_strlen(new_string), options.flags.minus);
	if (options.precision == -1 && options.flags.zero)
	{
		while (new_string[i] == ' ' && (i < (int)ft_strlen(new_string) -
				options.field_width))
			new_string[i++] = '0';
	}
	ft_putstr(new_string);
	return (ft_strlen(new_string));
}
