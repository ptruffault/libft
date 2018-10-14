#include "includes/libft.h"

int main(int ac, char **av, char **e)
{
	char *ret = ft_get_line_in_file(HISTORY_PATH, 5);
	
	ft_putstr(ret);
	return (0);
}
