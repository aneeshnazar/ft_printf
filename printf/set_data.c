/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:36:55 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 13:16:30 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_data(t_able *table, va_list a_list)
{
	if (ft_is_in(table->format.type, "sS"))
		set_str(table, a_list);
	else if (ft_is_in(table->format.type, "dDi"))
		set_int(table, a_list);
	else if (table->format.type == 'p')
		set_addr(table, a_list);
	else if (ft_is_in(table->format.type, "uUoOxX"))
		set_uint(table, a_list);
	else if (ft_is_in(table->format.type, "cC%"))
		set_char(table, a_list);
	else
		set_char(table, a_list);
	set_tmp(table);
}
