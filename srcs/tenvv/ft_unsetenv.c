/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:35:56 by adi-rosa          #+#    #+#             */
/*   Updated: 2019/02/05 13:35:56 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tenvv.h>

t_envv		*ft_del_envv(t_envv *envv, char *name)
{
	t_envv *tmp;
	t_envv *prev;

	tmp = envv->next;
	prev = envv;
	if (ft_strequ(envv->name, name))
	{
		tmp = envv->next;
		del_tenvv(envv);
		return (tmp);
	}
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
		{
			prev->next = tmp->next;
			del_tenvv(tmp);
			return (envv);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	warning("there is no such var name in env", name);
	return (envv);
}

t_envv		*ft_unsetenv(t_envv *envv, char **t)
{
	int i;

	i = 0;
	while (t[i])
		envv = ft_del_envv(envv, t[i++]);
	return (envv);
}
