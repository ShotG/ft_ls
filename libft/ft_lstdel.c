/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:36:24 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 19:44:36 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *nextptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		nextptr = ptr->next;
		free(ptr);
		ptr = nextptr;
	}
	ptr = NULL;
	*alst = NULL;
}
