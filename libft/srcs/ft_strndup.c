/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:37:22 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/24 19:40:20 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strndup(const char *s1, int n)
{
    int     i;
    int     length;
    char    *result;

    length = ft_strlen(s1);
	if (n > length)
		n = length;
    if (!(result = (char *)malloc(sizeof(char) * n + 1)))
        return (NULL);
    i = 0;
    while (s1[i] && i < n)
    {
        result[i] = s1[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
