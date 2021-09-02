#include "fdf.h"

int get_heigth(char *file)
{
    char *line;
    int fd;
    int height;

    fd = open(file, O_RDONLY, 0);
    if(fd <= 0)
        ft_error("not file");
    height = 0;
    while ((line = get_next_line(fd)))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);    
}

int get_width(char *file)
{
    char *line;
    int fd;
    int width;

    fd = open(file, O_RDONLY, 0);
    if(fd <= 0)
        ft_error("not file");
    line = get_next_line(fd);
    width = ft_words_count(line, ' ');
    free(line);
    close(fd);
    return(width);    
}

void get_filling(int *line_z, char *line)
{
    char **num;
    int j;

    num = ft_split(line, ' ');
    j = 0;

    while (num[j])
    {
        line_z[j] = ft_atoi(num[j]);
        free(num[j]);
        j++;
    }
    free(num);   
}

int *map_read(char *file, fdf *matrix_map)
{
    int i;
    int fd;
    char *line;
    matrix_map->h = get_heigth(file);
    matrix_map->w = get_width(file);
    matrix_map->d = (int **)malloc(sizeof(int*) * (matrix_map->h + 1));
    i = 0;
    while (i <= matrix_map->h)
    {
        matrix_map->d[i] = (int *)malloc(sizeof(int) * (matrix_map->w + 1));
        i++;
    }
    fd = open(file, O_RDONLY, 0);
    if(fd <= 0)
        ft_error("not file");
    i = 0;
    while ((line = get_next_line(fd)))
    {
       get_filling(matrix_map->d[i], line);
       free(line);
       i++;
    }
    close (fd);
    matrix_map->d[i] = NULL;
    return (0);
}
