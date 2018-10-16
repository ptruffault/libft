/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenvv_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:11:41 by ptruffau          #+#    #+#             */
/*   Updated: 2018/07/04 14:11:42 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tenvv.h"

static char	*get_equal(char *name, char *value)
{
	char *tmp;
	char *ret;

	if (!(tmp = ft_strnew(ft_strlen(name) + 2)))
		return (NULL);
	tmp = ft_strcpy(tmp, name);
	tmp[ft_strlen(name)] = '=';
	tmp[ft_strlen(name) + 1] = '\0';
	if (!(ret = ft_strjoin(tmp, value)))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (ret);
}

static int	envv_len(t_envv *envv)
{
	t_envv	*tmp;
	int		i;

	i = 0;
	tmp = envv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**tenvv_to_tab(t_envv *envv)
{
	char	**t;
	t_envv	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = envv;
	len = envv_len(envv) - 1;
	if (!(t = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (i < len)
	{
		if ((t[i] = get_equal(tmp->name, tmp->value)))
			i++;
		tmp = tmp->next;
	}
	t[i] = NULL;
	return (t);
}
