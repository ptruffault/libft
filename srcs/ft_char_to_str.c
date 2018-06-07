#include "libft.h"

char *ft_char_to_str(char c)
{
	char *new;

	if (!(new = ft_strnew(2)))
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	return (new);
}