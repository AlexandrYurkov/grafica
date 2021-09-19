/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:30:15 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 19:30:16 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_fdf *matrix_map)
{
	int	i;

	i = 0;
	while (i < matrix_map->h)
	{
		free(matrix_map->d[i]);
		i++;
	}
	free(matrix_map->d);
	matrix_map->d = NULL;
}
