/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:44 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 10:46:21 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	len;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s = 0;
	while (s1[s] && ft_strchr(set, s1[s]) != NULL)
		s++;
	len = ft_strlen(&s1[s]);
	if (len != 0)
		while (s1[s + len - 1]
				&& ft_strchr(set, s1[s + len - 1]) != NULL)
			len--;
	if ((trim = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trim = ft_strncpy(trim, &s1[s], len);
	trim[len] = '\0';
	return (trim);
}
