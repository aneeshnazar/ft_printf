/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:40:00 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 15:28:08 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_int(t_able *table)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D')
		table->tmp = ft_ltoa(table->data.ld);
	else if (!table->format.length)
		table->tmp = ft_itoa(table->data.d);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_hhtoa(table->data.hhd);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_htoa(table->data.hd);
	else if (table->format.length == L_LLONG)
		table->tmp = ft_lltoa(table->data.lld);
	else if (table->format.length == L_INTMAX)
		table->tmp = ft_jtoa(table->data.jd);
}
