/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:59:42 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 19:41:02 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_tmp_char(t_able *table)
{
	if (ft_is_in(table->format.type, "c%"))
		table->tmp = ft_ctos(table->data.c);
/*	else
		table->wtmp = ft_wctos(table->data.lc);*/
}
