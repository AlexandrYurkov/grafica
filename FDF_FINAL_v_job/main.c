/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:05:22 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 20:29:59 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialization(t_fdf *matrix_map)
{
	matrix_map->offset_z = 1;
	matrix_map->realloc_size = 10;
	matrix_map->zoom = 20;
	matrix_map->offset_angle_sin = 0.8;
	matrix_map->offset_angle_cos = 0.8;
}

int	main(int argc, char **argv)
{
	t_fdf	*matrix_map;

	if (argc != 2)
	{
		perror("error: enter argument");
		exit(0);
	}
	matrix_map = (t_fdf *)malloc(sizeof(t_fdf));
	if (!matrix_map)
	{
		perror("error malloc");
		exit(0);
	}
	initialization(matrix_map);
	map_read(argv[1], matrix_map);
	matrix_map->mlx_ptr = mlx_init();
	matrix_map->win_ptr = mlx_new_window(matrix_map->mlx_ptr, 1000, 1000,
			"FDF-test");
	print_map(matrix_map);
	mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
	mlx_loop(matrix_map->mlx_ptr);
	return (0);
}
