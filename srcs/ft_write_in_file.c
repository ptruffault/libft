/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:27:04 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 15:27:05 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write *str in *path file AT THE END mode = 2
//							AT BEGIN mode = 1
//							INSTEAD OF mode = 0
#include "../includes/libft.h"

void	ft_write_in_file(int mode, char *path, char *str)
{
	int fd;
	char **arr;
	
	if ((fd = ft_open(path)) < 2)
		return ;
	if (mode == 0)
		ft_putstr_fd(str, fd);
	else
	{	
		arr = ft_get_txt(fd);
		if (mode == 2)
			ft_putendl_fd(str, fd);
		else if (mode == 1)
		{
			close(fd);
			fd = ft_open(path);
			ft_putendl_fd(str, fd);
			
		}
		ft_freestrarr(arr);
	}
	close(fd);
}
