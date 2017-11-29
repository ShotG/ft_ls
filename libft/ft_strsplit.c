/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:53:18 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/02 15:53:02 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_cwords(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			count++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char		*ft_strcreate(char const *s, char *arr, int n, char c)
{
	int j;

	j = 0;
	while (s[n + j] != c && s[n + j] != '\0')
		j++;
	arr = (char *)malloc(sizeof(char) * (j + 1));
	arr[j] = '\0';
	j = 0;
	while (s[n] != c && s[n] != '\0')
		arr[j++] = s[n++];
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	int		n;
	int		j;

	if (s == NULL)
		return (0);
	i = ft_cwords(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	n = 0;
	i = 0;
	while (i < ft_cwords(s, c))
	{
		while (s[n] == c)
			n++;
		j = 0;
		arr[i] = ft_strcreate(s, arr[i], n, c);
		while (s[n + j] != c && s[n + j] != '\0')
			n++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
