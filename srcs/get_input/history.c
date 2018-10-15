#include "../includes/get_input.h"

static void	update_input(t_edit *e, char *s)
{
	ft_delete_line(e);
	ft_strdel(&e->input);
	e->input = s;
	e->size = ft_strlen(s) + 1;
	e->t->nb_of_l = e->size / e->t->width;
	ft_print_line(e);
	e->curr = 0;
	curs_reset(e);
}

void	hist_move_up(t_edit *e)
{
	char *s;

	if (e->input != NULL && e->curr_history == 0 && (s = ft_search_line_in_file(HISTORY_PATH, e->input)))
	{
		e->curr_history = 0;
		update_input(e, s);
	}
	else if ((s = ft_get_line_in_file(HISTORY_PATH, e->curr_history)))
	{
		e->curr_history++;
		update_input(e, s);
	}
}

void	hist_move_do(t_edit *e)
{
	char *s;

	if ((s = ft_get_line_in_file(HISTORY_PATH, e->curr_history - 1)))
	{
		e->curr_history--;
		update_input(e, s);
	}
}