/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:09:54 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 19:40:43 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_char(t_able *table, va_list a_list)
{
	if (table->format.type == '%')
		table->data.c = '%';
	else if (table->format.type == 'c' && !table->format.length)
		table->data.c = (char)va_arg(a_list, int);
/*	else
		table->data.lc = (wchar_t)va_arg(a_list, long);*/
}
