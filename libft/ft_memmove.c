/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:21:53 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:22:23 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*p2;

	p = (unsigned char*)dst;
	p2 = (unsigned char*)src;
	i = 0;
	if (p2 < p)
		while (++i <= len)
			p[len - i] = p2[len - i];
	else
		while (len-- > 0)
			*(p++) = *(p2++);
	return (dst);
}
