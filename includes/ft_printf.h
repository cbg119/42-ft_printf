/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:07:47 by cbagdon           #+#    #+#             */
/*   Updated: 2019/02/28 23:47:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define OCTAL_MAX 11

typedef struct      s_flags
{
    int             pound;
    int             minus;
    int             plus;
    int             space;
    int             zero;
}                   t_flags;

typedef struct      s_opts
{
    t_flags         flags;
    int             field_width;
    int				precision;
    int				length;
}                   t_opts;

void				add_flag(t_flags *flags, char c);

int					convert_s(t_opts options, va_list ap);
int					convert_i(t_opts options, va_list ap);
int					convert_c(t_opts options, va_list ap);
int					convert_p(t_opts options, va_list ap);
int					convert_o(t_opts options, va_list ap);
int					convert_u(t_opts options, va_list ap);
int					convert_x(t_opts options, va_list ap);
int					convert_X(t_opts options, va_list ap);
int					convert_percent(t_opts options);

int					is_flag(char c);
int					is_normal(char c);
int					ft_printf(char *str, ...);

t_opts				get_options(char **str, va_list ap);

char				*ft_intmove(char *str, int len, int64_t number);
char				*ft_pad(char *s, int pad, int length, int left_align);
int     ft_numlen(uint64_t num);
#endif
