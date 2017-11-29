/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:13:21 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 18:13:23 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_arr_dir(t_obj *arr_obj, int n, t_input *inp)
{
	int i;

	i = -1;
	while (++i < n)
	{
		free(arr_obj[i].name);
		free(arr_obj[i].path);
		if (ft_strchr(inp->flags, 'l'))
		{
			free((arr_obj[i]).permshn);
			free((arr_obj[i]).links);
			free((arr_obj[i]).size);
			free((arr_obj[i]).user);
			free((arr_obj[i]).group);
			free((arr_obj[i]).date);
		}
	}
}

int		count_obj_in_dir(char *str, t_input *inp)
{
	DIR				*dir;
	struct dirent	*dirent;
	int				i;

	dir = opendir(str);
	i = 0;
	while ((dirent = readdir(dir)))
		((dirent->d_name)[0] == '.' &&
			!(ft_strchr(inp->flags, 'a'))) ? 0 : i++;
	closedir(dir);
	return (i);
}

void	write_inp_dir_save_path(char *str, t_obj *arr_dir,
			t_input *inp, DIR *dir)
{
	struct dirent	*drnt;
	int				i;

	i = -1;
	while ((drnt = readdir(dir)))
	{
		if (!((drnt->d_name)[0] == '.' && !(ft_strchr(inp->flags, 'a'))))
		{
			arr_dir[++i].name = ft_strdup(drnt->d_name);
			arr_dir[i].path = build_path(str, drnt->d_name);
		}
	}
}

void	check_for_recurs(char *str, int n, t_input *inp, t_obj *arr_dir)
{
	char	*path;
	int		i;

	i = -1;
	if (ft_strchr(inp->flags, 'R'))
	{
		while (++i < n)
		{
			if ((arr_dir[i]).type == 'd' &&
				ft_strcmp((arr_dir[i]).name, ".") &&
					ft_strcmp((arr_dir[i]).name, ".."))
			{
				if (!((arr_dir[i].name)[0] == '.' &&
					!(ft_strchr(inp->flags, 'a'))))
				{
					write(1, "\n", 1);
					path = build_path(str, (arr_dir[i]).name);
					ft_putstr(path);
					write(1, ":\n", 2);
					write_inp_dir(path, inp, 1);
					free(path);
				}
			}
		}
	}
}

void	write_l(t_obj *arr_inp)
{
	write(1, &(arr_inp->type), 1);
	ft_putstr(arr_inp->permshn);
	write(1, "  ", 2);
	ft_putstr(arr_inp->links);
	write(1, " ", 1);
	ft_putstr(arr_inp->user);
	write(1, "  ", 2);
	ft_putstr(arr_inp->group);
	write(1, "  ", 2);
	ft_putstr(arr_inp->size);
	write(1, " ", 1);
	ft_putstr(arr_inp->date);
	write(1, " ", 1);
}
