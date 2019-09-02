/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:35:41 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/02 10:25:44 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(int *order, char **ls, char *flags)
{
	int i;
	int l;

	i = 0;
	l = -1;
	ft_putendl("___________ft_print_______");
	while (ls[i] != NULL)
	{
		ft_putnbr(order[i]);
		ft_putstr(" <<>> ");
		ft_putendl(ls[i]);
		i++;
	}
	ft_putendl("_____________ft_print______");
	if (flags[3] == '1')
	{
		while (--i >= 0 )
			ft_putendl(ls[order[i]]);
	}
	else
		while (++l < i)
			ft_putendl(ls[order[l]]);;
}
