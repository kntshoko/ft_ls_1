/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impliment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:59:17 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/03 14:32:43 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_impliment(char *flags, char *path)
{
	char 	**ls;
	int		*order;

	ft_putendl(flags);
	order = ft_sort(path, flags);
	ft_putendl("___ft_impliment befor ls____");
	ls = ft_listdir(flags, path);
	ft_putendl("___ft_impliment after ls_--ended here___");
	ft_print(order, ls, flags);
	free(order);
	int i = -1;
	while(ls[++i])
		free(ls[i]);
	if (flags[2] == '1')
	{
		ft_putendl("________recurse___________");
		ft_putendl(path);
		ft_recurse(path, flags);
	}
}
