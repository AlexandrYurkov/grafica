/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:16:40 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 21:24:38 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	l;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i < start)
		return (ft_strdup(""));
	l = i - start;
	if (l < len)
		len = l;
	str = (char *)malloc((len + 1) * sizeof (char));
	if (!(str))
		return (NULL);
	i = 0;
	while (i != len && s[i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
