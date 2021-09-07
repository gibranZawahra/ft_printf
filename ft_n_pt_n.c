/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_pt_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:33:19 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 15:09:17 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	ft_pt_n(t_info *info, char *str, int i, int ln)
{

	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('x');
	}
	while (++i < info->field_width_next - ln)
		info->count += ft_putchar('0');
	while (*str)
		info->count += ft_putchar(*(str++));
}

void	ft_n_pt(t_info *info, char *str, int i, int ln)
{

	if (info->sign == 1)
		ln += 1;
	if (info->isp == 1)
		ln += 2;
	if (info->flag->minus != '-')
		while (++i < info->field_width - ln)
			info->count += ft_putchar(' ');
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('x');
	}
	if (info->sign == 1)
		info->count += ft_putchar('-');
	while (*str)
		info->count += ft_putchar(*(str++));
	if (info->flag->minus == '-')
		while (++i < info->field_width - ln)
			info->count += ft_putchar(' ');
}

void	ft_n_pt_n_flag_no_minus(t_info *info, char *str, int ln, int i)
{

	if (info->sign == 1)
		i++;
	if (info->field_width_next < ln)
		info->field_width_next = ln;
	if (info->isp == 1)
		i += 2;
	while (++i < ((info->field_width - ln) - (info->field_width_next - ln)))
		info->count += ft_putchar(' ');
	i = -1;
	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('x');
	}
	while (++i < (info->field_width_next - ln))
		info->count += ft_putchar('0');
	while (*str)
		info->count += ft_putchar(*(str++));
}

void	ft_n_pt_n_flag_minus(t_info *info, char *str, int ln, int i)
{

	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('x');
	}
	if (info->field_width_next < ln)
		info->field_width_next = ln;
	while (++i < (info->field_width_next - ln))
		info->count += ft_putchar('0');
	i = -1;
	if (info->sign == 1)
		i++;
	while (*str)
		info->count += ft_putchar(*(str++));
	while (++i < (info->field_width - info->field_width_next))
		info->count += ft_putchar(' ');
}

void	ft_print_pt(t_info *info, char *str)
{

	int	i;
	int	ln;

	while (*str)
	{
		if (*str == '*')
			str++;
		else
			break ;
	}
	ln = (int)ft_strlen(str);
	i = -1;
	if (info->pt_n == 1)
		ft_pt_n(info, str, i, ln);
	else if (info->n_pt == 1)
		ft_n_pt(info, str, i, ln);
	else if (info->n_pt_n == 1)
	{
		if (info->flag->minus != '-')
			ft_n_pt_n_flag_no_minus(info, str, ln, i);
		else
			ft_n_pt_n_flag_minus(info, str, ln, i);
	}
}
