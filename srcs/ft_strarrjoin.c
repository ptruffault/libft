/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:29:27 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 14:29:31 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char **ft_strarrjoin(char **src, char **to_add)
{
	char **new;
	int i;
	int j;

	if (!src && (to_add))
		return (to_add);
	if (!to_add && (src))
		return (src);
	if (!src && !to_add)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) *  
	ft_strarrlen(src) + ft_strarrlen(to_add) + 1)))
		return (NULL);
	i = -1;
	while ((src) && src[++i])
		new[i] = ft_strdup(to_add[i]);
	j  = 0;
	while  ((to_add) && to_add[j])
		new[i++] = ft_strdup(to_add[j++]);
	new[i] = NULL;
	return (src);
}

char **ft_strarrjoin_fr(char **src, char **to_add)
{
	char **ret;

	ret = ft_strarrjoin(src, to_add);
	ft_freestrarr(to_add);
	ft_freestrarr(src);
	return (ret);
}
