/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 07:22:13 by kntshoko          #+#    #+#             */
/*   Updated: 2019/08/29 16:13:47 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int	main(int argc, char **argv)
{
	char *str;

	if (argc == 1)
	{
		str = ft_strdup("00000");
		ft_impliment(&str, ".");
	}
	else if (argc > 1)
		ft_checkpath(argc, argv);
	return (0);
}










