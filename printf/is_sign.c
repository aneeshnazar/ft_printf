/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 22:33:10 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 22:38:46 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_sign(t_able *table)
{
	if (ft_is_in(table->format.type, "dDi"))
	{
		if (is_neg(table))
			return (1);
		else if (check_plus(table))
			return (1);
	}
	return (0);
}
