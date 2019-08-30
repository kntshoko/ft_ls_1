/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:35:41 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/30 10:53:17 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(int *order, char **ls, char *flags)
{
	int i;
	int l;

	i = 0;
	l = 0;
	while (ls[i])
		i++;
	if (flags[3] == '1')
	{
		i--;
		while (i >= 0)
		{
			ft_putendl(ls[order[i]]);
			i--;
		}

	}
	else
	{
		while (l < i)
		{
			ft_putendl(ls[order[l]]);
			l++;
		}	
	}
}
