/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:57 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/29 16:40:49 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char     **ft_listdir(char **flags, char *path)
{
	DIR *dname;
	struct dirent *fname;
	char **ls;
	int i;
	int l;

	i = 0;
	l = ft_countcontent(path, *flags);
	dname = opendir(path);
	fname = readdir(dname);
	ls = (char **)malloc(sizeof(char *) * (l + 1));
	while (fname != NULL)
	{
		if (*flags[0] == '0' && fname->d_name[0] == '.')
			fname = readdir(dname);
		else if (*(flags[0] + 1) == '1')
		{
			ls[i] = ft_l(fname);
			fname = readdir(dname);
			i++;
		}
		else
		{
			ls[i] = ft_strdup(fname->d_name);
			fname = readdir(dname);
			i++;
		}
	}
	closedir(dname);
	ls[i] = NULL;
	return (ls);
}
