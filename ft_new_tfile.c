#include "libft.h"

t_file		*ft_new_tfile(void)
{
	
	t_file *new;

	new = NULL;
	if (!(new =  (t_file *)malloc(sizeof(t_file))))
	{
		ft_putendl_fd("ft_new_tfile : allocation failed", 2);
		exit(-1);
	}
	new->next = NULL;
	new->sdir = NULL;
	return (new);
}