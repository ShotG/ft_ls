/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:11:36 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 16:07:27 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f((char)s[i]);
	str[i] = '\0';
	return (str);
}
