/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_count_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 15:52:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_count_word(char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i])
	{
		if (ft_isspace(s[i]) && !(ft_isspace(s[i - 1])))
			n++;
		i++;
	}
	if (!(ft_isspace(s[i - 1])) && !s[i])
		n++;
	return (n);
}