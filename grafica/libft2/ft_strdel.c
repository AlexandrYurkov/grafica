#include "libft.h"

void	ft_strdel(char **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
