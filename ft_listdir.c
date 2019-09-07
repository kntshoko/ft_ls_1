/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:57 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/07 16:39:46 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *ft_filename(struct dirent *fname)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (255));
	ft_strcpy(str, fname->d_name);
	return (str);
}

char     **ft_listdir(char *flags, char *path)
{
	DIR				*dname;
	struct dirent	*fname;
	char			**ls;
	int				i;
	int				l;

	i = 0;
	l = ft_countcontent(path, flags);
	dname = opendir(path);
	fname = readdir(dname);
	ls = (char **)malloc(sizeof(char *) * (l + 1));
	while (fname != NULL)
	{	

		if (flags[0] == '0' && fname->d_name[0] == '.')
			fname = readdir(dname);
		else if (flags[1] == '1')
		{
			ft_putendl("-------------------");
			ls[i] = ft_l(path, fname);
			i++;
			fname = readdir(dname);
		}
		else
		{
			ls[i] = ft_filename(fname);
			i++;
			fname = readdir(dname);
		}
	}
	closedir(dname);
	return (ls);
}
