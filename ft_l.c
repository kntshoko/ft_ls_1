/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:51:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/26 16:39:18 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*ft_type(struct stat buff)
{
	char *l;

	l = ft_strnew(2);
	if (S_ISREG(buff.st_mode))
		l[0] = '-';
	else if (S_ISLNK(buff.st_mode))
		l[0] = 'l';
	else if (S_ISBLK(buff.st_mode))
		l[0] = 'b';
	else if (S_ISCHR(buff.st_mode))
		l[0] = 'c';
	else if (S_ISSOCK(buff.st_mode))
		l[0] = 's';
	else if (S_ISFIFO(buff.st_mode))
		l[0] = 'p';
	else if (S_ISDIR(buff.st_mode))
		l[0] = 'd';
	else
		l[0] = '-';
	l[1] = '\0';
	return (l);
}

static char	*ft_permissions(struct stat buff)
{
	char *l;

	l = ft_strnew(10);
	l[0] = (buff.st_mode & S_IRUSR) ? 'r' : '-';
	l[1] = (buff.st_mode & S_IWUSR) ? 'w' : '-';
	l[2] = (buff.st_mode & S_IXUSR) ? 'x' : '-';
	l[3] = (buff.st_mode & S_IRGRP) ? 'r' : '-';
	l[4] = (buff.st_mode & S_IWGRP) ? 'w' : '-';
	l[5] = (buff.st_mode & S_IXGRP) ? 'x' : '-';
	l[6] = (buff.st_mode & S_IROTH) ? 'r' : '-';
	l[7] = (buff.st_mode & S_IWOTH) ? 'w' : '-';
	l[8] = (buff.st_mode & S_IXOTH) ? 'x' : '-';
	l[9] = '\0';
	return (l);
}

char		*ft_l(struct dirent *fname)
{
	struct stat		buff;
	char			*l;
	struct group	*grp;
	struct passwd	*pss;

	stat(fname->d_name, &buff);
	grp = getgrgid(buff.st_gid);
	pss = getpwuid(buff.st_uid);
	l = ft_strjoin(ft_type(buff), ft_strjoin(ft_permissions(buff),
	ft_strjoin(" ",  ft_strjoin( ft_itoa(buff.st_nlink) , ft_strjoin("\t",
	ft_strjoin(pss->pw_name, ft_strjoin(" ", ft_strjoin( grp->gr_name,
	ft_strjoin("\t",ft_strjoin(ft_itoa(buff.st_size),ft_strjoin("\t",
	ft_strjoin(ft_strsub(ctime(&buff.st_mtime), 4, 12),
	ft_strjoin("\t", fname->d_name)))))))))))));
	return (l);
}
