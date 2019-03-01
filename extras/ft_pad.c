/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:01:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/01 14:01:41 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_pad(char *s, int pad, int length, int left_align)
{
	char	*new;

	if (pad <= length)
		return (s);
	MEM_CHK((new = malloc(sizeof(char) * pad + 1)));
	ft_memset(new, ' ', pad);
	new[pad] = '\0';
	if (left_align)
		ft_strmove(new, s);
	else
		ft_stroverlap(new, s);
	ft_memdel((void **)&s);
	return (new);
}
