/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:53:53 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 15:54:00 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_len_inp(t_obj *arr_inp, int n)
{
	set_len_links_inp(arr_inp, n);
	set_len_size_inp(arr_inp, n);
	set_len_user_inp(arr_inp, n);
	set_len_group_inp(arr_inp, n);
}

void	set_len_arr(t_obj *arr_inp, int n)
{
	set_len_links_arr(arr_inp, n);
	set_len_size_arr(arr_inp, n);
	set_len_user_arr(arr_inp, n);
	set_len_group_arr(arr_inp, n);
}

void	set_len_links_inp(t_obj *arr_inp, int n)
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
		t = ft_strlen((arr_inp[i]).links);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).type == 'd' || (arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).links;
		(arr_inp[i]).links = ft_strnew(len);
		ft_memset((arr_inp[i]).links, ' ', len);
		write_back((arr_inp[i]).links, tmp);
		free(tmp);
	}
}

void	set_len_links_arr(t_obj *arr_inp, int n)
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
		t = ft_strlen((arr_inp[i]).links);
		(t > len) ? (len = t) : 0;
	}
	i = -1;
	while (++i < n)
	{
		if ((arr_inp[i]).flag_error == '-')
			continue;
		tmp = (arr_inp[i]).links;
		((arr_inp[i]).links) = ft_strnew(len);
		ft_memset((arr_inp[i]).links, ' ', len);
		write_back((arr_inp[i]).links, tmp);
		free(tmp);
	}
}

void	write_back(char *dst, char *src)
{
	int i;
	int j;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	while (i >= 0)
	{
		dst[j] = src[i];
		i--;
		j--;
	}
}
