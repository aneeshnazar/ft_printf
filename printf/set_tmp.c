/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:09:27 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 19:32:57 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp(t_able *table)
{
	if (ft_is_in(table->format.type, "sS"))
		set_tmp_str(table);
	else if (ft_is_in(table->format.type, "dDi"))
		set_tmp_int(table);
	else if (ft_is_in(table->format.type, "puUoOxX"))
		set_tmp_uns(table);
	else if (ft_is_in(table->format.type, "cC%"))
		set_tmp_char(table);
}
