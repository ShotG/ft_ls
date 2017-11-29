/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:39:10 by vartyukh          #+#    #+#             */
/*   Updated: 2016/11/25 19:57:19 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (big[i] != '\0')
	{
		while (little[j] != '\0' && little[j] == big[i + j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
