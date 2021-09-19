/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:28:47 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 20:44:12 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_map(int x, int y, t_data *tmp_map)
{
	tmp_map->x = (float)x;
	tmp_map->y = (float)y;
	tmp_map->x1 = (float)x;
	tmp_map->y1 = (float)y;
}

static void	ft_step(int x, int y, t_data *tmp_map, t_fdf *matrix_map)
{
	if (x < (matrix_map->w - 1))
	{
		ft_init_map(x, y, tmp_map);
		tmp_map->x1 += 1;
		point_on_the_map(tmp_map, matrix_map);
	}
	if (y < (matrix_map->h - 1))
	{
		ft_init_map(x, y, tmp_map);
		tmp_map->y1 += 1;
		point_on_the_map(tmp_map, matrix_map);
	}
}

void	print_map(t_fdf *matrix_map)
{
	int		x;
	int		y;
	t_data	*tmp_map;

	tmp_map = (t_data *)malloc(sizeof(t_data));
	y = 0;
	mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
	while (y < matrix_map->h)
	{
		x = 0;
		while (x < matrix_map->w)
		{
			ft_step(x, y, tmp_map, matrix_map);
			x++;
		}
		y++;
	}
	free(tmp_map);
}
