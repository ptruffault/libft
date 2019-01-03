/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tenvv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:52 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:54 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tenvv.h>

char	*get_name(char *equal)
{
	int		i;

	i = 0;
	while (equal[i] && equal[i] != '=')
		i++;
	if (equal[i] == 0)
		return (NULL);
	return (ft_strndup(equal, i));
}

char	*get_value(char *equal)
{
	char *ptr;
	char *value;

	if (!(ptr = ft_strchr(equal, '=') + 1)
		|| !(value = ft_strdup(ptr)))
		return (NULL);
	return (value);
}

t_envv	*init_tenvv(t_envv *envv, char **tab_envv)
{
	int		i;
	int		len;
	t_envv	*tmp;

	i = 0;
	tmp = envv;
	len = ft_strarrlen(tab_envv);
	while (i < len)
	{
		if (!(tmp->name = get_name(tab_envv[i]))
		|| !(tmp->value = get_value(tab_envv[i])))
			return (envv);
		i++;
		if (!(tmp->next = new_tenvv()))
			return (envv);
		tmp = tmp->next;
	}
	return (envv);
}