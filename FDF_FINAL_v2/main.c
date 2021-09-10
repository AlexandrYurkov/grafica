#include "fdf.h"


// int get_event (int key, fdf *matrix_map)
// {
//     printf("%d\n", key);
//     return (0);
// }
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
    if(key != 53 && key != 126 && key != 125 && key != 123 && key != 124)
       return(0);
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
    print_map(matrix_map);
    return (0);
}

int main(int argc, char **argv)
{
    fdf *matrix_map;
    int i;
    int j;
    int k;

   if (argc != 2)
    //    ft_error("error: enter argument");
    ;
    matrix_map = (fdf*)malloc(sizeof(fdf));
    if (!matrix_map)
    {
        printf("error malloc");
        exit(0);
    }
    matrix_map->realloc_size = 10;
    map_read(argv[1], matrix_map);
    matrix_map->mlx_ptr = mlx_init();
    matrix_map->win_ptr = mlx_new_window(matrix_map->mlx_ptr, 1000, 1000, "FDF-test");
    matrix_map->zoom = 20;
    print_map(matrix_map);
    mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
    mlx_loop(matrix_map->mlx_ptr);
    return (0);
}
// int main(int argc, char **argv)
// {
//     fdf *matrix_map;
//     int i;
//     int j;

//    if (argc != 2)
//        ft_error("error: enter argument");
//     matrix_map = (fdf*)malloc(sizeof(fdf));
   
//     map_read(argv[1], matrix_map);
//     i = 0;
//     while (i < matrix_map->h)
//     {
//         if(i == 1)
//              j = 0;
//         while (j < matrix_map->w)
//         {
//             printf("%3d", matrix_map->d[i][j]);
//             j++;
//         }
//         i++; 
//         printf("\n");
//     }
//     return (0);
// }