/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:49:12 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 10:58:02 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			len;
	char		*string;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (IS_SPACE(s[i]))
		i++;
	if ((size_t)i == ft_strlen(s))
		return (ft_strnew(1));
	while (IS_SPACE(s[len - 1]))
		len--;
	string = ft_strsub(s, i, (size_t)(len - i));
	return (string);
}
