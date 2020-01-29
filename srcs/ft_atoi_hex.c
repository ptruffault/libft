/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:40:24 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/29 14:40:32 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi_hex(char *str)
{
	int					z;
	unsigned int		res;

	z = 1;
	res = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			res = res * 16 + *str - 'a' + 10;
		else
			res = res * 16 + *str - 'A' + 10;
	}
	return (res);
}
