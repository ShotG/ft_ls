/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:20:25 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 17:27:22 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	nb;
	char		*arr;
	int			len;

	nb = n;
	len = ft_numlen(nb);
	arr = ft_strnew(len);
	if (arr == NULL)
		return (NULL);
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	while (len >= 0 && arr[len - 1] != '-')
	{
		arr[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (arr);
}
