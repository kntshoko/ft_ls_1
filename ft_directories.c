/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:30:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 10:45:12 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_directories(char *path, int l, char *flags)
{
	DIR				*dname;
	struct dirent	*fname;
	char			**d;
	int				i;


	ft_putendl("ft_directoriiies");
	i = 0;
	dname = opendir(path);
	fname = readdir(dname);
	d = (char **)malloc(sizeof(char *) * (l + 1));
	while (fname != NULL)
	{
		if ((ft_cmp(fname->d_name, ".") == 0 || ft_cmp(fname->d_name,
			"..") == 0) || (opendir(fname->d_name)) == NULL)
			fname = readdir(dname);
		else if (flags[0] == '0' && fname->d_name[0] == '.' )
			fname = readdir(dname);
		else
		{
			d[i] = ft_join(ft_join(ft_strdup(path), ft_strdup("/")),
					ft_strdup(fname->d_name));
			i++;
			fname = readdir(dname);
		}
	}
	closedir(dname);
	d[i] = NULL;
	ft_putendl("+++++++++++++++++++++++++");
	i = 0;
	while (d[i] != NULL)
		ft_putendl(d[i++]);
	ft_putendl("+++++++++++++++++++++++++");
	return (d);
}
