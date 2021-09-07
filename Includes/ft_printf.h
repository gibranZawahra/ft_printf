/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:18 by gizawahr          #+#    #+#             */
/*   Updated: 2021/04/21 15:23:22 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flag_info
{
	char		minus;
	char		zero;
	char 		hash;
}				t_flag_info;

typedef struct	s_info
{
	int				field_width;
	int				field_width_next;
	int				precision;
	char			conversion_specifier;
	int				count;
	int				iszero;
	int				is_nopre;
	int				pt_n;
	int				n_pt;
	int				n_pt_n;
	int				isp;
	int				sign;
	char			star;
	int				char_z;
	int				is_char;
	char			*base_a;
	char			*base_b;
	t_flag_info		*flag;
}				t_info;

int				ft_printf(const char *strin, ...);
char			*ft_print_result(char *str, va_list ap, t_info *info);
void			ft_print_nbr_for_conv(char *str, va_list ap, t_info *info);
char			*ft_get_info_for_flag(t_info *info, char *str);
char			*ft_get_field_width(t_info *info, char *str, va_list ap);
void			ft_print_string_for_conv(char *str, va_list ap, t_info *info);
void			ft_print_nbr(t_info *info, char *str);
void			ft_print_string(t_info *info, char *str);
void			ft_print_pt(t_info *info, char *str);
void			ft_print_pt_string(t_info *info, char *str);

#endif
