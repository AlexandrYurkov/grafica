#include "libft.h"

int    ft_strchr(char *str, int c)
{
    int    i;

    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == c)
            return (i + 1);
        i++;
    }
    return (-1);
}
