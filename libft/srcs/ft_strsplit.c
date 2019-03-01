/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:54:16 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/13 16:41:11 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		get_word_len(char const *word, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (word[i] && word[i] == delim)
		i++;
	while (word[i] && word[i] != delim)
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strings;

	if (!s || !(strings = (char **)malloc(sizeof(char *) *
					ft_getwordcount(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_getwordcount(s, c))
	{
		k = 0;
		if (!(strings[i] = (char *)malloc(sizeof(char) *
						get_word_len(&s[j], c) + 1)))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			strings[i][k++] = s[j++];
		strings[i][k] = '\0';
		i++;
	}
	strings[i] = 0;
	return (strings);
}
