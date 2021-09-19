/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:29:28 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 19:29:29 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ignor(int key)
{
	if (key == 53 || key == 69 || key == 91)
		return (1);
	if (key == 78 || key == 82 || key == 84)
		return (1);
	if (key == 86 || key == 87 || key == 88)
		return (1);
	if (key == 123 || key == 126 || key == 124 || key == 125)
		return (1);
	return (0);
}

void	get_traffic(int key, t_fdf *matrix_map)
{
	if (key == 126)
		matrix_map->offset_y -= 10;
	if (key == 125)
		matrix_map->offset_y += 10;
	if (key == 123)
		matrix_map->offset_x -= 10;
	if (key == 124)
		matrix_map->offset_x += 10;
	if (key == 78)
		matrix_map->zoom -= 2;
	if (key == 69)
		matrix_map->zoom += 2;
	if (key == 88)
		matrix_map->offset_angle_sin -= 0.1;
	if (key == 86)
		matrix_map->offset_angle_sin += 0.1;
	if (key == 84)
		matrix_map->offset_angle_cos -= 0.1;
	if (key == 91)
		matrix_map->offset_angle_cos += 0.1;
	if (key == 82)
		matrix_map->offset_z -= 2;
	if (key == 87)
		matrix_map->offset_z += 2;
}

int	get_event(int key, t_fdf *matrix_map)
{
	if (ft_ignor(key))
	{
		mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
		if (key == 53)
		{
			ft_free(matrix_map);
			mlx_destroy_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
			free(matrix_map);
			exit(0);
		}
		get_traffic(key, matrix_map);
		print_map(matrix_map);
	}
	return (0);
}
