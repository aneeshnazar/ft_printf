/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:33:34 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:04:13 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_str(t_able *table)
{
	if (table->format.type == 's' && !table->format.length)
		table->tmp = (!table->data.s) ? ft_strdup("(null)") :
			ft_strdup(table->data.s);
	else
		table->wtmp = table->data.ls;
}
