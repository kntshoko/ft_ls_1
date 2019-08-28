/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:32:52 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/21 11:35:21 by kntshoko         ###   ########.fr       */
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
		npath = ft_strjoin(path, ft_strjoin("/", f->d_name));
		if (ft_strcmp(f->d_name, ".") == 0 || ft_strcmp(f->d_name, "..") == 0)
			f = readdir(dname);
		else if (flags[0] == '0' && f->d_name[0] == '.')
			f = readdir(dname);
		else
		{
			if (opendir(npath) != NULL)
				i++;
			f = readdir(dname);
		}
		free(npath);
	}
	closedir(dname);
	return (i);
}
