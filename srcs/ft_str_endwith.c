/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endwith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:40:44 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/21 15:40:49 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft.h"

int		ft_str_endwith(char *s1, char *s2)
{
	int	i;
	int j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (j >= 0)
		if (s1[i--] != s2[j--])
			return (0);
	return (1);
}
