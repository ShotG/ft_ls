/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:58:00 by vartyukh          #+#    #+#             */
/*   Updated: 2016/12/01 15:50:19 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	void **ptr;

	if (as == NULL)
		return ;
	ptr = (void **)as;
	free(*ptr);
	*as = NULL;
}
