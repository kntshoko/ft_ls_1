/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 07:22:13 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/04 17:21:53 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int	main(int argc, char **argv)
{
	ft_putendl("____main____");
	if (argc == 1)
		ft_impliment("00000", ".");
	else if (argc > 1)
		ft_checkpath(argc, argv);
	ft_putendl("____main____");
	return (0);
}
