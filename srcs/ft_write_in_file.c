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

// write *str in *path file AT THE END mode = 0
//							AT BEGIN mode = 1
#include <libft.h>

void	ft_write_in_file(char *path, char *str)
{
	int fd;
	
	if ((fd = open(path,  S_IRWXU | O_CREAT | O_APPEND , O_RDWR)) < 0)
		return ;
	ft_putendl_fd(str, fd);
	ft_close(fd);
}
