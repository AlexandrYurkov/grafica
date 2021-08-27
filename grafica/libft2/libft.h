#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

void	ft_error(char *msg);
int		get_next_line(const int fd, char **line);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *restrict str1, const char *restrict str2);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strdel(char **ap);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t s);
char	*ft_strsub(char const *s, unsigned int c, size_t l);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_words_count(char const *str, char c);
size_t	ft_strlcpy(char *dsr, const char *src, size_t size);
int		ft_atoi(const char *str);

#endif