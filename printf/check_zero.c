/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:47:39 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 23:47:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero(t_able *table)
{
	if (table->format.f_zero)
		if (ft_is_in(table->format.type, "dDiuUxXoO"))
			if (table->format.width != -1)
				return (1);
	return (0);
}
