/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:52:57 by vartyukh          #+#    #+#             */
/*   Updated: 2016/11/26 19:05:47 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *arr;

	arr = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, size);
	return (arr);
}
