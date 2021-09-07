/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:56:29 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void		ft_print_rest_part(t_info *info, char *str, int i)
{
	if (info->flag->minus != '-')
	{
		if (info->flag->zero == 'y')
			while (++i < info->field_width)
				info->count += ft_putchar('0');
		if (info->flag->zero != 'y')
			while (++i < info->field_width)
				info->count += ft_putchar(' ');
		if (*str == '%')
			info->count += ft_putchar('%') + 0 * atoi(str);
	}
	else
	{
		if (*str == '%')
			info->count += ft_putchar('%');
		if (info->flag->zero == 'y')
			while (++i < info->field_width)
				info->count += ft_putchar(' ');
		if (info->flag->zero != 'y')
			while (++i < info->field_width)
				info->count += ft_putchar(' ');
	}
}

char		*ft_print_rest(t_info *info, char *str)
{
	int	i;

	i = 0;
	if (info->field_width > -1)
		ft_print_rest_part(info, str, i);
	else
	{
		while (str[i])
		{
			if (str[i] == '%')
			{
				str += i;
				break ;
			}
			i++;
		}
		if (*str == '%')
			info->count += ft_putchar(*str);
	}
	return (str);
}

char		*ft_print_result(char *str, va_list ap, t_info *info)
{
	str = ft_get_info_for_flag(info, str);
	str = ft_get_field_width(info, str, ap);
	if (ft_str_all_chr(str, "diouxXDOUpb"))
		ft_print_nbr_for_conv(str, ap, info);
	else if (ft_str_all_chr(str, "cCsS"))
		ft_print_string_for_conv(str, ap, info);
	else
		str = ft_print_rest(info, str);
	return (str);
}
