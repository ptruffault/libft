#include "../../includes/libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, prev_size < new_size ? prev_size : new_size);
	free(ptr);
	return (new);
}