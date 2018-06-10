/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_nchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:17:55 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/10 17:20:36 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew_nchar(char c, int n)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = ft_strnew(n + 1)))
		return (NULL);
	while (i < n)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}
