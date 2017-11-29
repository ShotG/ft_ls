/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:51:08 by vartyukh          #+#    #+#             */
/*   Updated: 2016/11/26 18:50:10 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s_d;
	unsigned char *s_s;

	s_d = (unsigned char *)dst;
	s_s = (unsigned char *)src;
	if (s_s == s_d)
		return (s_d);
	if (s_s < s_d)
	{
		s_d = s_d + len - 1;
		s_s = s_s + len - 1;
		while (len-- > 0)
			*(s_d--) = *(s_s--);
		return (dst);
	}
	while (len-- > 0)
		*(s_d++) = *(s_s++);
	return (dst);
}
