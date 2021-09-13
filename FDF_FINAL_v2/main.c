#include "fdf.h"


void ft_free(fdf *matrix_map)
{
    int i;

    i = 0;
    while (i < matrix_map->h)
    {
        free (matrix_map->d[i]);
        i++;
    }
    free(matrix_map->d);
    matrix_map->d = NULL;

}

int get_event (int key, fdf *matrix_map)
{
    // if(key != 53 && key != 126 && key != 125 && key != 123 && key != 124)
    //    return(0);
    printf("%d\n", key);
    mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
    if(key == 53)
    {
        ft_free(matrix_map);
        mlx_destroy_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
        free(matrix_map);
        exit (0);
    }
    if(key == 126)
        matrix_map->offset_y -= 10;
    if(key == 125)
        matrix_map->offset_y += 10;
    if(key == 123)
        matrix_map->offset_x -= 10;
    if(key == 124)
        matrix_map->offset_x += 10;
    if(key == 78)
        matrix_map->zoom -= 2;
    if(key == 69)
        matrix_map->zoom += 2;
    if(key == 88)
         matrix_map->offset_angle_sin -= 0.1;
    if(key == 86)
        matrix_map->offset_angle_sin += 0.1;
    if(key == 84)
         matrix_map->offset_angle_cos -= 0.1;
    if(key == 91)
        matrix_map->offset_angle_cos += 0.1;
    if(key == 82) //0
        matrix_map->offset_z -= 2;
    if(key == 87) // 5
        matrix_map->offset_z += 2;
    print_map(matrix_map);
    return (0);
}

void incilization (fdf *matrix_map)
{
    matrix_map->offset_z = 1;
    matrix_map->realloc_size = 10;
    matrix_map->zoom = 20;
    matrix_map->offset_angle_sin = 0.8;
    matrix_map->offset_angle_cos = 0.8;
}

int main(int argc, char **argv)
{
    fdf *matrix_map;
    int i;
    int j;
    int k;

   if (argc != 2)
        perror("error: enter argument");
    matrix_map = (fdf*)malloc(sizeof(fdf));
    if (!matrix_map)
    {
        perror("error malloc");
        exit(0);
    }
    incilization(matrix_map);
    map_read(argv[1], matrix_map);
    matrix_map->mlx_ptr = mlx_init();
    matrix_map->win_ptr = mlx_new_window(matrix_map->mlx_ptr, 1000, 1000, "FDF-test");
    print_map(matrix_map);
    mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
    mlx_loop(matrix_map->mlx_ptr);
    return (0);
}