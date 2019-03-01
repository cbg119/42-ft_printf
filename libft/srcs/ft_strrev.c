/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:30:18 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/28 00:57:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_strrev(char *str)
{
	char	*pointer;

	pointer = str;
	while (*pointer)
		pointer++;
	pointer--;
	while (str < pointer)
	{
		ft_swap(&(*str), &(*pointer));
		str++;
		pointer--;
	}
}
