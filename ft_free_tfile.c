#include "libft.h"

void	ft_del_tfile(t_file *file)
{
	free(file->name);
	free(file->owner);
	free(file->group);
	free(file->date);
	free(file->mode);
	free(file->path);
	file->next = NULL;
	file->sdir = NULL;
	free(file);
}

void			ft_free_tfile(t_file *file)
{
	t_file *tmp;

	while (file)
	{
		if (file->type == 'd' && (file->sdir))
		{
			tmp = file->sdir;
			ft_free_tfile(tmp->next);
			free(file->sdir);
		}

		tmp = file->next;
		ft_del_tfile(file);
		file = tmp;

	}
}