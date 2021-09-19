/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon </var/mail/lfallon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:19:49 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 17:19:51 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (dup == 0)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
