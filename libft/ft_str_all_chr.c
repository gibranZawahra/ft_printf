/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_all_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:39:38 by gizawahr          #+#    #+#             */
/*   Updated: 2021/03/14 04:40:24 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_all_chr(char *str, char *search)
{
	while (*str)
	{
		while (*search)
		{
			if (*str == *search)
				return (1);
			search++;
		}
		str++;
	}
	return (0);
}
