#include "../includes/libft.h"

char *ft_search_line_in_file(char *path, char *src)
{
	int fd;
	int i;
	char **arr;
	char *ret;
	char *tmp;

	if ((fd = ft_open(path)) <= 2)
		return (NULL);
	arr = ft_get_txt(fd);
	tmp = ft_stradd_char(ft_strdup(src), '*');
	i = 0;
	while (arr[i])
	{
		if (ft_match(arr[i], tmp) && !ft_strequ(src, arr[i]))
		{
			ret = ft_strdup(arr[i]);
			ft_freestrarr(arr);
			close(fd);
			return (ret);
		}
		i++;
	}
	return (NULL);
}