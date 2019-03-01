/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:34:58 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/28 01:19:23 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	We decrement width since with %c we will always need to print at least
**	the char. AKA with 1 width we print only the c, with 2 width we print
**	a space AND the c.
*/

static void		c_pad(char to_print, int width, int left_align)
{
	int		i;

	i = 0;
	width--;
	if (width >= 0 && !left_align)
	{
		while (i < width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar(to_print);
	if (width >= 0 && left_align)
	{
		while (i < width)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

int				convert_c(t_opts options, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	c_pad(c, options.field_width, options.flags.minus);
	if (options.field_width > 1)
		return (options.field_width);
	return (1);
}
