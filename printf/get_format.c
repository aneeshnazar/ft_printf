/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:44:56 by anazar            #+#    #+#             */
/*   Updated: 2017/08/14 00:02:19 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*get_format(char *format, int *num)
{
	t_format	*out;
	int			i;
	char		**format_strs;

	format_strs = get_f_strs(format, num);
	out = (t_format *)ft_memalloc(sizeof(t_format) * (*num + 1));
	i = 0;
	while (i < *num)
	{
		if (format_strs[i][0] == '%' && format_strs[i]
			[ft_strlen(format_strs[i]) - 1] == '%')
			--*num;
		out[i] = parse_format(format_strs[i]);
		ft_strdel(&format_strs[i]);
		++i;
	}
	free(format_strs);
	return (out);
}
