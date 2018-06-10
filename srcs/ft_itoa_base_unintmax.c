/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unintmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:50:15 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/10 17:50:18 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		f(uintmax_t value, unsigned int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[*i] = tmp[value % base];
	(*i)++;
}

char			*ft_itoa_base_unintmax(uintmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
