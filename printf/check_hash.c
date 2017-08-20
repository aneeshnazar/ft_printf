/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:48:15 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 23:48:27 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_hash(t_able *table)
{
	if (table->format.f_hash)
	{
		if (ft_is_in(table->format.type, "oO"))
			return (1);
		else if (table->format.type == 'x')
			return (2);
		else if (table->format.type == 'X')
			return (3);
	}
	return (0);
}
