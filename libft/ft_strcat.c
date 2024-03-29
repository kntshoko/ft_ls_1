/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:04:05 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 12:02:13 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t l;
	size_t i;

	l = 0;
	i = ft_strlen(s1);
	while (s2[l] != '\0')
	{
		s1[l + i] = s2[l];
		l++;
	}
	s1[l + i] = '\0';
	return (s1);
}
