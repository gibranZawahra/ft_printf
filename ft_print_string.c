/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 13:57:29 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	ft_print_string_no_m(t_info *info, char *str, int ln)
{
	if (info->char_z == 1)
		info->field_width--;
	if (info->flag->zero == 'y')
		while (ln++ < info->field_width)
			info->count += ft_putchar('0');
	if (info->flag->zero != 'y')
		while (ln++ < info->field_width)
			info->count += ft_putchar(' ');
	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->iszero == 1)
		info->count += ft_putchar('0');
	if (info->char_z == 1)
		info->count += ft_putchar(str[0]);
	while (*str)
		info->count += ft_putchar(*(str++));
}

void	ft_print_string_m(t_info *info, char *str, int ln)
{
	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->iszero == 1)
		info->count += ft_putchar('0');
	if (info->char_z == 1)
		info->count += ft_putchar('\0');
	while (*str)
		info->count += ft_putchar(*(str++));
	if (info->char_z == 1)
		info->field_width--;
	while (ln++ < info->field_width)
		info->count += ft_putchar(' ');
}

void	ft_print_string(t_info *info, char *str)
{
	int ln;

	ln = ft_strlen(str);
	if (info->n_pt == 1 || info->pt_n == 1 || info->n_pt_n == 1)
	{
		ft_print_pt_string(info, str);
		return ;
	}
	if (info->flag->minus == '-')
		ft_print_string_m(info, str, ln);
	else
		ft_print_string_no_m(info, str, ln);
}
