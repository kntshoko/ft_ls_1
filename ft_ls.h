/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:24:34 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/01 11:03:55 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

void		ft_ls(char *path);
void		ft_checkpath(int argc, char **argv);
void		ft_flagcheck(int argc, char **argv, char *path);
void		ft_impliment(char *flags, char *path);
char		**ft_listdir(char *flags, char *path);
int			ft_countcontent(char *path, char *flags);
char		*ft_l(char *path, struct dirent *fname);
int			*ft_sort(char *path, char *flags);
int			*ft_sorttime(long *c, int l);
int			*ft_sortascii(char *path, char *flags);
void		ft_print(int *order, char **ls, char *flags);
void		ft_recurse(char *path, char *flags);
int			ft_countdir(char *path, char *flags);
char		**ft_directories(char *path, int l, char *flags);
char		*ft_join(char *s1, char *s2);
int			ft_cmp(const char *s1, const char *s2);

#endif
