/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:40:47 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/14 09:31:05 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
**	Fucntion to count the amount of digits in an int
*/

int		ft_intlen(int num)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	if (num < 0)
		i = -num;
	else
		i = num;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}
