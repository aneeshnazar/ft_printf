/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:31:33 by anazar            #+#    #+#             */
/*   Updated: 2017/08/09 16:32:23 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_precision(t_format *t, char *format, int *start)
{
	int			tmp;

	tmp = *start;
	if (format[tmp] == '.')
	{
		++tmp;
		while (ft_isdigit(format[tmp]))
			++tmp;
		t->precision = ft_atoi(&format[*start + 1]);
		*start = tmp;
	}
}
