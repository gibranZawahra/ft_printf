/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_for_conv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:58:05 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"

void	ft_print_string_for_conv(char *str, va_list ap, t_info *info)
{
	char *tmp;

	info->is_char = 0;
	info->char_z = 0;
	if (*str == 'c')
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return ;
		tmp[0] = va_arg(ap, int);
		if (tmp[0] == 0)
			info->char_z = 1;
		tmp[1] = '\0';
		info->is_char = 1;
		ft_print_string(info, tmp);
		free(tmp);
	}
	if (*str == 's')
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
			tmp = "(null)";
		ft_print_string(info, tmp);
	}
}
