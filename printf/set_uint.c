/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:03:19 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 13:29:49 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_uint(t_able *table, va_list a_list)
{
	if (ft_is_in(table->format.type, "UO") || table->format.length == 4)
		table->data.lu = va_arg(a_list, unsigned long int);
	else if (!table->format.length)
		table->data.u = va_arg(a_list, unsigned int);
	else if (table->format.length == 1)
		table->data.hhu = va_arg(a_list, unsigned int);
	else if (table->format.length == 2)
		table->data.hu = va_arg(a_list, unsigned int);
	else if (table->format.length == 3)
		table->data.llu = va_arg(a_list, unsigned long long int);
	else if (table->format.length == 5)
		table->data.ju = va_arg(a_list, uintmax_t);
	else if (table->format.length == 6)
		table->data.z = va_arg(a_list, size_t);
}
