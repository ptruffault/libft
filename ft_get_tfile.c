#include "libft.h"

static void read_all_dir(t_file *file, char *path, DIR *dir)
{
	struct dirent *t_dir;

	while ((t_dir = readdir(dir)))
	{
		file->next = ft_new_tfile();
		file = file->next;
		ft_get_file_information(file, t_dir, path);
		printf("%s\n", file->path);
		if (file->type == 'd' && *file->name != '.')
		{
			printf("enter in %s\n",file->path );
			file->sdir = ft_get_tfile(file->path);
		}
	}
}

void	ft_opendir(char *path, t_file *file)
{
	DIR *dir;

	if (!(dir = opendir(path)))
		perror(path);
	read_all_dir(file, path, dir);
	if (closedir(dir) == -1)
	{
		perror("ft_get_file : (closedir)");
		exit(-1);
	}
}

t_file	*ft_get_tfile(char *path)
{
	t_file *file;
	t_file *save;

	if (!(path))
	{
		ft_putendl_fd("ft_get_file : path = NULL", 2);
		exit(-1);
	}
	file = ft_new_tfile();
	save = file;
	ft_opendir(path, file);
	free(save);
	file = file->next;
	return (file);
}