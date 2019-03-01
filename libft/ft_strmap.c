/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:35:17 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/12 20:41:53 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Because the instructions suck dick - we malloc a new string the same length
** as the original, *s. We then fill each character as a result of the function
** *f applied to *s.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	length;
	unsigned int	i;
	char			*string;

	if (!s || !f)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if (!(string = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (s[i])
	{
		string[i] = (*f)(s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
