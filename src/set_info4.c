/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:39:45 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 17:39:51 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_len_user_arr(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	int		t;
	char	*tmp;

	len = 0;
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		t = ft_strlen((arr_inp[i]).user);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).user;
		((arr_inp[i]).user) = ft_strnew(len);
		ft_memset((arr_inp[i]).user, ' ', len);
		write_str((arr_inp[i]).user, tmp);
		free(tmp);
	}
}

void	set_len_user_inp(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	int		t;
	char	*tmp;

	len = 0;
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		t = ft_strlen((arr_inp[i]).user);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).user;
		((arr_inp[i]).user) = ft_strnew(len);
		ft_memset((arr_inp[i]).user, ' ', len);
		write_str((arr_inp[i]).user, tmp);
		free(tmp);
	}
}

void	set_len_group_arr(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	int		t;
	char	*tmp;

	len = 0;
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		t = ft_strlen((arr_inp[i]).group);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).group;
		((arr_inp[i]).group) = ft_strnew(len);
		ft_memset((arr_inp[i]).group, ' ', len);
		write_str((arr_inp[i]).group, tmp);
		free(tmp);
	}
}

void	set_len_group_inp(t_obj *arr_inp, int n)
{
	int		i;
	int		len;
	int		t;
	char	*tmp;

	len = 0;
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		t = ft_strlen((arr_inp[i]).group);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).group;
		((arr_inp[i]).group) = ft_strnew(len);
		ft_memset((arr_inp[i]).group, ' ', len);
		write_str((arr_inp[i]).group, tmp);
		free(tmp);
	}
}

void	write_str(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
}
