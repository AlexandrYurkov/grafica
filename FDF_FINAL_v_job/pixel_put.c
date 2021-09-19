/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:29:13 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 19:29:14 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	ft_pixel_put(t_data *tmp_map, t_fdf *matrix_map)
{
	float	x_step;
	float	y_step;
	int		maxinus;
	int		tmp_x;
	int		tmp_y;

	x_step = tmp_map->x1 - tmp_map->x;
	y_step = tmp_map->y1 - tmp_map->y;
	maxinus = max(mod(x_step), mod(y_step));
	x_step /= maxinus;
	y_step /= maxinus;
	tmp_x = (int)(tmp_map->x - tmp_map->x1);
	tmp_y = (int)(tmp_map->y - tmp_map->y1);
	while (tmp_x || tmp_y)
	{
		mlx_pixel_put(matrix_map->mlx_ptr, matrix_map->win_ptr, tmp_map->x,
			tmp_map->y, matrix_map->color);
		tmp_map->x += x_step;
		tmp_map->y += y_step;
		tmp_x = (int)(tmp_map->x - tmp_map->x1);
		tmp_y = (int)(tmp_map->y - tmp_map->y1);
	}
}
