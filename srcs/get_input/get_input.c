/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:12:58 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 13:12:59 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_input.h>

char	*get_input(void)
{
	t_edit			e;
	char			*ret;
	unsigned long	buf;

	e = init_tedit();
	while (e.edited == FALSE)
	{
		buf = 0;
		read(0, &buf, 8);
		handle_input(buf, &e);
	}
	ft_write_in_file(HISTORY_PATH, e.input);
	ret = ft_strdup(e.input);
	free_tedit(&e);
	ft_putchar('\n');
	return (ret);
}
