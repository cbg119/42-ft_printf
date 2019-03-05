/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:30:19 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 01:07:36 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const t_dispatch	g_table[] =
{
	{'s', &convert_s},
	{'c', &convert_c},
	{'p', &convert_p},
	{'o', &convert_o},
	{'u', &convert_u},
	{'x', &convert_x},
	{'X', &convert_xl},
	{'f', &convert_f}
};
