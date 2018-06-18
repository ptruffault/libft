/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:33:25 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 16:34:15 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_color_fd(char c , char *color, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putchar_fd(c, fd);
	ft_putstr_fd(NORMAL, 2);
}

void	ft_putchar_color(char c , char *color)
{
	ft_putchar_color_fd(c, color, 1);
}

void	ft_putstr_color_fd(char *str, char *color, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(NORMAL, 2);
}

void	ft_putstr_color(char *str, char *color)
{
	ft_putstr_color_fd(str, color, 1);
}
