/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:40:34 by lfallon           #+#    #+#             */
/*   Updated: 2021/06/29 18:44:16 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*one_str(char *str1, char *str2)
{
	if (!str1)
		return (ft_strdup(str2));
	else
		return (ft_strdup(str1));
}

static int	end_one(char **line_next, char **line, int i)
{
	char	*tmp;

	(*line_next)[i] = '\0';
	*line = ft_strdup(*line_next);
	tmp = ft_strdup(*line_next + i + 1);
	free(*line_next);
	*line_next = tmp;
	tmp = NULL;
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;

	s3 = 0;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (one_str(s1, s2));
	else if (s1 && s2)
	{
		s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
			return (0);
		ft_strcpy(s3, s1);
		free(s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}

int	end(char **line_next, char **line, int end_read)
{
	int		i;

	i = -1;
	if (end_read < 0)
		return (-1);
	if (*line_next)
		i = ft_strchr(*line_next, '\n');
	if (i >= 0)
		return (end_one(line_next, line, i));
	else if (*line_next)
	{
		*line = *line_next;
		*line_next = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*line_next[MAX_FD];
	char		*buff;
	int			end_read;
	int			i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
		return(-1);
	end_read = read(fd, buff, BUFFER_SIZE);
	while (end_read > 0)
	{
		buff[end_read] = '\0';
		line_next[fd] = ft_strjoin(line_next[fd], buff);
		i = ft_strchr(line_next[fd], '\n');
		if (i >= 0)
		{
			free(buff);
			return (end_one(&line_next[fd], line, i));
		}
		end_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (end(&line_next[fd], line, end_read));
}
