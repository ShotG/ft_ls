/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:13:07 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 18:13:14 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	write_inp_param(t_obj *arr_inp, t_input *inp)
{
	int i;

	i = -1;
	while (++i < inp->count_path)
	{
		if ((arr_inp[i]).flag_error == '+')
		{
			if ((arr_inp[i]).type == 'd')
			{
				if (inp->count_path > 1)
				{
					(i != 0 && (arr_inp[i - 1]).flag_error != '-') ?
						write(1, "\n", 1) : 0;
					ft_putstr(arr_inp[i].name);
					write(1, ":\n", 2);
				}
				write_inp_dir((arr_inp[i]).name, inp, 2);
			}
			else
				write_inp_file(&(arr_inp[i]), inp);
		}
	}
}

void	write_inp_dir(char *str, t_input *inp, int er_f)
{
	DIR			*dir;
	t_obj		*arr_dir;
	int			tmp;

	if (!(dir = opendir(str)))
	{
		error_read_param(str, 0, inp, er_f);
		return ;
	}
	else
	{
		tmp = count_obj_in_dir(str, inp);
		arr_dir = (t_obj *)malloc(sizeof(t_obj) * (tmp));
		write_inp_dir_save_path(str, arr_dir, inp, dir);
	}
	closedir(dir);
	check_path_and_set_type_dir(arr_dir, tmp, inp, 1);
	sort_arr_dir(arr_dir, tmp, inp);
	print_arr_dir(arr_dir, tmp, inp);
	check_for_recurs(str, tmp, inp, arr_dir);
	free_arr_dir(arr_dir, tmp, inp);
	free(arr_dir);
}

void	print_arr_dir(t_obj *arr_dir, int n, t_input *inp)
{
	int			i;
	long int	s;
	int			z;

	i = -1;
	z = 0;
	while (++i < n)
		if ((arr_dir[i]).flag_error == '+')
			z = 1;
	i = -1;
	if (ft_strchr(inp->flags, 'l'))
	{
		s = 0;
		while (++i < n)
			s += (arr_dir[i]).bl_s;
		if (z)
		{
			write(1, "total ", 6);
			ft_putnbr(s);
			write(1, "\n", 1);
		}
		i = -1;
	}
	while (++i < n)
		write_inp_file(&(arr_dir[i]), inp);
}

void	write_inp_file(t_obj *arr_inp, t_input *inp)
{
	char *buff;

	if (arr_inp->flag_error == '+')
	{
		if (ft_strchr(inp->flags, 'l'))
			write_l(arr_inp);
		if (arr_inp->type == 'l' && ft_strchr(inp->flags, 'l'))
		{
			buff = ft_strnew(1024);
			readlink(arr_inp->path, buff, 1024);
			ft_putstr(arr_inp->name);
			write(1, " -> ", 4);
			ft_putendl(buff);
			free(buff);
		}
		else
			ft_putendl(arr_inp->name);
	}
}

char	*build_path(char *str, char *name)
{
	int		i;
	char	*res;
	char	*t;

	res = ft_strdup(str);
	i = 0;
	while (res[i] != 0)
		i++;
	if (res[i - 1] != '/')
	{
		t = res;
		res = ft_strjoin(t, "/");
		free(t);
	}
	t = res;
	res = ft_strjoin(t, name);
	free(t);
	return (res);
}
