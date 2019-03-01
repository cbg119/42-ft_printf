/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:59:15 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 13:59:52 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int				convert_percent(t_opts options)
{
	char	c;

	c = '%';
	c_pad(c, options.field_width, options.flags.minus);
	if (options.field_width > 1)
		return (options.field_width);
	return (1);
}
