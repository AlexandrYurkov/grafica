#include "fdf.h"

void get_filling(int *line_z, char *line)
{
    char **num;
    int j;

    num = ft_strsplit(line, ' ');
    j = 0;

    while (num[j])
    {
        line_z[j] = ft_atoi(num[j]);
        if (NULL != num[j])
            free(num[j]);
        j++;
    }
    if (NULL != num)
        free(num);
}

int *map_read(char *file, fdf *matrix_map)
{
    int i;
    int fd;
    char *line;

    matrix_map->d = (int **)malloc(sizeof(int *) * (matrix_map->realloc_size + 1));
    i = 0;
    fd = open(file, O_RDONLY, 0);
    if (fd <= 0)
        perror("not file");
    i = 1;
    get_next_line(fd, &line);
    matrix_map->w = ft_wc(line, ' ');
    matrix_map->d[0] = (int *)malloc(sizeof(int) * (matrix_map->w));
    get_filling(matrix_map->d[0], line);
    free(line);
    while ((get_next_line(fd, &line) > 0))
    {
        if (i == matrix_map->realloc_size)
        {
            matrix_map->d = (int **)ft_realloc(matrix_map->d ,sizeof(int *) * matrix_map->realloc_size, sizeof(int *) * (matrix_map->realloc_size * 2));
            matrix_map->realloc_size = matrix_map->realloc_size * 2;
        }
        matrix_map->d[i] = (int *)malloc(sizeof(int) * (matrix_map->w));
        get_filling(matrix_map->d[i], line);
        free(line);
        i++;
    }
    matrix_map->h = i;
    close(fd);
    matrix_map->d[i] = NULL;
    return (0);
}
