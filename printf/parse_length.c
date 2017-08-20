/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:32:35 by anazar            #+#    #+#             */
/*   Updated: 2017/08/14 17:31:00 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		length_val(t_format *t, char *format, int *start)
{
	if (format[*start] == 'h')
	{
		if (format[*start + 1] == 'h')
			t->length = 1;
		else
			t->length = 2;
	}
	else if (format[*start] == 'l')
	{
		if (format[*start + 1] == 'l')
			t->length = 3;
		else
			t->length = 4;
	}
	else if (format[*start] == 'j')
		t->length = 5;
	else
		t->length = 6;
}

int				parse_length(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC%"))
		return (0);
	else if (ft_is_in(format[*start], "hljz"))
	{
		length_val(t, format, start);
		if (t->length == 1 || t->length == 3)
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
