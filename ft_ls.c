/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:08:06 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 10:54:11 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *path)
{
	DIR				*dname;
	struct dirent	*fname;

	dname = NULL;
	dname = opendir(path);
	fname = readdir(dname);
	while (fname != NULL)
	{
		if (fname->d_name[0] != '.')
			ft_putendl(fname->d_name);
		fname = readdir(dname);
	}
	closedir(dname);
}
