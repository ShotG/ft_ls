/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:58:55 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 15:59:04 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_len_size_arr(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	char	*tmp;
	t_dev	tp;

	len = 0;
	tp.max_maj = 0;
	tp.max_min = 0;
	tp.n = n;
	set_len_size_arr_p1(arr_inp, &tp, &len);
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		if ((arr_inp[i]).type == 'c' || (arr_inp[i]).type == 'b')
			set_len_size_arr_p2(&arr_inp[i], tmp, &tp);
		tmp = (arr_inp[i]).size;
		((arr_inp[i]).size) = ft_strnew(len);
		ft_memset((arr_inp[i]).size, ' ', len);
		write_back((arr_inp[i]).size, tmp);
		free(tmp);
	}
}

void	set_len_size_inp(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	char	*tmp;
	t_dev	tp;

	len = 0;
	tp.max_maj = 0;
	tp.max_min = 0;
	tp.n = n;
	set_len_size_inp_p1(arr_inp, &tp, &len);
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		if ((arr_inp[i]).type == 'c' || (arr_inp[i]).type == 'b')
			set_len_size_arr_p2(&arr_inp[i], tmp, &tp);
		tmp = (arr_inp[i]).size;
		((arr_inp[i]).size) = ft_strnew(len);
		ft_memset((arr_inp[i]).size, ' ', len);
		write_back((arr_inp[i]).size, tmp);
		free(tmp);
	}
}

void	set_len_size_inp_p1(t_obj *arr_inp, t_dev *tp, int *len)
{
	int i;

	i = -1;
	while (++i < tp->n)
	{
		if ((arr_inp[i]).flag_error == '-' || (arr_inp[i]).type == 'd')
			continue;
		if ((arr_inp[i]).type == 'c' || (arr_inp[i]).type == 'b')
		{
			(tp->t = ft_strlen((arr_inp[i]).maj) +
					ft_strlen((arr_inp[i]).min) + 2);
			(ft_strlen((arr_inp[i]).maj) > tp->max_maj) ?
				(tp->max_maj = ft_strlen((arr_inp[i]).maj)) : 0;
			(ft_strlen((arr_inp[i]).min) > tp->max_min) ?
				(tp->max_min = ft_strlen((arr_inp[i]).min)) : 0;
		}
		else
			tp->t = ft_strlen((arr_inp[i]).size);
		(tp->t > *len) ? (*len = tp->t) : 0;
	}
}

void	set_len_size_arr_p1(t_obj *arr_inp, t_dev *tp, int *len)
{
	int i;

	i = -1;
	while (++i < tp->n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		if ((arr_inp[i]).type == 'c' || (arr_inp[i]).type == 'b')
		{
			(tp->t = ft_strlen((arr_inp[i]).maj) +
					ft_strlen((arr_inp[i]).min) + 2);
			(ft_strlen((arr_inp[i]).maj) > tp->max_maj) ?
				(tp->max_maj = ft_strlen((arr_inp[i]).maj)) : 0;
			(ft_strlen((arr_inp[i]).min) > tp->max_min) ?
				(tp->max_min = ft_strlen((arr_inp[i]).min)) : 0;
		}
		else
			tp->t = ft_strlen((arr_inp[i]).size);
		(tp->t > *len) ? (*len = tp->t) : 0;
	}
}

void	set_len_size_arr_p2(t_obj *arr_inp, char *tmp, t_dev *tp)
{
	tmp = arr_inp->maj;
	(arr_inp->maj) = ft_strnew(tp->max_maj);
	ft_memset(arr_inp->maj, ' ', tp->max_maj);
	write_back(arr_inp->maj, tmp);
	free(tmp);
	tmp = arr_inp->min;
	arr_inp->min = ft_strnew(tp->max_min);
	ft_memset(arr_inp->min, ' ', tp->max_min);
	write_back(arr_inp->min, tmp);
	free(tmp);
	tmp = ft_strdup(", ");
	arr_inp->size = ft_strjoin(arr_inp->maj, tmp);
	free(tmp);
	tmp = arr_inp->size;
	arr_inp->size = ft_strjoin(arr_inp->size, arr_inp->min);
	free(tmp);
	free(arr_inp->min);
	free(arr_inp->maj);
}
