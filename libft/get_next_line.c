/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:28:42 by akasamar          #+#    #+#             */
/*   Updated: 2018/05/03 23:28:44 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_readme(char *buff, t_list *mylst)
{
	int		ret;
	char	*tmp;

	if (!(ret = read(mylst->content_size, buff, BUFF_SIZE)))
		return (0);
	buff[ret] = '\0';
	tmp = mylst->content;
	mylst->content = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (ret);
}

static int		ft_gogogo(void **newstart, char **line, int i)
{
	int		d;
	char	*s;

	if (!ft_strlen(*newstart))
		return (0);
	s = *newstart;
	i = -1;
	d = 1;
	while (s[++i] != '\n')
		if (s[i] == '\0')
		{
			d = 0;
			break ;
		}
	*line = ft_strsub(s, 0, i);
	*newstart = ft_strdup(&s[i + d]);
	free(s);
	return (1);
}

static t_list	*ft_lists(const int fd)
{
	static t_list	*head = NULL;
	t_list			*current;

	current = head;
	while (current != NULL)
	{
		if (fd == (int)current->content_size)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(&head, current);
	return (current);
}

int				get_next_line(const int fd, char **line)
{
	t_list			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				g;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	tmp = ft_lists(fd);
	while (1)
	{
		if (ft_strchr(tmp->content, '\n'))
			return (ft_gogogo(&(tmp->content), line, -1));
		if ((g = ft_readme(buff, tmp)) == -1)
			return (-1);
		if (g == 0)
		{
			if (!ft_strlen(tmp->content))
				return (0);
			*line = ft_strdup(tmp->content);
			ft_bzero(tmp->content, ft_strlen(tmp->content));
			return (1);
		}
	}
	return (1);
}
