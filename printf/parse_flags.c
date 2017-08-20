/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:29:13 by anazar            #+#    #+#             */
/*   Updated: 2017/08/09 16:30:29 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_flags(t_format *t, char *format, int *start)
{
	while (ft_is_in(format[*start], "0-+ #"))
	{
		if (format[*start] == '0')
			t->f_zero += 1;
		if (format[*start] == '-')
			t->f_minus += 1;
		if (format[*start] == '+')
			t->f_plus += 1;
		if (format[*start] == ' ')
			t->f_space += 1;
		if (format[*start] == '#')
			t->f_hash += 1;
		++*start;
	}
	if (t->f_zero > 1 || t->f_minus > 1 ||
		t->f_plus > 1 || t->f_space > 1 || t->f_hash > 1)
	{
		t->is_good = 0;
		return (-1);
	}
	else
		return (1);
}
