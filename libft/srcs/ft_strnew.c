/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:12:39 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 20:16:54 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (!(fresh = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
