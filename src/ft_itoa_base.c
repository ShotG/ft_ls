/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:46:43 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 17:50:17 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	f(long int value, int base, char *str, int *i)
{
	char *s;

	s = "0123456789ABCDEF";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = s[value % base];
}

char	*ft_itoa_base(long int value, int base)
{
	char	*str;
	int		i;

	if (base < 2 || base > 16 || !(str = (char *)malloc(32)))
		return (0);
	i = 0;
	if (base == 10 && value < 0)
		str[i++] = '-';
	if (value < 0)
		value = value * (-1);
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
