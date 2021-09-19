/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <lfallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:05:06 by lfallon           #+#    #+#             */
/*   Updated: 2021/09/19 20:44:23 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct t_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
	int		**d;
	int		zoom;
	int		color;
	int		offset_x;
	int		offset_y;
	int		offset_z;
	float	offset_angle_sin;
	float	offset_angle_cos;
	int		realloc_size;
}	t_fdf;

typedef struct s_data
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}	t_data;

int		*map_read(char *file, t_fdf *matrix_map);
void	print_map(t_fdf *matrix_map);
void	point_on_the_map(t_data *tmp_map, t_fdf *matrix_map);
int		max(int a, int b);
float	mod(float i);
void	get_3d(float *x, float *y, int z, t_fdf *matrix_map);
int		get_event(int key, t_fdf *matrix_map);
void	ft_pixel_put(t_data *tmp_map, t_fdf *matrix_map);
void	get_zoom(t_data *tmp_map, t_fdf *matrix_map);
int		get_color(int z, int z1, t_fdf *matrix_map);
void	center_align(t_data *tmp_map, t_fdf *matrix_map);
void	ft_free(t_fdf *matrix_map);
int		ft_ignor(int key);

#endif
