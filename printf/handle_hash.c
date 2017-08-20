/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:25:50 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 21:46:39 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(t_able *table)
{
	if (table->format.f_hash)
	{
		if (ft_is_in(table->format.type, "oO") && table->data.u != 0)
			table->tmp = ft_strjoinfree("0", table->tmp);
		else if ((table->format.type == 'x' && table->data.u != 0)
			|| (table->format.type == 'p'))
			table->tmp = ft_strjoinfree("0x", table->tmp);
		else if (table->format.type == 'X' && table->data.u != 0)
			table->tmp = ft_strjoinfree("0X", table->tmp);
	}
}
