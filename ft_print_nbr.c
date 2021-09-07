/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:26:42 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 17:45:43 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	print_nbr_fminus(char *str, t_info *info, int ln, int i)
{
	if (info->sign == 1)
		info->count += ft_putchar('-');
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('i');
		ln += 2;
	}
	if (info->iszero == 1)
		info->count += ft_putchar('0');
	while (*str)
	{
		if (*str != '*')
			info->count += ft_putchar(*str);
		str++;
	}
	while (i++ < info->field_width - ln)
		info->count += ft_putchar(' ');
}

void	print_nbr_nopfminus_n(char *str, t_info *info)
{
	if (info->isp == 1)
	{
		info->count += ft_putchar('0');
		info->count += ft_putchar('x');
	}
	if (info->iszero == 1)
		info->count += ft_putchar('0');
	while (*str)
	{
		if (*str != '*')
		info->count += ft_putchar(*str);
		str++;
	}
}

void	print_nbr_nopfminus(char *str, t_info *info, int ln, int i)
{
	if (info->isp == 1)
		ln += 2;
	if (info->flag->zero == 'y')
	{
		if (info->sign == 1)
			info->count += ft_putchar('-');
		while (i++ < info->field_width - ln)
			info->count += ft_putchar('0');
	}
	if (info->flag->zero != 'y')
		while (i++ < info->field_width - ln)
			info->count += ft_putchar(' ');
	if (info->sign == 1 && info->flag->zero != 'y')
		info->count += ft_putchar('-');
	print_nbr_nopfminus_n(str, info);
}

void	ft_print_nbr(t_info *info, char *str)
{
	int	ln;
	int	i;

	i = -1;
	ln = 0;
	if (info->sign == 1)
		ln++;
	if (info->iszero == 1)
		ln++;
	while (str[++i])
		if (str[i] != '*')
			ln++;
	i = 0;
	if (info->n_pt == 1 || info->pt_n == 1 || info->n_pt_n == 1)
	{
		ft_print_pt(info, str);
		return ;
	}
	if (info->flag->minus == '-')
		print_nbr_fminus(str, info, ln, i);
	else
		print_nbr_nopfminus(str, info, ln, i);
}
