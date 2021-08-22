/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:00:44 by lfallon           #+#    #+#             */
/*   Updated: 2021/06/29 19:00:57 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *d, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d[i])
		i++;
	while (s[j])
	{
		d[i] = s[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *d, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		j;

	j = 0;
	while (s1[j])
		j++;
	dest = malloc(sizeof(*dest) * (j + 1));
	if (!dest)
		return (0);
	dest = ft_strcpy(dest, s1);
	return (dest);
}
