/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:47:06 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 15:28:53 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_uns(t_able *table)
{
	if (ft_is_in(table->format.type, "UO") || table->format.length == L_LONG)
		table->tmp = ft_lutoa(table->data.lu, table->format.type);
	else if (table->format.type == 'p')
	{
		table->tmp = ft_lutoa(table->data.lu, 'x');
		table->format.f_hash = 1;
	}
	else if (!table->format.length)
		table->tmp = ft_utoa(table->data.u, table->format.type);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_hhutoa(table->data.hhu, table->format.type);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_hutoa(table->data.hu, table->format.type);
	else if (table->format.length == L_LLONG)
		table->tmp = ft_llutoa(table->data.llu, table->format.type);
	else if (table->format.length == L_INTMAX)
		table->tmp = ft_jutoa(table->data.ju, table->format.type);
	else if (table->format.length == L_SIZET)
		table->tmp = ft_zutoa(table->data.z, table->format.type);
}
