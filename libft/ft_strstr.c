/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:43:34 by vartyukh          #+#    #+#             */
/*   Updated: 2016/11/25 19:59:57 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (little[j] != '\0' && little[j] == big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char*)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
