/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:35:41 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/29 16:48:40 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(int *order, char **ls, char revers)
{
	int i;

	i = 0;

	if (revers == '1')
	{
		ft_putendl("not la!!!");
		while (ls[i] != NULL)
			i++;
		while (--i >= 0)
		{
			ft_putendl(ls[order[i]]);
			free(ls[order[i]]);
		}

	}
	else
	{
		while (ls[i] != NULL)
		{
			ft_putendl(ls[order[i]]);
			free(ls[order[i]]);
			i++;
		}	
	}
	free(order);
}
