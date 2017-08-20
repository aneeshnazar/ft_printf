/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:44:50 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 16:16:30 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_int(t_able *table, va_list a_list)
{
	if (LENGTH == 3 || LENGTH == 6 || TYPE == 'D')
		table->data.ld = va_arg(a_list, long);
	else if (!table->format.length)
		table->data.d = va_arg(a_list, int);
	else if (table->format.length == 1)
		table->data.hhd = va_arg(a_list, int);
	else if (table->format.length == 2)
		table->data.hd = va_arg(a_list, int);
	else if (table->format.length == 4)
		table->data.lld = va_arg(a_list, long long);
	else if (table->format.length == 5)
		table->data.jd = va_arg(a_list, intmax_t);
}
