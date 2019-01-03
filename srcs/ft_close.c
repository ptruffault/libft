#include <libft.h>

int ft_close(int fd)
{
	char *n;

	if (!(n = ft_itoa(fd)) || close(fd) == -1)
		warning("close failure fd ->", n);
	ft_strdel(&n);
	return (fd);
}
