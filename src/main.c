/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:56:45 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 17:56:50 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_inp_param(t_obj *arr_inp, int n, t_input *inp)
{
	int i;

	i = -1;
	while (++i < n)
	{
		free((arr_inp[i]).name);
		if ((ft_strchr(inp->flags, 'l') && (arr_inp[i]).type != 'd'))
		{
			free((arr_inp[i]).permshn);
			free((arr_inp[i]).links);
			free((arr_inp[i]).size);
			free((arr_inp[i]).user);
			free((arr_inp[i]).group);
			free((arr_inp[i]).date);
		}
	}
}

void	error_read_param(char *path_error, char *e_f,
			t_input *inp, int er_f)
{
	inp->ret_val = er_f;
	(e_f != NULL) ? (*e_f = '-') : 0;
	ft_putstr_fd("ft_ls", 2);
	write(2, ": ", 2);
	ft_putstr_fd(path_error, 2);
	write(2, ": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

int		main(int argc, char **argv)
{
	t_input	*inp;
	int		status;

	save_input_param(argc, argv, &inp);
	inp->ret_val = 0;
	read_and_write_param(inp);
	status = inp->ret_val;
	free_input_param(&inp);
	return (status);
}
