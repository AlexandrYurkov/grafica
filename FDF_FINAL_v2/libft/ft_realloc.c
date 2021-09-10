#include "libft.h"

void		*ft_realloc(void *mem, size_t current_size, size_t new_size)
{
	void	*new_mem;

	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (NULL);
	ft_memcpy(new_mem, mem, current_size);
	ft_memdel(&mem);
	return (new_mem);
}

