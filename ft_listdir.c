/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:54:57 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/03 18:00:56 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char     **ft_listdir(char *flags, char *path)
{
	DIR				*dname;
	struct dirent	*fname;
	char			**ls;
	int				i;
	int				l;

	i = 0;
	ft_putendl(flags);
	l = ft_countcontent(path, flags);
	ft_putendl("________ft_listdir start________");
	ft_putstr("number cotent in : ");
	ft_putstr(path);
	ft_putstr(" == ");
	ft_putnbr(l);
	dname = opendir(path);
	fname = readdir(dname);
	if (fname != NULL)
	ft_putendl("fname not null");
	else
	ft_putendl("fname is null");
	ls = (char **)malloc(sizeof(char *) * (l + 1));
	ls[l] = NULL;
	while (fname != NULL && i < l)
	{	

		if (flags[0] == '0' && fname->d_name[0] == '.')
			fname = readdir(dname);
		else if (flags[1] == '1')
		{
			ls[i] = ft_l(path, fname);
			fname = readdir(dname);
			i++;
		}
		else
		{
			ls[i] = ft_strdup(fname->d_name);
			fname = readdir(dname);
			i++;
		}
	ft_putendl("________ft_listdir end________");
	}
	closedir(dname);
	return (ls);
}
