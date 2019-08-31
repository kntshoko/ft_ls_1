/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:35:41 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/31 13:11:18 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(int *order, char **ls, char *flags)
{
	int i;
	int l;

	i = 0;
	l = -1;
	while (ls[i] != NULL)
		i++;
	if (flags[3] == '1')
		while (--i >= 0)
			ft_putendl(ls[order[i]]);
	else
		while (++l < i)
			ft_putendl(ls[order[l]]);
}
