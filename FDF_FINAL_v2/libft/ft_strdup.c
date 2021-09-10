#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (dup == 0)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
