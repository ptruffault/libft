#include "includes/libft.h"

int main(int ac, char **av, char **e)
{
	int fd;

	fd = ft_open("./history");
	printf("%i\n", fd);
	ft_putstr_fd("LOL", fd);
	return (0);
}
