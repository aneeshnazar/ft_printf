/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:40:00 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:05:12 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MOD_U 0x100000000
#define MOD_SC 0x100
#define MOD_SH 0x10000

void	set_tmp_int(t_able *table)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D' ||
		table->format.length == L_LLONG ||
		table->format.length == L_INTMAX)
		table->tmp = ft_jtoa(table->data.ld);
	else if (!table->format.length)
		table->tmp = ft_jtoa(table->data.d % MOD_U);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_jtoa(table->data.hd % MOD_SH);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_jtoa(table->data.hhd % MOD_SC);
}
