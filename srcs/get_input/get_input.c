#include "../includes/get_input.h"




t_edit		*get_set_edit(t_edit *new_ed)
{
	static t_edit	*stored_ed = NULL;

	if (new_ed)
		stored_ed = new_ed;
	return (stored_ed);
}

void		refresh_screen_size(int signum)
{
	t_edit	*e;
	struct winsize	window;

	(void)signum;
	e = get_set_edit(NULL);
	ioctl(0, TIOCGWINSZ, &window);
	if (e->t != NULL)
		e->t->width = window.ws_col;
}

char	*get_input(char **env)
{
	t_edit 	e;
	char	*ret;
	unsigned long buf;

	e = init_tedit(env);
	while (e.edited == FALSE)
	{
		buf = 0;		
		read(0, &buf, 8);
		handle_input(buf, &e);
	}
	save_input_in_file(&e);
	ret = ft_strdup(e.input);
	free_tedit(&e);
	return (ret);
}