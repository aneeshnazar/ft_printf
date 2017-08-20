/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 19:40:38 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 20:11:29 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_able	*generate_table(char *format, va_list a_list, int *num)
{
	t_format	*formats;
	t_able		*out;
	int			i;

	i = 0;
	formats = get_format(format, num);
	out = (t_able *)ft_memalloc(sizeof(t_able) * (*num + 1));
	while (i < *num)
	{
		out[i].format = formats[i];
		set_data(&out[i], a_list);
		if (!((out[i].format.type == 'S' ||
			(out[i].format.type == 's' && out[i].format.length == 3)) ||
			(out[i].format.type == 'C' ||
			(out[i].format.type == 'c' && out[i].format.length == 3))))
			set_output(&out[i]);
		++i;
	}
	return (out);
}
