/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:35 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:33:27 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	length_val(t_format *t, char *format, int *start)
{
	if (format[*start] == 'h')
		t->length = (format[*start + 1] == 'h') ? L_SCHAR : L_SHORT;
	else if (format[*start] == 'l')
		t->length = (format[*start + 1] == 'l') ? L_LLONG : L_LONG;
	else
		t->length = (format[*start] == 'j') ? L_INTMAX : L_SIZET;
}

int			parse_length(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC%"))
		return (0);
	else if (ft_is_in(format[*start], "hljz"))
	{
		length_val(t, format, start);
		*start += (t->length == L_SCHAR || t->length == L_LLONG) ? 2 : 1;
		return (1);
	}
	else
	{
		t->is_good = 0;
		return (-1);
	}
}
