/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:25:50 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 20:39:04 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(t_able *table)
{
	if (table->format.f_hash && table->data.u != 0)
	{
		if (ft_is_in(table->format.type, "oO"))
			table->tmp = ft_strjoinfree("0", table->tmp);
		else if (table->format.type == 'x' || table->format.type == 'p')
			table->tmp = ft_strjoinfree("0x", table->tmp);
		else if (table->format.type == 'X')
			table->tmp = ft_strjoinfree("0X", table->tmp);
	}
}
