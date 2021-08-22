/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:47:16 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 18:48:55 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dsr, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	if (dsr == 0 || src == 0)
		return (0);
	i = 0;
	l = ft_strlen(src);
	if (size == 0)
		return (l);
	while ((src[i] != '\0') && (i < (size - 1)) && (size > 0))
	{
		dsr[i] = src[i];
		i++;
	}
	dsr[i] = '\0';
	return (l);
}
