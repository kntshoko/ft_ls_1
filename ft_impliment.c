/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impliment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:59:17 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/06 14:23:22 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_impliment(char *flags, char *path)
{
	char 	**ls;
	int		*order;
	int 	j;

	j = 0;
	order = ft_sort(path, flags);
	ls = ft_listdir(flags, path);
	ft_print(order, ls, flags);
	free(order);
	while(ls[j] != NULL)
	{
		ft_strdel(&ls[j]);
		j++;
	}
	if (flags[2] == '1')
		ft_recurse(path, flags);
}
