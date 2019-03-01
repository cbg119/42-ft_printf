/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:05:07 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 13:02:15 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

static void		dispatch_normal(char **str)
{
	ft_putchar(**str);
	(*str)++;
}

static int		dispatch_flagged(char **str, va_list ap)
{
	int		count;
	t_opts	options;

	(*str)++;
	count = 0;
	options = get_options(str, ap);
	if (**str == 's')
	{
		count = convert_s(options, ap);
		(*str)++;
	}
	else if (**str == 'i' || **str == 'd')
	{
		count = convert_i(options, ap);
		(*str)++;
	}
	else if (**str == 'c')
	{
		count = convert_c(options, ap);
		(*str)++;
	}
	else if (**str == 'p')
	{
		count = convert_p(options, ap);
		(*str)++;
	}
	else if (**str == 'o')
	{
		count = convert_o(options, ap);
		(*str)++;
	}
	else if (**str == 'u')
	{
		count = convert_u(options, ap);
		(*str)++;
	}
	else if (**str == 'x')
	{
		count = convert_x(options, ap);
		(*str)++;
	}
	else if (**str == 'X')
	{
		count = convert_X(options, ap);
		(*str)++;
	}
	else if (**str == '%')
	{
		count = convert_percent(options);
		(*str)++;
	}
	else
	{
		count++;
		ft_putchar(**str);
	}
	return (count);
}

int		ft_printf(char *str, ...)
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
			count += dispatch_flagged(&str, ap);
	}
	va_end(ap);
	return (count);
}

int		main(void)
{
	ft_printf("%x\n", 0);
	printf("%x\n\n", 0);
}
