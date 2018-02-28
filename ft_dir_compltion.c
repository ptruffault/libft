#include "libft.h"

static int 	test(char *name, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*')
		{
			while (name[j] != str[i + 1] && name[j] != '\0')
				j++;
			if (name[j] == '\0' && str[i + 1] != '\0')
				return (0);
		}
		if (str[i] != name[j])
			return (0);

	}
}

char **ft_dir_compltion(char *str, char *path)
{
	t_file *file;
	t_file *prev;

	prev = ft_new_tfile();
	file = get_tfile(path);
	while (file)
	{
		if (test(file->name, str) == 0)
		{
			printf("test : FALSE : delete :%s\n", file->name);
			prev->next = file->next;
			del_tfile(file);
			file = prev->next;
		}
		else
		{
			printf("test ok :%s\n", file->name);
			prev = file
			file = file->next;
		}
	}
}