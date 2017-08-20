/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:14:33 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 21:58:14 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_output(t_able *table, int precision)
{
	if (check_minus(table))
	{
		if (!is_sign(table))
			ft_strfncpy(OUTPUT, table->tmp, precision);
		else
			ft_strfncpy(OUTPUT + 1, table->tmp, precision);
	}
	else
		ft_strrncpy(OUTPUT, table->tmp, precision);
}

void	handle_null(t_able *table)
{
	if (check_minus(table))
		OUTPUT[0] = 0;
	else
		OUTPUT[ft_strlen(OUTPUT) - 1] = 0;
}

void	append_sign(t_able *table)
{
	int	i;

	i = 0;
	while (OUTPUT[i] && (OUTPUT[i] == ' ' || OUTPUT[i] == '+'
		|| OUTPUT[i] == '-'))
		++i;
	if (is_sign(table))
	{
		if (i - 1 >= 0)
			OUTPUT[i - 1] = get_sign(table);
		else if (i == 0 && !ft_is_in(OUTPUT[i], "123456789"))
			OUTPUT[i] = get_sign(table);
	}
}

void	set_output(t_able *table)
{
	int	width;
	int	precision;

	handle_hash(table);
	get_width(table, &width, &precision);
	if (!(OUTPUT = ft_strnew(width)))
		return ;
	ft_memset(OUTPUT, ' ', width);
	if (!*table->tmp && TYPE == 'c')
		handle_null(table);
	else
		handle_output(table, precision);
	handle_zero(table);
	append_sign(table);
}
