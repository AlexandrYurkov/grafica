/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:38:49 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 18:38:52 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				get_next_line(const int fd, char **line);
char			**ft_strsplit(char const *s, char c);
void			*ft_realloc(void *mem, size_t current_size, size_t new_size);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_matfree(char **str, int i);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			ft_strdel(char **as);
char			*ft_strnew(size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
unsigned int	ft_wc(char const *s, char c);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);

#endif
