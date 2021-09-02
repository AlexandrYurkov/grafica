#include "get_next_line.h"

static char	*tmp_line_return(char **line, int n, char **buffer)
{
	char		*tmp;

	tmp = NULL;
	tmp = malloc((n + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_tmpcpy2(tmp, *line, n);
	*line = ft_strtrim2(*line, n);
	if (!*line)
	{
		free (*buffer);
		free (tmp);
		return (NULL);
	}
	if (*buffer)
		free(*buffer);
	return (tmp);
}

static char	*ft_line_check(char **line, char **buffer)
{
	int			n;
	char		*tmp;

	tmp = NULL;
	n = 0;
	n = ft_strchr2(*line, '\n');
	if (n >= 0)
		return (tmp_line_return(&(*line), n, &(*buffer)));
	else
	{
		tmp = ft_strdup2(*line);
		free (*line);
		*line = NULL;
		if (*buffer)
			free(*buffer);
		return (tmp);
	}
}

static char	*ft_read_processing(int byte_read, char **buffer, char **line)
{
	if (byte_read < 0)
	{
		if (*buffer)
			free(*buffer);
		return (NULL);
	}
	if (*line && byte_read == 0)
		return (ft_line_check(&(*line), &(*buffer)));
	else
	{
		if (*buffer)
			free(*buffer);
		if (*line)
			free(*line);
	}
	return (NULL);
}

char	*get_next_line2(int fd)
{
	static char	*line;
	char		*buffer;
	int			n;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		if (!line)
			line = ft_strdup2(buffer);
		else
			line = ft_strjoin2(line, buffer);
		n = ft_strchr2(line, '\n');
		if (n >= 0)
			return (tmp_line_return(&line, n, &buffer));
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_read_processing(byte_read, &buffer, &line));
}
