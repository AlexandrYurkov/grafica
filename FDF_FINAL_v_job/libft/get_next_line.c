/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:27:44 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 20:38:28 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char			*p;
	char			*rp;

	p = ft_strnew(n + 1);
	if (!p)
		return (NULL);
	rp = p;
	*p = *s1;
	while ((*p) && (size_t)(p - rp) < n)
	{
		p++;
		s1++;
		*p = *s1;
	}
	ft_memset(p, 0, 1 + n - (p - rp));
	return (rp);
}

static t_list	*get_node(t_list **list, int fd)
{
	t_list			*node;

	node = *list;
	while (node)
	{
		if (node->content_size == (size_t)fd)
			return (node);
		node = node->next;
	}
	node = ft_lstnew("\0", 1);
	node->content_size = fd;
	ft_lstadd(list, node);
	node = *list;
	return (node);
}

static int	if_write_line(t_list *pnode, char **line)
{
	char	*str;

	str = ft_strchr((char *)pnode->content, '\n');
	if (str && *str)
	{
		*line = ft_strndup((char *)pnode->content,
				str - (char *)pnode->content);
		str = ft_strdup(str + 1);
		if (!(*line) || !(str))
			return (-1);
		ft_memdel(&pnode->content);
		pnode->content = str;
		return (1);
	}
	if (pnode->content && *(char *)pnode->content)
	{
		*line = ft_strdup((char *)pnode->content);
		if (!(*line))
			return (-1);
		ft_memdel(&pnode->content);
		return (1);
	}
	return (0);
}

static int	write_line(t_list **node, char **line)
{
	t_list	*pnode;
	int		i;

	pnode = *node;
	if (pnode->content == NULL)
		return (0);
	i = if_write_line(pnode, line);
	if (i == 1)
		return (1);
	if (i == -1)
		return (-1);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	t_list			*node;
	static t_list	*list;
	char			*str;
	int				size;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE < 1))
		return (-1);
	node = get_node(&list, fd);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[size] = 0;
		str = (char *)node->content;
		node->content = ft_strjoin((char *)node->content, buff);
		if (!(node->content))
			return (-1);
		ft_strdel(&str);
		if (ft_strchr((char *)node->content, '\n'))
			break ;
		size = read(fd, buff, BUFFER_SIZE);
	}
	if (size == -1)
		return (-1);
	return (write_line(&node, line));
}
