#include "../includes/get_input.h"

void	curr_move_right(t_edit *e)
{
	if (e->curr + 1 < e->size)
	{
		e->curr++;
		curs_move_right(e);
	}
}

void	curr_move_left(t_edit *e)
{
	if (e->curr > 0)
	{
		e->curr--;
		curs_move_left(e);
	}
}


void handle_input(unsigned long buf, t_edit *e)
{
	if (buf == KEY_ENTER)
		e->edited = TRUE;
	else if (buf == ARROW_LEFT)
		curr_move_left(e);
	else if (buf == ARROW_RIGHT)
		curr_move_right(e);
	else if (buf == ARROW_UP)
		hist_move_up(e);
	else if (buf == ARROW_DOWN)
		hist_move_down(e);
	else if (buf == TOUCHE_SUPPR)
		delete_left(e);
//	else if (buf == TOUCHE_DEL)
//		delete_on(e);
//	else if (buf == TOUCHE_HOME)
//		curs_reset(e);
//	else if (buf == TOUCHE_END)
//		curs_gotoend(e);
	else if (buf == TOUCHE_F5)
		TERM(CLEAR);
	else if (buf == TOUCHE_CTRL_C)
		ft_exit(e);
	else
		ft_add_char((char)buf, e);
}

