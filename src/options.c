/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:35:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/27 22:52:35 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_flags		get_flags(char **str)
{
	t_flags		flags;

	flags.pound = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.zero = 0;
	while (is_flag(**str))
	{
		add_flag(&flags, **str);
		(*str)++;
	}
	return (flags);
}

static int			get_width(char **str, va_list ap)
{
	int		width;

	width = 0;
	if (IS_DIGIT(**str))
	{
		width = ft_atoi(*str);
		while (IS_DIGIT(**str))
			(*str)++;
	}
	else if (**str == '*')
	{
		width = va_arg(ap, int);
		(*str)++;
	}
	return (width);
}

static int			get_precision(char **str, va_list ap)
{
	int		precision;

	precision = -1;
	if (**str == '.')
	{
		(*str)++;
		if (IS_DIGIT(**str))
		{
			precision = ft_atoi(*str);
			if (precision < 0)
				precision = -1;
			while (IS_DIGIT(**str))
				(*str)++;
		}
		else if (**str == '*')
		{
			precision = va_arg(ap, int);
			if (precision < 0)
				precision = -1;
			(*str)++;
		}
	}
	return ((precision >= 0) ? precision : -1);
}

static int			get_length(char **str)
{
	int		length;

	length = 0;
	if (**str == 'h' && *(*str + 1) == 'h')
		length = (int)('h' + 'h');
	else if (**str == 'h' && (*(*str + 1) != 'h'))
		length = (int)'h';
	else if (**str == 'l' && *(*str + 1) == 'l')
		length = (int)('l' + 'l');
	else if (**str == 'l' && *(*str + 1) != 'l')
		length = (int)'l';
	if (length > 0)
		(*str) += (length >= 'h' + 'h') ? 2 : 1;
	return (length);
}

t_opts		get_options(char **str, va_list ap)
{
	t_opts		options;

	options.flags = get_flags(str);
	options.field_width = get_width(str, ap);
	options.precision = get_precision(str, ap);
	options.length = get_length(str);
	return (options);
}
