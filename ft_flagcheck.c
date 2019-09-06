/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:01:48 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/04 17:21:49 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flagcheck(int argc, char **argv, char *path)
{
	int		cnt;
	int		i;
	int		j;
	int		l;
	char	*flg;
	char	*flags;

	cnt = 1;
	flg = ft_strdup("alRrt");
	flags = ft_strdup("00000");
	while (cnt < argc && argv[cnt][0] == '-')
	{
		i = 1;
		l = ft_strlen(argv[cnt]);
		if (l > 2)
		{
			while (i < l)
			{
				j = 0;
				while (j < 5)
				{
					if (flg[j] == argv[cnt][i])
						flags[j] = '1';
					j++;

				}
				i++;
			}
		}
		else
		{
			j = 0;
			while (j < 5)
			{
				if (flg[j] == argv[cnt][i])
					flags[j] = '1';
				j++;
			}
		}
		cnt++;
	}
	ft_impliment(flags, path);
}
