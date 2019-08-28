/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:20:54 by kntshoko          #+#    #+#             */
/*   Updated: 2019/07/10 15:02:05 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t l;

	l = 0;
	while (l <= ft_strlen(s))
	{
		if (s[l] == (unsigned char)c)
			return ((char *)&s[l]);
		l++;
	}
	return (0);
}
