#include "../../includes/get_input.h"

void	curs_moveto_eow(t_edit *e)
{
	while (e->t->x < (e->t->y + 1) * e->t->width)
	{
		TERM(CURSEUR_RI);
		e->t->x++;
	}
}

void	curs_moveto_bow(t_edit *e)
{
	while (e->t->x > 0)
	{
		TERM(CURSEUR_LE);
		e->t->x--;
	}
}

void	curs_reset(t_edit *e)
{
		TERM(RESET_CURS);
		e->t->x = 0;
		e->t->y = 0;
}

void	curs_move_to(t_edit *e, int x, int y)
{
	curs_reset(e);
	if (y * e->t->width + x > e->size)
	{
		x = e->size - e->t->nb_of_l * e->t->width;
		y = (e->size - x) / e->t->width;
	}
	while (e->t->y != y)
	{
		TERM(CURSEUR_DO);
		e->t->y++;
	}
	while (e->t->x != x)
		curs_move_right(e);
}

void	curs_gotonext_tab(t_edit *e)
{
	int i;

	i = e->t->x - 6;
	while (e->t->x > i)
	{
		e->t->x--;
		TERM(CURSEUR_RI);
	}
}

void	curs_gotoprev_tab(t_edit *e)
{
	int i;

	i = e->t->x + 7;
	while (e->t->x < i)
	{
		e->t->x++;
		TERM(CURSEUR_LE);
	}
}

void	curs_move_left(t_edit *e)
{
	if (e->t->x > 0)
	{
		TERM(CURSEUR_LE);
		e->t->x--;
	}
	else if (e->t->y > 0)
	{
		TERM(CURSEUR_UP);
		e->t->y--;
		curs_moveto_eow(e);
	}
}

void	curs_move_right(t_edit *e)
{
	if (e->t->x < e->t->width)
	{
		TERM(CURSEUR_RI);
		e->t->x++;
	}
	else
	{
		TERM(CURSEUR_DO);
		e->t->y++;
		if (e->t->y > e->t->nb_of_l)
			e->t->nb_of_l++;
		curs_moveto_bow(e);
	}
}

void	ft_delete(t_edit *e)
{
	int i;

	i = 0;
	curs_reset(e);
	while (i <= e->t->nb_of_l)
	{
		TERM(DELETE_LINE);
		if (i++ != e->t->nb_of_l)
			TERM(CURSEUR_DO);
	}
	curs_reset(e);
}

void	ft_putstr_no_tab(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			ft_putchar(' ');
		else
			ft_putchar(str[i]);
		i++;
	}
}

void ft_print_line(t_edit *e)
{
	int save_x;
	int save_y;

	save_x = e->t->x;
	save_y = e->t->y;
	ft_delete(e);
	ft_putstr_no_tab(e->input);
	curs_move_to(e, save_x, save_y);
}
