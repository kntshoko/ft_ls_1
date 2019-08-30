/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:37:25 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/30 15:38:24 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_swap_str(char **s1, char **s2)
{
	char *hold;

	hold = *s1;
	*s1 = *s2;
	*s2 = hold;
}

static void		ft_swap_int(int *i1, int *i2)
{
	int hold;

	hold = *i1;
	*i1 = *i2;
	*i2 = hold;
}

static char		**ft_make_sarray(char *path, char *flags, int l)
{
	DIR				*dname;
	struct dirent	*fname;
	char			**sarray;
	int				j;

	dname = opendir(path);
	fname = readdir(dname);
	sarray = (char **)malloc(l + 1);
	j = 0;
	while (fname != NULL)
	{
		if (flags[0] == '0' && fname->d_name[0] == '.')
			fname = readdir(dname);
		else
		{
			sarray[j] = fname->d_name;
			j++;
			fname = readdir(dname);
		}
	}
	closedir(dname);
	sarray[j] = NULL;
	return (sarray);
}

static int		*ft_make_c(int l)
{
	int *c;
	int i;

	c = (int *)malloc(sizeof(int) * l);
	i = -1;
	while (++i < l)
		c[i] = i;
	return (c);
}

int				*ft_sortascii(char *path, char *flags)
{
	int		i;
	int		j;
	int		l;
	int		*c;
	char	**sarray;

	l = ft_countcontent(path, flags);
	c = ft_make_c(l);
	sarray = ft_make_sarray(path, flags, l);
	i = 0;
	j = 0;
	while (sarray[++i])
	{
		printf("%d \n", i);
j++;
		if (ft_cmp(sarray[i], sarray[i - 1]) == 1)
		{
			printf("%s  vs  %s\n",sarray[i],sarray[i - 1]);
			ft_swap_str(&sarray[i], &sarray[i - 1]);
			ft_swap_int(&c[i], &c[i - 1]);
			i = 0;
		}
	}
	free(sarray);
	printf("steps = %d\n", j);
	return (c);
}
