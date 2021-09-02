#include "libft.h"

char    *ft_strjoin(char *s1, const char *s2)
{
    char    *s3;
    int        i;
    int        j;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!s3)
        return (NULL);
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[j + i] = s2[j];
        j++;
    }
    free(s1);
    s1 = NULL;
    s3[j + i] = '\0';
    return (s3);
}
