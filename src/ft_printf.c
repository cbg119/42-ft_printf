/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:05:07 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 01:27:05 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		dispatch_normal(char **str)
{
	ft_putchar(**str);
	(*str)++;
}

static int		dispatch_flagged(char **str, va_list ap, int count)
{
	int		i;
	t_opts	options;

	(*str)++;
	options = get_options(str, ap);
	i = -1;
	if (**str == 'i' || **str == 'd')
	{
		count = convert_i(options, ap, 0, 0);
		(*str)++;
	}
	else if (**str == '%')
	{
		count = convert_percent(options);
		(*str)++;
	}
	else
	{
		while (++i < CONVERSION_NUMBER)
			if (**str == g_table[i].key)
				count = g_table[i].convert(options, ap);
		(*str)++;
	}
	return (count);
}

int				ft_printf(char *str, ...)
{
	int			count;
	va_list		ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (is_normal(*str))
		{
			dispatch_normal(&str);
			count++;
		}
		else
			count += dispatch_flagged(&str, ap, 0);
	}
	va_end(ap);
	return (count);
}
