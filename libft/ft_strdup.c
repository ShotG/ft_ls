/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:55:48 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 16:04:32 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		n;
	int		i;

	i = -1;
	n = ft_strlen(s1);
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str != NULL)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
