/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:40:47 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 15:43:01 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_l_info(struct stat	*file_stat, t_obj *obj_f, t_input *inp)
{
	if (file_stat == NULL || inp == NULL)
		;
	set_permish(file_stat, obj_f);
	obj_f->links = ft_itoa_base(file_stat->st_nlink, 10);
	if (obj_f->type == 'c' || obj_f->type == 'b')
	{
		obj_f->maj = ft_itoa_base(major(file_stat->st_rdev), 10);
		obj_f->min = ft_itoa_base(minor(file_stat->st_rdev), 10);
	}
	else
		obj_f->size = ft_itoa_base(file_stat->st_size, 10);
	obj_f->user = ft_strdup((getpwuid(file_stat->st_uid))->pw_name);
	obj_f->group = ft_strdup((getgrgid(file_stat->st_gid))->gr_name);
	obj_f->bl_s = file_stat->st_blocks;
	obj_f->date = ft_strdup(ctime(&(file_stat->st_mtime)));
	obj_f->s_date = (file_stat->st_mtimespec).tv_sec;
	obj_f->s_ns = (file_stat->st_mtimespec).tv_nsec;
	(cmp_date(file_stat)) ? set_date(obj_f, 1) : set_date(obj_f, 0);
}

void	set_permish(struct stat	*file_stat, t_obj *obj_f)
{
	int i;

	obj_f->permshn = ft_strnew(10);
	i = 0;
	(file_stat->st_mode & S_IRUSR) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWUSR) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXUSR) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IRGRP) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWGRP) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXGRP) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IROTH) ? ((obj_f->permshn)[i++] = 'r')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IWOTH) ? ((obj_f->permshn)[i++] = 'w')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_IXOTH) ? ((obj_f->permshn)[i++] = 'x')
		: ((obj_f->permshn)[i++] = '-');
	(file_stat->st_mode & S_ISUID) ? ((obj_f->permshn)[2] = 's') : 0;
	(file_stat->st_mode & S_ISGID) ? ((obj_f->permshn)[5] = 's') : 0;
	(file_stat->st_mode & S_ISVTX) ? ((obj_f->permshn)[8] = 't') : 0;
}

int		cmp_date(struct stat *f_s)
{
	time_t curtime;

	time(&curtime);
	if (((curtime / 2620800) - ((f_s->st_mtimespec).tv_sec) / 2620800) >= 6)
		return (1);
	if ((curtime) < (f_s->st_mtimespec).tv_sec)
		return (1);
	return (0);
}

void	set_date(t_obj *obj_f, int f)
{
	char	*t;
	int		i;
	int		j;

	i = 3;
	j = 0;
	t = ft_strnew(16);
	if (f == 1)
	{
		while (++i <= 9)
			t[j++] = (obj_f->date)[i];
		i = 18;
		t[j++] = ' ';
		while (++i <= 23)
			t[j++] = (obj_f->date)[i];
	}
	else
	{
		while (++i <= 15)
			t[j++] = (obj_f->date)[i];
	}
	free(obj_f->date);
	obj_f->date = t;
}
