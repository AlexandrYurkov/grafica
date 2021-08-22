/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:43:48 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/05 15:45:01 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset (void *str, int s, size_t i)
{
	unsigned char	t;
	unsigned char	*st;

	t = (unsigned char)s;
	st = (unsigned char *)str;
	while (i > 0)
	{
		*st++ = t;
		--i;
	}
	return (str);
}
