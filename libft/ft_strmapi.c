/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:35:52 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:36:20 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*map;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((map = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
