/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:15:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/19 22:00:45 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_list	*ft_save_content(t_list **save, int fd)
{
	t_list	*database;

	database = *save;
	while (database)
	{
		if (((int)(database->content_size)) == fd)
			return (database);
		database = database->next;
	}
	database = ft_lstnew("\0", fd);
	ft_lstadd(save, database);
	return (*save);
}

static void		sanitize(t_list *line)
{
	char	*temp;

	if ((temp = ft_strchr(line->content, '\n')))
	{
		temp = ft_strdup(temp + 1);
		free(line->content);
		line->content = temp;
	}
	else
		ft_strclr(line->content);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			*temp;
	char			buff[BUFF_SIZE + 1];
	t_list			*pointer;
	static t_list	*database;

	CHECK(fd < 0 || line == NULL || read(fd, buff, 0) < 0);
	pointer = ft_save_content(&database, fd);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		CHECK(!(temp = ft_strjoin(pointer->content, buff)));
		free(pointer->content);
		pointer->content = temp;
		BREAK(ft_strchr(pointer->content, '\n'));
	}
	if (!i && ft_strlen(pointer->content) == 0)
	{
		ft_strclr(*line);
		return (0);
	}
	CHECK(!(*line = ft_strnew(ft_strlen(pointer->content))));
	ft_strccpy(*line, pointer->content, '\n');
	sanitize(pointer);
	return (1);
}
