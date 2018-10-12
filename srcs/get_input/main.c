#include "../includes/get_input.h"

int main(int argc, char **argv, char **envv)
{
	char *ret;

	(void)argv;
	while (42)
	{
		ret = get_input(envv);
		printf("\nret =[%li] {%s}\n",ft_strlen(ret), ret );
		ft_strdel(&ret);
	}
	return (argc);
}