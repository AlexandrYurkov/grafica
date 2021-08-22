/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:23:15 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 18:30:35 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*str;
	size_t	len;

	str = (char *)s1;
	s = (char *)malloc((ft_strlen(str) + 1) * sizeof (char));
	if (!(s))
		return (NULL);
	len = 0;
	while (str[len])
	{
		s[len] = str[len];
		len++;
	}
	s[len] = '\0';
	return ((char *)s);
}
