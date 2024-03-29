/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countcontent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:53:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/04 12:11:21 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_countcontent(char *path, char *flags)
{
	DIR				*dname;
	struct dirent	*fname;
	int				i;

	dname = NULL;
	dname = opendir(path);
	fname = readdir(dname);
	i = 0;
	while (fname != NULL)
	{
		if (flags[0] == '0' && fname->d_name[0] == '.')
			fname = readdir(dname);
		else
		{
			i++;
			fname = readdir(dname);
		}
	}
	closedir(dname);
	return (i);
}
