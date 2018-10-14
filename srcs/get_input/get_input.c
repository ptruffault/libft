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

#include "../includes/get_input.h"

char	*get_input(char **env)
{
	t_edit			e;
	char			*ret;
	unsigned long	buf;

	e = init_tedit(env);
	while (e.edited == FALSE)
	{
		buf = 0;
		read(0, &buf, 8);
		handle_input(buf, &e);
	}
	ft_write_in_file(1, HISTORY_PATH, e.input);
	ret = ft_strdup(e.input);
	free_tedit(&e);
	return (ret);
}
