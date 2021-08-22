/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:34:33 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 18:09:53 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			len;

	if (!(dst) && !(src))
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	len = 0;
	while (len < n)
	{
		d[len] = s[len];
		len++;
	}
	return (dst);
}
