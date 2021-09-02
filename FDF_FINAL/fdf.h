#ifndef FDF_H
# define FDF_H
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include <stdio.h> // удалить, заменить на ft_printf
#include "libft/libft.h"

typedef struct
{
    void *mlx_ptr;
    void *win_ptr;
    int h;
    int w;
    int **d;
    float x;
    float y;
    float z;
    int zoom;
    int color;

 
}               fdf;

int *map_read(char *file, fdf *matrix_map);
void print_map (fdf *matrix_map);
void point_on_the_map(float x, float x1, float y, float y1, fdf *matrix_map);

#endif