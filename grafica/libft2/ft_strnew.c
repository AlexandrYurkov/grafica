#include "libft.h"

char	*ft_strnew(size_t s)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (s + 1));
	if (str == NULL)
		return (NULL);
	while (s > 0)
		str[s--] = '\0';
	str[0] = '\0';
	return (str);
}