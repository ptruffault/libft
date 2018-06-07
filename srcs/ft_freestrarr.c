#include "../includes/libft.h"

void	ft_freestr(char *s)
{
	if (!s)
		return ;
	free(s);
	s = NULL;
}

void	ft_freestrarr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		ft_freestr(arr[i++]);
	arr = NULL;
}