#include "libft.h"

char	*ft_strsub(char const *s, unsigned int c, size_t l)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(l + 1);
	if (tmp == NULL || s == NULL)
		return (NULL);
	while (i < l)
	{
		tmp[i] = s[c];
		i++;
		c++;
	}
	tmp[i] = '\0';
	return (tmp);
}
