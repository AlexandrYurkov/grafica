/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:45:42 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 18:47:05 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat (char *dst, const char *src, size_t size)
{
	size_t	SRC;
	size_t	DST;
	size_t	j;

	SRC = ft_strlen(src);
	DST = ft_strlen(dst);
	j = 0;
	if (size <= DST)
		SRC += size;
	else
		SRC += DST;
	while (src[j] && (DST + 1) < size)
	{
		dst[DST] = src[j];
		j++;
		DST++;
	}
	dst[DST] = '\0';
	return (SRC);
}
