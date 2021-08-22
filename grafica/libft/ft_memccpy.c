/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:47:38 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/05 15:18:03 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*DST;
	unsigned char	*SRC;
	unsigned char	C;

	DST = (unsigned char *)dst;
	SRC = (unsigned char *)src;
	C = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		DST[i] = SRC[i];
		if (SRC[i] == C)
			return (&(DST[i + 1]));
		i++;
	}
	return (0);
}
