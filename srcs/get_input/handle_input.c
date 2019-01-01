/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:14:33 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 13:14:34 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_input.h"

static void	curr_move_right(t_edit *e)
{
	if (e->curr + 1 < e->size)
	{
		e->curr++;
		curs_move_right(e);
	}
}

static void	curr_move_left(t_edit *e)
{
	if (e->curr > 0)
	{
		e->curr--;
		curs_move_left(e);
	}
}


void		handle_input(unsigned long buf, t_edit *e)
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
		hist_move_do(e);
	else if (buf == TOUCHE_SUPPR)
		delete_left(e);
	else if (buf == TOUCHE_DEL)
		delete_on(e);
	else if (buf == TOUCHE_HOME)
		curs_reset(e);
	else if (buf == TOUCHE_END)
		curs_move_to(e, -1, -1);
	else if (buf == TOUCHE_F5)
		TERM(CLEAR);
	else if (buf == TOUCHE_CTRL_C)
		ft_exit(e);
	else 
		ft_add_char((char)buf, e);
}
