/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:35 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 15:33:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	length_val(t_format *t, char *format, int *start)
{
	if (format[*start] == 'h')
	{
		if (format[*start + 1] == 'h')
			t->length = L_SHORT;
		else
			t->length = L_SCHAR;
	}
	else if (format[*start] == 'l')
	{
		if (format[*start + 1] == 'l')
			t->length = L_LLONG;
		else
			t->length = L_LONG;
	}
	else if (format[*start] == 'j')
		t->length = L_INTMAX;
	else
		t->length = L_SIZET;
}

int			parse_length(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC%"))
		return (0);
	else if (ft_is_in(format[*start], "hljz"))
	{
		length_val(t, format, start);
		if (t->length == L_SHORT || t->length == L_LLONG)
			*start += 2;
		else
			*start += 1;
		return (1);
	}
	else
	{
		t->is_good = 0;
		return (-1);
	}
}
