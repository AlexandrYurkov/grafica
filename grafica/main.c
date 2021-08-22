#include <fdf.h>

int main(int argc, char **argv)
{
    fdf *matrix_map;

    if (argc != 2)
        printf("error: enter argument");
    matrix_map = (fdf*)malloc(sizeof(fdf));
    matrix_map = map_read(argv[2]);
   
    return (0);
}