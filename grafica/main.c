#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    fdf *matrix_map;
    int i;
    int j;

   // if (argc != 2)
   //     ft_error("error: enter argument");
   printf("%s", argv[1]);
    matrix_map = (fdf*)malloc(sizeof(fdf));
    printf("%s", argv[1]);
    map_read(argv[1], matrix_map);
    i = 0;
    while (i < matrix_map->h)
    {
        j = 0;
        while (j < matrix_map->w)
        {
            printf("%d", matrix_map->d[i][j]);
            j++;
        }
        i++; 
    }
    return (0);
}