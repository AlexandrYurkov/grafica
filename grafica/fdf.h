#ifndef FDF_H
# define FDF_H
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h> // удалить, заменить на ft_printf
#include "libft2/libft.h"

typedef struct fdf
{
    void *mlx_ptr;
    void *win_ptr;
    int h;
    int w;
    int **d;
    float x;
    float y;
    float z;

}               fdf;

void map_read(char *file, fdf *matrix_map);

#endif