/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:34:45 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 16:34:47 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_tab_fd(char **t, int fd)
{
	int i;

	i = 0;
	while ((t[i]))
	{
		ft_putstr_fd(t[i++], fd);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_putstr_tab(char **t)
{
	ft_putstr_tab_fd(t, 1);
}
