#include "libft.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}