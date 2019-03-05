/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:37:18 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 01:06:06 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define OCTAL_MAX 11
# define CONVERSION_NUMBER 9

typedef struct				s_flags
{
	int						pound;
	int						minus;
	int						plus;
	int						space;
	int						zero;
}							t_flags;

typedef struct				s_opts
{
	t_flags					flags;
	int						field_width;
	int						precision;
	int						length;
}							t_opts;

typedef int					(*t_conv)(t_opts, va_list);

typedef struct				s_dispatch
{
	const char				key;
	const t_conv			convert;
}							t_dispatch;

extern const t_dispatch		g_table[];

void						ft_imsorry(char to_print, int *len, int spaces);
void						add_flag(t_flags *flags, char c);

unsigned long long			fetch_number(int length, va_list ap);

int							convert_s(t_opts options, va_list ap);
int							convert_i(t_opts options, va_list ap,
		int count, int negative);
int							convert_c(t_opts options, va_list ap);
int							convert_p(t_opts options, va_list ap);
int							convert_o(t_opts options, va_list ap);
int							convert_u(t_opts options, va_list ap);
int							convert_x(t_opts options, va_list ap);
int							convert_xl(t_opts options, va_list ap);
int							convert_f(t_opts options, va_list ap);
int							convert_percent(t_opts options);

int							is_flag(char c);
int							is_normal(char c);
int							ft_printf(char *str, ...);

t_opts						get_options(char **str, va_list ap);

void						ft_intmove(char *str, int len,
		unsigned long long number, int negative);
char						*ft_pad(char *s, int pad, int length,
		int left_align);
void						pf_putfloat(long double number, t_opts options);
int							ft_numlen(unsigned long long number);
#endif
