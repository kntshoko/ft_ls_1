/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:49:32 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/31 17:14:15 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static long	*ft_mtime(char *path, int l)
{
	long			*c;
	DIR				*dname;
	struct dirent	*fname;
	struct stat		buff;
	int				i;

	ft_putendl("ft_mtime");
	dname = NULL;
	dname = opendir(path);
	fname = readdir(dname);
	c = (long *)malloc(l + 1);
	i = 0;
	while (fname != NULL)
	{
		stat(fname->d_name, &buff);
		c[i] = buff.st_mtime;
		fname = readdir(dname);
		i++;
	}
	closedir(dname);
	ft_putendl("ft_mtime_end");
	return (c);
}

int *ft_sort(char *path, char **flags)
{
	long	*c = NULL;
	int		*t;
	int		l;

	l = ft_countcontent(path, *flags);
	c = ft_mtime(path, l);
	ft_putendl(*flags);
	if (*flags[4] == '1')
		t = ft_sorttime(c, l);
	else
		t = ft_sortascii(path, *flags);
	return (t);
}
