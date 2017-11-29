/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:10:25 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 18:10:31 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_and_write_param(t_input *inp)
{
	t_obj	*arr_inp;
	int		i;

	arr_inp = (t_obj *)malloc(sizeof(t_obj) * (inp->count_path));
	i = -1;
	while (++i < inp->count_path)
		arr_inp[i].name = ft_strdup((inp->path)[i]);
	check_path_and_set_type_inp(arr_inp, inp->count_path, inp, 2);
	i = -1;
	sort_inp_param(arr_inp, inp->count_path, inp->flags);
	write_inp_param(arr_inp, inp);
	free_inp_param(arr_inp, inp->count_path, inp);
}

void	check_path_and_set_type_inp(t_obj *arr_inp, int n,
			t_input *inp, int er_f)
{
	struct stat	file_stat;
	int			i;

	i = -1;
	while (++i < n)
	{
		if ((lstat((arr_inp[i]).name, &file_stat) < 0))
		{
			(arr_inp[i]).flag_error = '-';
			error_read_param((arr_inp[i]).name,
				&(arr_inp[i]).flag_error, inp, er_f);
			continue;
		}
		(arr_inp[i]).flag_error = '+';
		if (S_ISLNK(file_stat.st_mode) &&
				((arr_inp[i]).path = (arr_inp[i]).name))
			(arr_inp[i]).type = 'l';
		else
			set_type(&file_stat, &(arr_inp[i]), 1);
		((ft_strchr(inp->flags, 'l') || ft_strchr(inp->flags, 't')) &&
			(arr_inp[i]).type != 'd') ?
				set_l_info(&file_stat, &(arr_inp[i]), inp) : 0;
	}
	(ft_strchr(inp->flags, 'l')) ? set_len_inp(arr_inp, n) : 0;
}

void	check_path_and_set_type_dir(t_obj *arr_inp, int n,
			t_input *inp, int er_f)
{
	struct stat	file_stat;
	int			i;

	i = -1;
	while (++i < n)
	{
		if ((lstat((arr_inp[i]).path, &file_stat) < 0))
		{
			error_read_param((arr_inp[i]).path,
				&(arr_inp[i]).flag_error, inp, er_f);
			continue;
		}
		(arr_inp[i]).flag_error = '+';
		if (S_ISLNK(file_stat.st_mode))
			(arr_inp[i]).type = 'l';
		else
			set_type(&file_stat, &(arr_inp[i]), 0);
		(ft_strchr(inp->flags, 'l') || ft_strchr(inp->flags, 't')) ?
			set_l_info(&file_stat, &(arr_inp[i]), inp) : 0;
	}
	(ft_strchr(inp->flags, 'l')) ? set_len_arr(arr_inp, n) : 0;
}

void	set_type(struct stat *file_stat, t_obj *arr_inp, int flag)
{
	if (flag == 0)
		stat(arr_inp->path, file_stat);
	else
		stat(arr_inp->name, file_stat);
	(S_ISDIR(file_stat->st_mode)) ? arr_inp->type = 'd' : 0;
	(S_ISREG(file_stat->st_mode)) ? arr_inp->type = '-' : 0;
	(S_ISCHR(file_stat->st_mode)) ? arr_inp->type = 'c' : 0;
	(S_ISBLK(file_stat->st_mode)) ? arr_inp->type = 'b' : 0;
	(S_ISSOCK(file_stat->st_mode)) ? arr_inp->type = 's' : 0;
}
