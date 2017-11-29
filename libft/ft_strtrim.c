/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:56:29 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 17:33:18 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_absol(size_t i, size_t len)
{
	if (i < len)
		return (len - i);
	if (i > len)
		return (i - len);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;
	size_t	c;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t') &&
		len != 0)
		len--;
	str = ft_strnew(ft_absol(i, len));
	if (str == NULL)
		return (NULL);
	c = 0;
	while (i < len)
		str[c++] = s[i++];
	str[c] = '\0';
	return (str);
}
