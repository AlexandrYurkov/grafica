/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:25:47 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/05 13:51:16 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(int n)
{
	if (n == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	unsigned int	res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		str++;
	res = 0;
	if (str[0] == '-')
		n = -1;
	else
		n = 1;
	if (str[0] == '-' || str[0] == '+')
		str += 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i > 10 || res >= 4294967295)
		return (ft_max(n));
	return (n * res);
}
