/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:52:45 by vartyukh          #+#    #+#             */
/*   Updated: 2017/03/17 17:52:50 by vartyukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	save_input_param(int argc, char **argv, t_input **inp)
{
	int i;
	int j;

	*inp = (t_input *)malloc(sizeof(t_input));
	(*inp)->path_exec = ft_strdup(argv[0]);
	(*inp)->flags = ft_strnew(16);
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != 0)
	{
		is_flag(argv[i] + 1, *inp);
		i++;
	}
	j = 0;
	(*inp)->path = (char **)malloc(sizeof(char *) * (argc - i));
	if ((argc - i) > 0)
		while (argv[i])
			((*inp)->path)[j++] = ft_strdup(argv[i++]);
	else
		((*inp)->path)[j++] = ft_strdup(".");
	((*inp)->count_path) = j;
}

int		is_flag(char *str, t_input *inp)
{
	char	*f;
	int		i;

	f = "1lRart";
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(f, str[i]))
			error_flag(inp, str[i]);
		else
			save_flag(inp->flags, str[i]);
		i++;
	}
	return (1);
}

void	save_flag(char *s, char c)
{
	int i;

	i = 0;
	if (!ft_strchr(s, c))
	{
		while ((s)[i] != 0)
			i++;
		s[i] = c;
	}
}

void	error_flag(t_input *inp, char c)
{
	ft_putstr_fd("ft_ls", 2);
	write(2, ": ", 2);
	write(2, "illegal option -- ", 18);
	write(2, &c, 1);
	write(2, "\n", 1);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	free(inp->flags);
	free(inp->path_exec);
	free(inp);
	exit(1);
}

void	free_input_param(t_input **inp)
{
	int i;
	int j;

	i = 0;
	j = (*inp)->count_path;
	while (i < j)
	{
		free((*inp)->path[i]);
		i++;
	}
	free((*inp)->path);
	free((*inp)->flags);
	free((*inp)->path_exec);
	free(*inp);
	*inp = 0;
}
