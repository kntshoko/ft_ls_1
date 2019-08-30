/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impliment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:59:17 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/30 10:53:22 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_impliment(char **flags, char *path)
{
	char **ls;
	char c;

	ls = ft_listdir(flags, path);
	ft_print(ft_sort(path, flags), ls, *flags);
	if (*(flags[0] + 2) == '1')
		ft_recurse(path,*flags);
	free(*flags);
}
