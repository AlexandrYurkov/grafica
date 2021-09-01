#include "fdf.h"

int mod(int i)
{
    if (i < 0)
        i *= -1;
    return (i);
}

int max (int a, int b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

void get_zoom(float *x, float *x1, float *y, float *y1)// можно добавить переменную zoom в структуру и изменять ее
{

}

void point_on_the_map(float x, float x1, float y, float y1, fdf *matrix_map)
{
    float x_step;
    float y_step;
    int maxinus;

    get_zoom(&x, &x1, &y, &y1);

    x_step = x1 - x;
    y_step = y1 - y;
    maxinus = max(mod(x_step), mod(y_step));
    x_step /= maxinus;
    y_step /= maxinus;

    while ((int)(x -x1)) || (int)(y - y1))
    {
        mlx_pixel_put(matrix_map->mlx_ptr, matrix_map->win_ptr, x, y, 0xfffffff);
        x += x_step;
        y += y_step;
    }
    
}

void print_map (fdf *matrix_map)
{
    int x;
    int y;

    y = 0;

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