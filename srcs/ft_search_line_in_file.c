#include "../includes/libft.h"

int	match(char *s1, char *s2)
{
	if (*s1 && *s2 == '*')
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	else if (!(*s1) && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 && *s2 && *s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (!(*s1) && !(*s2))
		return (1);
	return (0);
}

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
		if (match(arr[i], tmp) && !ft_strequ(src, arr[i]))
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