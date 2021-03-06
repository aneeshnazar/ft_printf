/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:03:19 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 22:57:31 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_uint(t_able *table, va_list a_list)
{
	if (ft_is_in(table->format.type, "UO") || table->format.length == L_LONG)
		table->data.lu = va_arg(a_list, unsigned long int);
	else if (!table->format.length ||
			table->format.length == L_SCHAR ||
			table->format.length == L_SHORT)
		table->data.u = va_arg(a_list, unsigned int);
	else if (table->format.length == L_LLONG)
		table->data.llu = va_arg(a_list, unsigned long long int);
	else if (table->format.length == L_INTMAX)
		table->data.ju = va_arg(a_list, uintmax_t);
	else if (table->format.length == L_SIZET)
		table->data.z = va_arg(a_list, size_t);
}
