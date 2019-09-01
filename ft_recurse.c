/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:34:27 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 08:33:30 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recurse(char *path, char *flags)
{
	char	**directories;
	int		l;
	int		i;

	ft_putendl("ft_recures");
	l = ft_countdir(path, flags);
	ft_putendl("==========================");
	directories = ft_directories(path, l, flags);
	i = 0;
	while(directories[i] != NULL)
	ft_putendl(directories[i++]);
	ft_putendl("==========================");
	i = 0;
	while (directories[i] != NULL)
	{
		ft_putchar('\n');
		ft_putstr(directories[i]);
		ft_putstr(": \n");
		ft_putnbr(i);
		ft_putchar('\n');
		ft_impliment(flags, directories[i]);
		i++;
	}
}
