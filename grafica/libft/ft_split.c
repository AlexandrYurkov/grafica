/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:30:23 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 20:13:16 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **mass)
{
	unsigned int	i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
	return (NULL);
}

static size_t	ft_quantity_src(char const *s, char c)
{
	size_t	i;
	size_t	n_src;

	if (!(*s))
		return (0);
	i = 0;
	n_src = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			n_src++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		n_src++;
	return (n_src);
}

static int	ft_len_str(char **str, unsigned int *len_s, char c)
{
	unsigned int	i;
	int				j;

	*str += *len_s;
	*len_s = 0;
	i = 0;
	j = 0;
	while (*str[i] && *str[i] == c)
	{
		(*str)++;
		j++;
	}
	while ((*str)[i] && (*str)[i] != c)
	{
		(*len_s)++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**mass;
	char			*str;
	unsigned int	len_s;
	size_t			len;
	size_t			i;

	len = ft_quantity_src(s, c);
	mass = (char **)malloc(sizeof(char *) * (len + 1));
	if (!s || !(mass))
		return (NULL);
	i = 0;
	str = (char *)s;
	len_s = 0;
	while (i < len)
	{
		ft_len_str(&str, &len_s, c);
		mass[i] = (char *)malloc(sizeof(char) * (len_s + 1));
		if (!(mass[i]))
			return (ft_free(mass));
		ft_strlcpy(mass[i], str, len_s + 1);
		i++;
	}
	mass[i] = NULL;
	return (mass);
}
