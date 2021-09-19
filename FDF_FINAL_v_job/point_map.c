/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:29:18 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 20:42:55 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_zoom(t_data *tmp_map, t_fdf *matrix_map)
{
	tmp_map->x *= matrix_map->zoom;
	tmp_map->x1 *= matrix_map->zoom;
	tmp_map->y *= matrix_map->zoom;
	tmp_map->y1 *= matrix_map->zoom;
}

int	get_color(int z, int z1, t_fdf *matrix_map)
{
	if (z > 0 || z1 > 0)
		return (0xFF0000);
	if (z < 0 || z1 < 0)
		return (0x00FF00);
	else
		return (0xffffff);
}

void	get_3d(float *x, float *y, int z, t_fdf *matrix_map)
{
	*x = (*x - *y) * matrix_map->offset_angle_cos;
	*y = (*x + *y) * matrix_map->offset_angle_sin - z;
}

void	center_align(t_data *tmp_map, t_fdf *matrix_map)
{
	tmp_map->x += matrix_map->offset_x + 450;
	tmp_map->y += matrix_map->offset_y + 350;
	tmp_map->x1 += matrix_map->offset_x + 450;
	tmp_map->y1 += matrix_map->offset_y + 350;
}

void	point_on_the_map(t_data *tmp_map, t_fdf *matrix_map)
{
	int	z;
	int	z1;

	z = matrix_map->d[(int)tmp_map->y][(int)tmp_map->x] * matrix_map->offset_z;
	z1 = matrix_map->d[(int)tmp_map->y1][(int)tmp_map->x1]
		* matrix_map->offset_z;
	get_zoom(tmp_map, matrix_map);
	get_3d(&(tmp_map->x), &(tmp_map->y), z, matrix_map);
	get_3d(&(tmp_map->x1), &(tmp_map->y1), z1, matrix_map);
	matrix_map->color = get_color(z, z1, matrix_map);
	center_align(tmp_map, matrix_map);
	ft_pixel_put(tmp_map, matrix_map);
}
