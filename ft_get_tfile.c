#include "libft.h"

static void read_all_dir(t_file *file, char *path, DIR *dir, int recursive)
{
	struct dirent *t_dir;

	while ((t_dir = readdir(dir)))
	{
		file->next = ft_new_tfile();
		file = file->next;
		ft_get_file_information(file, t_dir, path);
		if (recursive != 0 && file->type == 'd' && 
			ft_strcmp(file->name, ".") != 0  && ft_strcmp(file->name, "..") != 0)
		{
			file->sdir = ft_get_tfile(file->path, recursive);
			ft_sort_tfile(file->sdir, NULL);
		}
	}
}

static void	ft_opendir(char *path, t_file *file, int recursive)
{
	DIR *dir;

	if (!(dir = opendir(path)))
	{
		ft_putendl_fd("get_file -> opendir :", 2);
		perror(path);
	}
	else if ((path)) 
		read_all_dir(file, path, dir, recursive);
	if (closedir(dir) == -1)
		perror(path);
}

t_file	*ft_get_tfile(char *path, int recursive)
{
	t_file *file;
	t_file *save;

	if (!(path))
	{
		ft_putendl_fd("ft_get_file : path = NULL", 2);
		return (NULL);
	}
	file = ft_new_tfile();
	save = file;
	ft_opendir(path, file, recursive);
	file = save->next;
	free(save);
	ft_sort_tfile(file, NULL);
	return (file);
}