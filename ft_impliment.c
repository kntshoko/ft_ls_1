/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impliment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:59:17 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/27 17:03:58 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_impliment(char *flags, char *path)
{
	char **ls;

	ls = ft_listdir(flags, path);
	ft_putendl("**************************impliment*****************************");
	int i = 0;
	while (ls[i] != NULL)
	{
		ft_putendl(ls[i]);
		i++;
	}

	ft_putendl("**************************impliment*****************************");
	ft_putendl("aaaaaaaaa!");
	ft_print(ft_sort(path, flags), ls, flags[3]);
	if (flags[2] == '1')
		ft_recurse(path, flags);
	ft_strdel(&flags);
}
