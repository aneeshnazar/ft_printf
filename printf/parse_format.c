/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:39:50 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 19:54:32 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		init_format(void)
{
	t_format	n;

	n.f_minus = 0;
	n.f_plus = 0;
	n.f_space = 0;
	n.f_zero = 0;
	n.f_hash = 0;
	n.width = -1;
	n.precision = -1;
	n.length = 0;
	n.type = 0;
	n.str = NULL;
	return (n);
}

t_format		parse_format(char *str)
{
	t_format	new_f;
	int			pos;

	new_f = init_format();
	pos = 1;
	new_f.str = ft_strdup(str);
	parse_flags(&new_f, str, &pos);
	parse_width(&new_f, str, &pos);
	parse_precision(&new_f, str, &pos);
	parse_length(&new_f, str, &pos);
	parse_type(&new_f, str, &pos);
	return (new_f);
}
