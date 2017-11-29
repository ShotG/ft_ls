/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:35:09 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 15:48:07 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = s1;
	str2 = s2;
	i = -1;
	while (++i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
