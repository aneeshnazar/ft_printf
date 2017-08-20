/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:40:00 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 16:16:35 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_int(t_able *table)
{
	if (LENGTH == 3 || LENGTH == 6 || TYPE == 'D')
		table->tmp = ft_ltoa(table->data.ld);
	else if (!table->format.length)
		table->tmp = ft_itoa(table->data.d);
	else if (table->format.length == 1)
		table->tmp = ft_hhtoa(table->data.hhd);
	else if (table->format.length == 2)
		table->tmp = ft_htoa(table->data.hd);
	else if (table->format.length == 4)
		table->tmp = ft_lltoa(table->data.lld);
	else if (table->format.length == 5)
		table->tmp = ft_jtoa(table->data.jd);
}
