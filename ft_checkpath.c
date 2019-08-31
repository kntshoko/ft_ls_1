/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:05:29 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/31 16:27:47 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_callflagcheck(int argc, char **argv, char **d)
{
	int		i;
	char	*str;

	i = 0;
	if (d[i] != NULL)
	{
		while (d[i] != NULL)
		{
			str = ft_join(ft_strdup(d[i]), ft_strdup("/"));
			if (d[1] != NULL)
			{
				ft_putstr(d[i]);
				ft_putendl(":");
			}
			ft_flagcheck(argc, argv, str);
			i++;
			ft_putchar('\n');
		}
	}
	else
		ft_flagcheck(argc, argv, ".");
}

static char	*ft_listpath(char *path)
{
	char	*str;

	if (opendir(path) != NULL)
	{
		str = ft_strjoin(path, " ");
	}
	else
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		str = "\0";
	}
	return (str);
}

void		ft_checkpath(int argc, char **argv)
{
	int		cnt;
	char	*hold;
	char	*str;
	char	**d;

	d = NULL;
	str = ft_strnew(0);
	cnt = 1;
	while (cnt < argc)
	{
		if (argv[cnt][0] == '-' && ft_strlen(argv[cnt]) > 1)
			cnt++;
		else
			break ;
	}
	while (argv[cnt] != NULL)
	{
		hold = ft_strjoin(str, ft_listpath(argv[cnt]));
		free(str);
		str = ft_strdup(hold);
		free(hold);
		cnt++;
	}
	d = ft_strsplit(str, ' ');
	ft_callflagcheck(argc, argv, d);
}
