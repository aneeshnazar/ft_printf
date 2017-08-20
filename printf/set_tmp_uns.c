/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:47:06 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 20:25:04 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_uns(t_able *table)
{
	if (ft_is_in(table->format.type, "pUO") || table->format.length == 3)
		table->tmp = ft_lutoa(table->data.lu, table->format.type);
	else if (!table->format.length)
		table->tmp = ft_utoa(table->data.u, table->format.type);
	else if (table->format.length == 1)
		table->tmp = ft_hhutoa(table->data.hhu, table->format.type);
	else if (table->format.length == 2)
		table->tmp = ft_hutoa(table->data.hu, table->format.type);
	else if (table->format.length == 4)
		table->tmp = ft_llutoa(table->data.llu, table->format.type);
	else if (table->format.length == 5)
		table->tmp = ft_jutoa(table->data.ju, table->format.type);
	else if (table->format.length == 6)
		table->tmp = ft_zutoa(table->data.z, table->format.type);
}
