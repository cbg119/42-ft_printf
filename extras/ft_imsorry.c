/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imsorry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:13:23 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/03 13:21:58 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_imsorry(char to_print, int *len, int spaces)
{
	while (spaces-- > 0)
	{
		ft_putchar(to_print);
		*len += 1;
	}
}
