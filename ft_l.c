/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:51:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 11:25:42 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*ft_type(struct stat buff)
{
	char *l;

	l = ft_strnew(1);
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

char		*ft_l(char *path, struct dirent *fname)
{
	struct stat		buff;
	char			*l;
	struct group	*grp;
	struct passwd	*pss;
	char			*npath;

	ft_putendl("------ft_listdir--------");
	npath = ft_join(ft_strdup(path), ft_strjoin("/", fname->d_name));
	stat(npath, &buff);
	grp = getgrgid(buff.st_gid);
	pss = getpwuid(buff.st_uid);
	l = ft_join(ft_type(buff), ft_join(ft_permissions(buff),
	ft_join(ft_strdup(" "),  ft_join(ft_itoa(buff.st_nlink) , ft_join(ft_strdup("\t"),
	ft_join(ft_strdup(pss->pw_name), ft_join(ft_strdup(" "),
	ft_join(ft_strdup(grp->gr_name), ft_join(ft_strdup("\t") ,
	ft_join(ft_itoa(buff.st_size), ft_join(ft_strdup("\t") ,
	ft_join(ft_strsub(ctime(&buff.st_mtime), 4, 12),
	ft_join(ft_strdup("\t"), ft_strdup(fname->d_name))))))))))))));
	free(npath);
	return (l);
}
