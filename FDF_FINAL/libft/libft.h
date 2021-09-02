#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


void	ft_error(char *msg);
char    *get_next_line(int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int     ft_strchr(char *str, int c);
char    *ft_strtrim(char *src, int n);
char    *ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char    *ft_strdup(const char *src);
char    *ft_tmpcpy(char *tmp, const char *line, int n);
int		ft_words_count(char const *str, char c);
int		ft_atoi(const char *str);

#endif
