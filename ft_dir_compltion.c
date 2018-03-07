#include "libft.h"

static int 	test(char *name, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ft_strcmp(str, "*") == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '*')
		{
			while (name[j] != str[i + 1] && name[j] != '\0')
				j++;
			i++;
			if (name[j] == '\0' && str[i] != '\0')
				return (0);
			else if (name[j] == '\0')
				return (1);
		}
		if (str[i++] != name[j++])
			return (0);
	}
	return (1);
}

static void ft_sort(t_file *file, t_file *prev, char *str)
{
	while (file)
	{
		if (test(file->name, str) == 0)
		{
			prev->next = file->next;
			ft_del_tfile(file);
			file = prev->next;
		}
		else
		{
			prev = file;
			file = file->next;
		}
	}
}

t_file *ft_dir_compltion(char *str, char *path)
{
	t_file *head;
	t_file *file;
	t_file *prev;

	file = ft_new_tfile();
	prev = file;
	file->next = ft_get_tfile(path, 0);
	file = file->next;
	head = prev;
	ft_sort(file, prev, str);
	prev = head;
	head = head->next;
	free(prev);
	return (head);
}