/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:47:06 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 22:23:43 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MOD_U 0x100000000
#define MOD_SC 0x100
#define MOD_SH 0x10000

void	set_tmp_uns(t_able *table)
{
	if (ft_is_in(table->format.type, "UO") ||
		table->format.length == L_LONG ||
		table->format.length == L_LLONG ||
		table->format.length == L_INTMAX ||
		table->format.length == L_SIZET)
		table->tmp = ft_jutoa(table->data.lu, table->format.type);
	else if (table->format.type == 'p')
	{
		table->tmp = ft_jutoa(table->data.lu, 'x');
		table->format.f_hash = 1;
	}
	else if (!table->format.length)
		table->tmp = ft_jutoa(table->data.u % MOD_U, table->format.type);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_jutoa(table->data.hu % MOD_SH, table->format.type);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_jutoa(table->data.hhu % MOD_SC, table->format.type);
	//else if (table->format.length == L_LLONG || table->format.length == L_INTMAX || table->format.length == L_SIZET)
	//	table->tmp = ft_jutoa(table->data.llu, table->format.type);
	//else if (table->format.length == L_INTMAX)
	//	table->tmp = ft_jutoa(table->data.ju, table->format.type);
	//else if (table->format.length == L_SIZET)
	//	table->tmp = ft_jutoa(table->data.z, table->format.type);
}
