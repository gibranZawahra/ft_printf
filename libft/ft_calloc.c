/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:06:05 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 13:41:00 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (!(result = malloc(size * nmemb)))
		return (NULL);
	while (i <= nmemb)
	{
		((char*)result)[i] = 0;
		i++;
	}
	return (result);
}
