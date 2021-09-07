/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:24:58 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 12:17:19 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int srcl;

	srcl = ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= i)
		srcl = srcl + dstsize;
	else
		srcl = srcl + i;
	if (dstsize > i)
		while (src[j] && i + 1 < dstsize)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	dst[i] = 0;
	return (srcl);
}
