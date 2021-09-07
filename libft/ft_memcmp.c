/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:21:31 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:21:39 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p2;

	i = 0;
	if (n == 0)
		return (0);
	p = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p == *p2 && ++i < n)
	{
		p++;
		p2++;
	}
	return ((int)(*p - *p2));
}
