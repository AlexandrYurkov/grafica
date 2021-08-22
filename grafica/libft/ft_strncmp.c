/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:56:07 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/06 19:04:23 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (0);
	while (c > i && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (c <= i)
		return (0);
	else
		return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
