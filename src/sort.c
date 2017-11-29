/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:10:56 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 18:11:02 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_inp_param(t_obj *arr_inp, int n, char *flgs)
{
	int		i;
	int		j;
	t_obj	tmp;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (set_sort_arr_inp(arr_inp[j], arr_inp[j + 1], flgs))
			{
				tmp = arr_inp[j];
				arr_inp[j] = arr_inp[j + 1];
				arr_inp[j + 1] = tmp;
			}
		}
	}
}

int		set_sort_arr_inp(t_obj l, t_obj r, char *flgs)
{
	if (l.type == 'd' && r.type != 'd')
		return (1);
	else if ((l.type != 'd' && r.type != 'd') ||
		(l.type == 'd' && r.type == 'd'))
	{
		if ((ft_strchr(flgs, 't')))
			return (sort_t(l, r, flgs));
		else
		{
			if ((ft_strcmp(l.name, r.name) > 0 && !ft_strchr(flgs, 'r')) ||
				(ft_strcmp(l.name, r.name) < 0 && ft_strchr(flgs, 'r')))
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

void	sort_arr_dir(t_obj *arr_dir, int size, t_input *inp)
{
	int		i;
	int		j;
	t_obj	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (set_sort_arr_dir(arr_dir[j], arr_dir[j + 1], inp))
			{
				tmp = arr_dir[j];
				arr_dir[j] = arr_dir[j + 1];
				arr_dir[j + 1] = tmp;
			}
		}
	}
}

int		set_sort_arr_dir(t_obj l, t_obj r, t_input *inp)
{
	if ((ft_strchr(inp->flags, 't')))
		return (sort_t(l, r, inp->flags));
	else
	{
		if ((ft_strcmp(l.name, r.name) > 0 && !ft_strchr(inp->flags, 'r')) ||
			(ft_strcmp(l.name, r.name) < 0 && ft_strchr(inp->flags, 'r')))
			return (1);
		else
			return (0);
	}
}

int		sort_t(t_obj l, t_obj r, char *flgs)
{
	if (l.s_date == r.s_date)
	{
		if (l.s_ns == r.s_ns)
		{
			if ((ft_strcmp(l.name, r.name) > 0 && !ft_strchr(flgs, 'r')) ||
				(ft_strcmp(l.name, r.name) < 0 && ft_strchr(flgs, 'r')))
				return (1);
			else
				return (0);
		}
		if ((l.s_ns < r.s_ns && !ft_strchr(flgs, 'r')) ||
			(l.s_ns > r.s_ns && ft_strchr(flgs, 'r')))
			return (1);
		else
			return (0);
	}
	if ((l.s_date < r.s_date && !ft_strchr(flgs, 'r')) ||
		(l.s_date > r.s_date && ft_strchr(flgs, 'r')))
		return (1);
	else
		return (0);
}
