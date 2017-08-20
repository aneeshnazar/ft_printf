/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:30:45 by anazar            #+#    #+#             */
/*   Updated: 2017/08/09 16:31:22 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_width(t_format *t, char *format, int *start)
{
	int			tmp;

	tmp = *start;
	if (ft_isdigit(format[tmp]))
	{
		while (ft_isdigit(format[tmp]))
			++tmp;
		t->width = ft_atoi(&format[*start]);
		*start = tmp;
	}
}
