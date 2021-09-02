#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line2(int fd);
size_t	ft_strlen2(const char *s);
int		ft_strchr2(char *str, int c);
char	*ft_strdup2(const char *src);
char	*ft_strjoin2(char *s1, const char *s2);
char	*ft_tmpcpy2(char *tmp, const char *line, int n);

#define BUFFER_SIZE 100

#endif
