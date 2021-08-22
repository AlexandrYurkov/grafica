#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h> // удалить, заменить на ft_printf
#include "libft/libft.h"

typedef struct fdf
{
    void *mlx_ptr;
    void *win_ptr;
    float x;
    float y;
    float z;

}               fdf;
