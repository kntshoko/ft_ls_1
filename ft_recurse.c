/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:34:27 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/31 18:15:42 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recurse(char *path, char *flags)
{
	char	**directories;
	int		l;
	int		i;

	l = ft_countdir(path, flags);
	directories = ft_directories(path, l, flags);
	i = 0;
	while (i < l)
	{
		ft_putchar('\n');
		ft_putstr(directories[i]);
		ft_putstr(": \n");
		ft_impliment(&flags, directories[i]);
		i++;
	}
}
