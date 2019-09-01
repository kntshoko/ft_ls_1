/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:32:52 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 11:29:25 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_countdir(char *path, char *flags)
{
	DIR				*dname;
	struct dirent	*f;
	int				i;
	char			*npath;

	i = 0;
	dname = opendir(path);
	f = readdir(dname);
	while (f != NULL)
	{
	ft_putendl("-------ft_countdir---------");
		npath = ft_join(ft_strdup(path), ft_join(ft_strdup("/"),
		ft_strdup(f->d_name)));
		if (ft_cmp(f->d_name, ".") == 0 || ft_cmp(f->d_name, "..") == 0)
			f = readdir(dname);
		else if (flags[0] == '0' && f->d_name[0] == '.')
			f = readdir(dname);
		else
		{
			if (opendir(npath) != NULL)
				i++;
			f = readdir(dname);
		}
		ft_strdel(&npath);
	}
	closedir(dname);
	return (i);
}
