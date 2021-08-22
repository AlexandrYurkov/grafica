/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:10:16 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 19:16:01 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	ft_compare(const char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s;
	size_t	n;

	if (!s1)
		return (NULL);
	s = 0;
	while (s1[s] && ft_compare(set, s1[s]))
		s++;
	n = ft_strlen(s1);
	while (n > s && ft_compare(set, s1[n - 1]))
		n--;
	n -= s;
	str = (char *)malloc(((n) + 1) * sizeof(*s1));
	if (!(str))
		return (NULL);
	ft_strncpy(str, (s1 + s), n);
	str[n] = '\0';
	return (str);
}
