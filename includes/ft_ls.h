/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:55:42 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 19:55:46 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_input
{
	char		**path;
	int			count_path;
	char		*flags;
	char		*path_exec;
	int			ret_val;
	int			tmp;
}				t_input;

typedef	struct	s_obj
{
	char		flag_error;
	char		*path;
	char		*permshn;
	char		*links;
	char		*user;
	char		*group;
	char		*size;
	char		*maj;
	char		*min;
	char		*date;
	char		*name;
	char		type;
	long int	bl_s;
	time_t		s_date;
	long		s_ns;
}				t_obj;

typedef struct	s_dev
{
	size_t		max_maj;
	size_t		max_min;
	int			tmp;
	int			n;
	int			t;
}				t_dev;

void			save_input_param(int argc, char **argv, t_input **inp);
int				is_flag(char *str, t_input *inp);
void			save_flag(char *s, char c);
void			error_flag(t_input *inp, char c);
void			free_input_param(t_input **inp);
void			read_and_write_param(t_input *inp);
void			check_path_and_set_type_inp(t_obj *arr_inp,
				int n, t_input *inp, int er_f);
void			free_inp_param(t_obj *arr_inp, int n, t_input *inp);
void			error_read_param(char *path_error, char *e_f,
				t_input *inp, int er_f);
void			write_inp_param(t_obj *arr_inp, t_input *inp);
void			sort_inp_param(t_obj *arr_inp, int n, char *flgs);
int				set_sort_arr_inp(t_obj l, t_obj r, char *flgs);
void			write_inp_file(t_obj *arr_inp, t_input *inp);
void			write_inp_dir(char *path, t_input *inp, int er_f);
int				count_obj_in_dir(char *str, t_input *inp);
char			*build_path(char *str, char *name);
void			sort_arr_dir(t_obj *arr_dir, int size, t_input *inp);
int				set_sort_arr_dir(t_obj l, t_obj r, t_input *inp);
void			print_arr_dir(t_obj *arr_dir, int n, t_input *inp);
void			check_path_and_set_type_dir(t_obj *arr_inp, int n,
				t_input *inp, int er_f);
void			free_arr_dir(t_obj *arr_obj, int n, t_input *inp);
void			write_inp_dir_save_path(char *str, t_obj *arr_dir,
				t_input *inp, DIR *dir);
void			check_for_recurs(char *str, int n, t_input *inp,
				t_obj *arr_dir);
void			set_l_info(struct stat	*file_stat, t_obj *obj_inp,
				t_input *inp);
void			set_permish(struct stat	*file_stat, t_obj *obj_f);
char			*ft_itoa_base(long int value, int base);
void			set_len_inp(t_obj *arr_inp, int n);
void			set_len_arr(t_obj *arr_inp, int n);
void			set_len_links_arr(t_obj *arr_inp, int n);
void			set_len_user_arr(t_obj *arr_inp, int n);
void			set_len_user_inp(t_obj *arr_inp, int n);
void			set_len_group_arr(t_obj *arr_inp, int n);
void			set_len_group_inp(t_obj *arr_inp, int n);
void			set_len_links_inp(t_obj *arr_inp, int n);
void			set_len_size_arr(t_obj *arr_inp, int n);
void			set_len_size_inp(t_obj *arr_inp, int n);
void			write_back(char *dst, char *src);
void			set_len_size_arr_p1(t_obj *arr_inp, t_dev *tp,
				int *len);
void			set_len_size_arr_p2(t_obj *arr_inp, char *tmp,
				t_dev *tp);
void			set_len_size_inp_p1(t_obj *arr_inp, t_dev *tp,
				int *len);
void			write_str(char *dst, char *src);
void			set_date(t_obj *obj_f, int f);
int				cmp_date(struct stat *file_stat);
int				sort_t(t_obj l, t_obj r, char *flgs);
void			write_l(t_obj *arr_inp);
void			set_type(struct stat *file_stat, t_obj *arr_inp,
				int flag);

#endif
