/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:30:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/29 15:40:11 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_directories(char *path, int l, char *flags)
{
	DIR				*dname;
	struct dirent	*fname;
	char			**d;
	int				i;


	ft_putendl("ft_directories");
	i = 0;
	dname = opendir(path);
	fname = readdir(dname);
	d = (char **)malloc(sizeof(char) * (l + 1));
	while (fname != NULL)
	{
		if ((ft_strcmp(fname->d_name, ".") == 0 || ft_strcmp(fname->d_name,
			"..") == 0) && (opendir(fname->d_name)) == NULL)
			fname = readdir(dname);
		else
		{
			d[i] = ft_strjoin(fname->d_name, "/");
			i++;
			fname = readdir(dname);
		}
	}
	closedir(dname);
	d[i] = NULL;
	return (d);
}
