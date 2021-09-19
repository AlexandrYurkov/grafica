/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:13:54 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 17:13:58 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tmp(char const *s, char c, char **str, int i)
{
	const char		*end;

	while (*s)
	{
		end = s;
		while (*end && *end != c)
			end++;
		*(str + i++) = ft_strsub(s, 0, end - s);
		if (!(*str))
		{
			ft_matfree(str, i);
			return (0);
		}
		s = end;
		while (*s && *s == c)
			s++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			i;

	i = 0;
	str = (char **)malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (*s && *s == c)
		s++;
	i = tmp (s, c, str, i);
	*(str + i) = NULL;
	return (str);
}
