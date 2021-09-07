/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pt_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:55:14 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	ft_print_pt_string_pt_n(t_info *info, char *str)
{
	while (*str && info->field_width_next > 0)
	{
		info->count += ft_putchar(*(str++));
		info->field_width_next--;
	}
	if (info->is_char == 1 && info->field_width_next == -1)
		info->count += ft_putchar(*(str++));
}

void	ft_print_pt_string_n_pt(t_info *info, char *str, int i, int ln)
{
	if (info->is_char == 1)
	{
		while (++i < info->field_width - ln)
			info->count += ft_putchar(' ');
		info->count += ft_putchar(str[0]);
	}
	while (++i < info->field_width)
		info->count += ft_putchar(' ');
}

void	ft_print_pt_string_n_pt_n_m(t_info *info, char *str, int count)
{
	while (*str && info->field_width_next > 0)
	{
		info->count += ft_putchar(*(str++));
		info->field_width_next--;
		count++;
	}
	while (count < info->field_width)
	{
		info->count += ft_putchar(' ');
		info->field_width--;
	}
}

void	ft_print_pt_string_n_pt_n(t_info *info, char *str, int count, int ln)
{
	count = info->field_width_next;
	if (info->field_width_next > ln)
		count = ln;
	while (info->field_width - count > 0)
	{
		info->count += ft_putchar(' ');
		count++;
	}
	count = info->field_width_next;
	if (info->field_width_next > ln)
		count = ln;
	if (info->char_z == 1)
		info->count += ft_putchar(str[0]);
	else
	{
		while (*str && count > 0)
		{
			info->count += ft_putchar(*(str++));
			count--;
		}
	}
}

void	ft_print_pt_string(t_info *info, char *str)
{
	int	i;
	int	ln;
	int	count;

	ln = (int)ft_strlen(str);
	count = 0;
	i = -1;
	if (info->pt_n == 1)
		ft_print_pt_string_pt_n(info, str);
	else if (info->n_pt == 1)
		ft_print_pt_string_n_pt(info, str, i, ln);
	else if (info->n_pt_n == 1)
	{
		if (info->flag->minus == '-')
			ft_print_pt_string_n_pt_n_m(info, str, count);
		else
			ft_print_pt_string_n_pt_n(info, str, count, ln);
	}
}
