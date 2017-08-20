/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:44:00 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 18:58:18 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zero(t_able *table)
{
	int	i;

	if (WIDTH != -1 && PRECISION != -1)
		i = table->format.width - table->format.precision;
	else
		i = 0;
	if (ft_is_in(table->format.type, "dDioOuUxX") && table->format.f_zero)
	{
		while (table->output[i])
		{
			if (table->output[i] == ' ')
				table->output[i] = '0';
			else
				break ;
			++i;
		}
		fix_sign(table);
	}
}
