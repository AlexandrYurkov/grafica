/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:26:48 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/05 14:45:28 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dsr, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dsr[i] = src[i];
		i++;
	}
	dsr[i] = '\0';
	return (dsr);
}

static int	ft_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa (int n)
{
	char	*str;
	int		size;

	size = ft_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy (str, "-2147483648"));
	str[size--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
