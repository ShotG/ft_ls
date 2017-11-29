/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:45:17 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 15:42:03 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*lstnew;
	unsigned char	*ptr;
	unsigned char	*newptr;
	size_t			i;

	ptr = (unsigned char *)content;
	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lstnew->content = (unsigned char *)malloc(sizeof(content_size));
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		lstnew->content_size = content_size;
		newptr = (unsigned char *)(lstnew->content);
		i = -1;
		while (++i < content_size)
			newptr[i] = ptr[i];
		lstnew->next = NULL;
	}
	return (lstnew);
}
