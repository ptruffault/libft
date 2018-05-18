/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:08:40 by ptruffau          #+#    #+#             */
/*   Updated: 2017/12/03 15:59:57 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_strclr(char *str)
{
	size_t i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			str[i++] = '\0';
	}
}
