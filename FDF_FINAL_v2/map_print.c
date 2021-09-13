#include "fdf.h"
#include <math.h>

float mod(float i)
{
    if (i < 0)
        i *= -1;
    return (i);
}

int max(int a, int b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

void get_zoom(float *x, float *x1, float *y, float *y1, fdf *matrix_map) // можно добавить переменную zoom в структуру и изменять ее
{
    *x *= matrix_map->zoom;
    *x1 *= matrix_map->zoom;
    *y *= matrix_map->zoom;
    *y1 *= matrix_map->zoom;
}

int get_color(int z, int z1, fdf *matrix_map)
{
    if (z > 0 || z1 > 0)
        return (0xFF0000);
    if (z < 0 || z1 < 0)
        return (0x00FF00);
    else
        return (0xffffff);
}

void get_3d(float *x, float *y, int z, fdf *matrix_map)
{
    *x = (*x - *y) * matrix_map->offset_angle_cos;//cos(0.5);// задать переменную на врашение
    *y = (*x + *y) * matrix_map->offset_angle_sin - z;//sin(0.5) - z;
}

void point_on_the_map(float x, float y, float x1, float y1, fdf *matrix_map)
{
    float x_step;
    float y_step;
    int maxinus;
    int tmp_x;
    int tmp_y;
    int z;
    int z1;

    z = matrix_map->d[(int)y][(int)x] * matrix_map->offset_z;
    z1 = matrix_map->d[(int)y1][(int)x1]* matrix_map->offset_z;
    get_zoom(&x, &x1, &y, &y1, matrix_map);
    get_3d(&x, &y, z, matrix_map);
    get_3d(&x1, &y1, z1, matrix_map);
    matrix_map->color = get_color(z, z1, matrix_map);
    x += matrix_map->offset_x + 450;
    y += matrix_map->offset_y + 350;
    x1 += matrix_map->offset_x + 450;
    y1 += matrix_map->offset_y + 350;
    x_step = x1 - x;
    y_step = y1 - y;
    maxinus = max(mod(x_step), mod(y_step));
    x_step /= maxinus;
    y_step /= maxinus;
    //printf("x = %f\n, x1 = %f\n, x_step = %f \n %d ---- %d  ", x, x1, x_step, ((int)(x - x1)), ((int)(y - y1)));
    // вставить изменения по event x, y, x1, y1
    tmp_x = (int)(x - x1);
    tmp_y = (int)(y - y1);
    while (tmp_x || tmp_y)
    {
        mlx_pixel_put(matrix_map->mlx_ptr, matrix_map->win_ptr, x, y, matrix_map->color);
        x += x_step;
        y += y_step;
        tmp_x = (int)(x - x1);
        tmp_y = (int)(y - y1);
    }
}

void print_map(fdf *matrix_map)
{
    int x;
    int y;

    y = 0;
    mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
    while (y < matrix_map->h)
    {
        x = 0;
        while (x < matrix_map->w)
        {
            if (x < (matrix_map->w - 1))
                point_on_the_map(x, y, (x + 1), y, matrix_map);
            if (y < (matrix_map->h - 1))
                point_on_the_map(x, y, x, (y + 1), matrix_map);
            x++;
        }
        y++;
    }
}