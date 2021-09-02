#include "libft.h"

char    *ft_tmpcpy(char *tmp, const char *line, int n)
{
    int    i;

    i = 0;
    while (n)
    {
        tmp[i] = line[i];
        i++;
        n--;
    }
    tmp[i] = '\0';
    return (tmp);
}
