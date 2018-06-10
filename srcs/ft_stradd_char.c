/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:28:54 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/10 17:33:11 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_stradd_char(char *str, char c)
{
	char	*new;
	int		len;

	if (!str)
		return (ft_char_to_str(c));
	len = ft_strlen(str);
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	new = ft_strcpy(new, str);
	new[len] = c;
	new[len + 1] = '\0';
	ft_strdel(&str);
	return (new);
}
