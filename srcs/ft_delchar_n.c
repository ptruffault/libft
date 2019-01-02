/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_delchar_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 15:52:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char  *ft_delchar_n(char *s, int n)
{
	int len;

	if (n < 0 || (len = ft_strlen(s)) == 0 || n > len)
		return (NULL);
	while (n  < len)
	{
		s[n] = s[n + 1];
		n++;
	}
	return (s);
}
