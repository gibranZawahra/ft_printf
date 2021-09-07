/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_for_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:12:16 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:44:45 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

char		*ft_get_info_for_flag(t_info *info, char *str)
{

	ft_bzero(info->flag, sizeof(t_flag_info));
	info->sign = -1;
	while (*str == '-' || *str == ' ' || *str == '0' || *str == '+')
	{
		if (*str == '-')
			info->flag->minus = '-';
		else if (*str == '0')
			info->flag->zero = 'y';
		str++;
	}
	return (str);
}
