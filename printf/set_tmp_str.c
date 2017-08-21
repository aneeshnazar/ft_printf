/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:33:34 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 16:24:25 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_str(t_able *table)
{
	if (table->format.type == 's' && !table->format.length)
	{
		if (!table->data.s)
			table->tmp = ft_strdup("(null)");
		else
			table->tmp = ft_strdup(table->data.s);
	}
	else
		table->wtmp = table->data.ls;
}
