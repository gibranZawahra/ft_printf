/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:13:34 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:15:34 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if ((p = malloc(size)) == NULL)
		return (NULL);
	while (size-- > 0)
		((unsigned char*)p)[size] = 0;
	return (p);
}
