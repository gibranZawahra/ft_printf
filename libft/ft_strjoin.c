/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:33:47 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:34:13 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((join = (char*)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	join = ft_strcpy(join, s1);
	return (ft_strcat(join, s2));
}
