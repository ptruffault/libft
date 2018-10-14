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

static int delete_content(char *path)
{
	int fd;

	if ((fd = open(path, O_WRONLY)) <= 2)
	{
		warning("can't delete content", path);
		perror(NULL);
	}
	return (fd);
}

void	ft_write_in_file(int mode, char *path, char *str)
{
	int fd;
	char **arr;
	
	if (mode == 0)
	{
		fd = delete_content(path);
		ft_putstr_fd(str, fd);
	}
	else if ((fd = ft_open(path)) < 2)
		return ;
	else if (mode == 1)
		ft_putendl_fd(str, fd);
	else if (mode == 2)
	{	
		arr = ft_get_txt(fd);
		ft_putstr_fd(str, fd);
		ft_freestrarr(arr);
	}
	close(fd);
}
