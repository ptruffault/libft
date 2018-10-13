#include "includes/libft.h"

int main(int ac, char **av, char **e)
{
	char *ret;

	while (42)
	{
		ret = get_input(e);
		printf("\n{%s}\n", ret);
		ft_strdel(&ret);
	}
	return (0);
}