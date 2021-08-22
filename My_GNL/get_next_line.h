/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:01:31 by lfallon           #+#    #+#             */
/*   Updated: 2021/06/29 19:13:43 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		end(char **line_next, char **line, int end_read);
int		get_next_line(int fd, char **line);
char	*ft_strcat(char *d, const char *s);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *str, int c);
char	*ft_strcpy(char *d, const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

# ifndef MAX_FD
#  define MAX_FD 256

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

# endif

#endif
