#include "fdf.h"

int get_heigth(char *file)
{
    char *line;
    int fd;
    int height;

    fd = open(file, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);    
}


void map_read(char *file, fdf *matrix_map)
{
    matrix_map->x = get_heigth(file);
}