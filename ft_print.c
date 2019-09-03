/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:35:41 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/03 12:42:39 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(int *order, char **ls, char *flags)
{
	int i;
	int l;

	i = 0;
	l = -1;
	ft_putendl("_________ft_print_________");
	while (ls[i] != NULL)
		i++;
	int j = 0; 
//	while(order[j])
//	{
        ft_putnbr(order[20]);
    //    ft_putstr(" <> ");
        j++;
//	}
	if (flags[3] == '1')
	{
		while (--i >= 0 )
			ft_putendl(ls[order[i]]);
	}
	else
		while (++l < i)
			ft_putendl(ls[order[l]]);
//	free(order);
	ft_putendl("_________ft_print_________");
}
