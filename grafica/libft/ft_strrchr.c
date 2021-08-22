/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:07:20 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 19:09:53 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr (const char *s, int c)
{
	char	*p;
	char	i;
	int		len;

	i = (char)c;
	len = ft_strlen(s);
	p = len + (char *)s;
	while (p >= s)
	{
		if (*p == i)
		{
			return (p);
		}
		p--;
	}
	return (NULL);
}
