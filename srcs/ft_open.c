/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:28:15 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 15:28:17 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_open(char *path)
{
	int fd;

	if ((fd = open(path, O_CREAT | O_RDWR)) <= 2)
	{
		warning("can't acess", path);
		perror(NULL);
	}
	return (fd);
}
