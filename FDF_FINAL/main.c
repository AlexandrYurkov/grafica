#include "fdf.h"


int get_event (int key, fdf *matrix_map)
{
    printf("%d", key);
    return (0);
}



int main(int argc, char **argv)
{
    fdf *matrix_map;
    int i;
    int j;

   if (argc != 2)
       ft_error("error: enter argument");
    matrix_map = (fdf*)malloc(sizeof(fdf));
    map_read(argv[1], matrix_map);
    matrix_map->mlx_ptr = mlx_init();
    matrix_map->win_ptr = mlx_new_window(matrix_map->mlx_ptr, 900, 900, "FDF-test");
    matrix_map->zoom = 20;
    print_map(matrix_map);
    mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
    //mlx_loop(matrix_map->mlx_ptr);
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