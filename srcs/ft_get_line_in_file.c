/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_in_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:43:04 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 15:43:06 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char *ft_get_line_in_file(char *path, int n)
{
	char	**arr;
	char	*ret;
	int		fd;

	ret = NULL;
	arr = NULL;
	if (n < 0 || (fd = ft_open(path)) < 2)
		return (NULL);
	if ((arr = ft_get_txt(fd)) &&
	n < (int)ft_strarrlen(arr))
		ret = ft_strdup(arr[n]);
	ft_putstrarr(arr);
	ft_freestrarr(arr);
	return (ret);
}