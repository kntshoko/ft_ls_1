/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:48:18 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/30 11:02:50 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_swap_int(int *s1, int *s2)
{
	int	hold;

	hold = *s1;
	*s1 = *s2;
	*s2 = hold;
}

static	void	ft_swap_long(long *s1, long *s2)
{
	long	hold;

	hold = *s1;
	*s1 = *s2;
	*s2 = hold;
}

static int		*ft_make_t(int l)
{
	int		*t;
	int		j;

	j = 0;
	t = (int *)malloc(sizeof(int) * l);
	while (j < l)
	{
		t[j] = j;
		j++;
	}
	return (t);
}

int			*ft_sorttime(long *c, int l)
{
	int		*t;
	int		i;
	int		j;

	t = ft_make_t(l);
	j = 0;
	j = 0;
	while (j < l)
	{
		i = 0;
		while (i < l)
		{
			if (c[i] > c[j])
			{
				ft_swap_long(&c[i], &c[j]);
				ft_swap_int(&t[i], &t[j]);
			}
			i++;
		}
		j++;
	}
	return (t);
}
