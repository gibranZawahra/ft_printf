/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_field_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:13:56 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:44:06 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	ft_take_point(t_info *info, char *str)
{
	int i;

	i = 0;
	info->pt_n = 0;
	info->n_pt_n = 0;
	info->n_pt = 0;
	if (str[i] == '.')
		info->pt_n = 1 + 0 * i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'
		|| str[i] == '*')
	{
		if (info->pt_n == 0 && str[i] == '.')
		{
			info->n_pt = 1;
			if (str[i + 1] == '*'
				|| (str[++i] >= '0' && str[i] <= '9'))
			{
				info->n_pt_n = 1;
				info->n_pt = 0;
			}
		}
		i++;
	}
	info->field_width = -1;
	info->field_width_next = -1;
}

char	*ft_field_with_stars(t_info *info, va_list ap, char *str)
{

	if (info->pt_n == 1 || (info->n_pt_n == 1 && info->field_width > 0))
		info->field_width_next = va_arg(ap, int);
	else
		info->field_width = va_arg(ap, int);
	if (info->field_width < 0)
	{
		info->field_width = -info->field_width;
		info->flag->minus = '-';
	}
	if (info->field_width_next < 0 && info->pt_n == 1)
		info->pt_n = 0;
	else if (info->field_width_next < 0)
		info->field_width_next *= -1;
	str++;
	return (str);
}

char	*ft_get_field_width(t_info *info, char *str, va_list ap)
{

	ft_take_point(info, str);
	if (*str >= '1' && *str <= '9')
		info->field_width = ft_atoi(str);
	while ((*str >= '0' && *str <= '9'))
		str++;
	if (*str == '.')
		str++;
	if (*str == '*')
		str = ft_field_with_stars(info, ap, str);
	if (*str == '.')
		str++;
	if (*str >= '0' && *str <= '9')
		info->field_width_next = ft_atoi(str);
	if (*str == '*')
	{
		info->field_width_next = va_arg(ap, int);
		if (info->field_width_next < 0)
			info->n_pt_n = 0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}
