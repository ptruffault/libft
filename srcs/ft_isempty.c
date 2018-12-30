/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:18:46 by ptruffau          #+#    #+#             */
/*   Updated: 2017/11/16 10:53:38 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_isempty(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isspace(s[i++]))
			return (0);
	}
	return (1);
}