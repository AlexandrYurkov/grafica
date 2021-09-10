#ifndef FDF_H
# define FDF_H
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include <math.h>
#include <stdio.h> // удалить, заменить на ft_printf
#include "libft/libft.h"
#include <stdlib.h>

typedef struct
{
    void *mlx_ptr;
    void *win_ptr;
    int h;
    int w;
    int **d;
    int zoom;
    int color;
    int offset_x;
    int offset_y;
    int realloc_size;
}               fdf;

int *map_read(char *file, fdf *matrix_map);
void print_map (fdf *matrix_map);
void point_on_the_map(float x, float x1, float y, float y1, fdf *matrix_map);
int max (int a, int b);
float mod (float i);
void get_3d(float *x, float *y, int z);
int get_event (int key, fdf *matrix_map);

#endif