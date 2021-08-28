/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:17:49 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 18:22:28 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	i;

	i = (char) c;
	p = (char *)s;
	while (*p != i)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}