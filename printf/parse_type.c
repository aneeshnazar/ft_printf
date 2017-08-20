/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:33:13 by anazar            #+#    #+#             */
/*   Updated: 2017/08/09 16:33:32 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_type(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC") ||
		(format[*start] == '%' && *start >= 1))
	{
		t->type = format[*start];
		++*start;
		return (1);
	}
	else
	{
		t->is_good = 0;
		return (-1);
	}
}
