/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:44:50 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 22:36:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_int(t_able *table, va_list a_list)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D')
		table->data.ld = va_arg(a_list, long);
	else if (!table->format.length ||
			table->format.length == L_SCHAR ||
			table->format.length == L_SHORT)
		table->data.d = va_arg(a_list, int);
	//else if (table->format.length == L_SCHAR)
	//	table->data.hhd = va_arg(a_list, int);
	//else if (table->format.length == L_SHORT)
	//	table->data.hd = va_arg(a_list, int);
	else if (table->format.length == L_LLONG)
		table->data.lld = va_arg(a_list, long long);
	else if (table->format.length == L_INTMAX)
		table->data.jd = va_arg(a_list, intmax_t);
}
