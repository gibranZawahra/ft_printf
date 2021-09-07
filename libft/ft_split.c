/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:53:25 by gizawahr          #+#    #+#             */
/*   Updated: 2019/11/19 12:26:57 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void		*empty(char **strs)
{
	int i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	tabs;

	if (s == NULL)
		return (NULL);
	tabs = count(s, c);
	if ((strs = (char**)malloc(sizeof(char*) * (tabs + 1))) == NULL)
		return (NULL);
	tabs = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if ((strs[tabs++] = ft_strndup(&s[j], i)) == NULL)
			return (empty(strs));
		j += i - 1;
	}
	strs[tabs] = NULL;
	return (strs);
}
