/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:41:20 by anazar            #+#    #+#             */
/*   Updated: 2017/08/09 14:12:48 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_str(t_able *table, va_list a_list)
{
	if (table->format.type == 's' && !table->format.length)
		table->data.s = va_arg(a_list, char *);
	else
		table->data.ls = va_arg(a_list, wchar_t *);
}
