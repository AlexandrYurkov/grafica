#include "libft.h"

char    *ft_strtrim(char *src, int n)
{
    char    *dst;
    int        i;
    int        len;

    i = 0;
    len = ft_strlen(src);
    dst = malloc((len - n + 1) * sizeof(char));
    if (!dst)
    {
        free (src);
        return (NULL);
    }
    while (src[n])
        dst[i++] = src[n++];
    dst[i] = '\0';
    if (src)
    {
        free(src);
        src = NULL;
    }
    return (dst);
}
