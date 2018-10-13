/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:09:39 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 13:09:41 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_input.h"

static void	ft_delete(t_edit *e)
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

static void	ft_putstr_no_tab(char *str)
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

void		ft_print_line(t_edit *e)
{
	int save_x;
	int save_y;

	save_x = e->t->x;
	save_y = e->t->y;
	ft_delete(e);
	ft_putstr_no_tab(e->input);
	curs_move_to(e, save_x, save_y);
}
