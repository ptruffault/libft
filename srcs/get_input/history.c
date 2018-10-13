/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:17:05 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/13 13:17:07 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_open(char *path)
{
	int fd;

	if ((fd = open(path, O_RDWR | O_CREAT)) < 0)
		perror(path);
	return (fd);
}

static void	init_hist(t_edit *e, int *fd, char ***arr, int *len)
{
	*fd = ft_open(HISTORY_PATH);
	if (!(*arr = ft_get_txt(*fd)))
		*len = 0;
	else
		*len = ft_strarrlen(*arr);
	if (e->curr_history == -1)
		e->curr_history = *len;
}

void		save_input_in_file(t_edit *e)
{
	int		fd;
	char	**arr;
	int		len;

	init_hist(e, &fd, &arr, &len);
	if (fd > 0)
	{
		ft_putstr_fd(e->input, fd);
		ft_putchar_fd('\n', fd);
	}
	ft_freestrarr(arr);
	if (fd != -1 && close(fd) < 0)
		perror(HISTORY_PATH);
}

void		hist_move_up(t_edit *e)
{
	int		fd;
	char	**arr;
	char	*tmp;
	int		len;

	init_hist(e, &fd, &arr, &len);
	if ((tmp = ft_strdup(arr[--e->curr_history])))
	{
		ft_strdel(&e->input);
		e->input = tmp;
	}
	ft_freestrarr(arr);
	if (fd != -1 && close(fd) < 0)
		perror(HISTORY_PATH);
	ft_print_line(e);
}

void		hist_move_down(t_edit *e)
{
	int		fd;
	char	**arr;
	char	*tmp;
	int		len;

	init_hist(e, &fd, &arr, &len);
	if (e->curr_history < len)
		return ;
	if ((tmp = ft_strdup(arr[++e->curr_history])))
	{
		ft_strdel(&e->input);
		e->input = tmp;
	}
	ft_freestrarr(arr);
	if (close(fd) < 0)
		perror(HISTORY_PATH);
	ft_print_line(e);
}
