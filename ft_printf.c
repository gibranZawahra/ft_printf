/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/22 14:46:10 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

char	*ft_print_all(char *str, t_info *info)
{
	while (((*str && *str != '%')) || (*(str + 1) == '%' && *str == '%'))
	{
		while (*str && *str != '%')
			info->count += ft_putchar(*(str++));
		while (*(str + 1) && *(str + 1) == '%' && *str == '%')
		{
			info->count += ft_putchar(*str);
			str += 2;
		}
	}
	if (*str == '%')
		str++;
	if ((*str == ' ' && (*(str + 1) == '*')) ||
		(*str == ' ' && (*(str + 1) == 'd')) ||
		(*str == ' ' && (*(str + 1) == 'X')) ||
		(*str == ' ' && (*(str + 1) == 'c')) ||
		(*str == ' ' && (*(str + 1) == 'x')) ||
		(*str == ' ' && (*(str + 1) == 'i')) ||
		(*str == ' ' && (*(str + 1) == 'p')))
		info->count += ft_putchar(*(str++));
	return (str);
}

int		ft_printf(const char *strin, ...)
{
	va_list		ap;
	char		*str;
	t_info		info;

	info.iszero = 0;
	if (!(info.flag = (t_flag_info*)malloc(sizeof(t_flag_info) * 1)))
		return (-1);
	info.count = 0;
	if (!strin)
		return (-1);
	va_start(ap, strin);
	str = (char *)strin;
	while (*str)
	{
		str = ft_print_all(str, &info);
		if (*str)
			str = ft_print_result(str, ap, &info);
		if (!*str++)
			break ;
	}
	free(info.flag);
	va_end(ap);
	return (info.count);
}

