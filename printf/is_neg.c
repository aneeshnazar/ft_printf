/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_neg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:35:28 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 14:35:43 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_neg(t_able *table)
{
	if (LENGTH == 3 || LENGTH == 6 || TYPE == 'D')
		return (table->data.ld < 0);
	else if (!LENGTH)
		return (table->data.d < 0);
	else if (LENGTH == 1)
		return (table->data.hhd < 0);
	else if (LENGTH == 2)
		return (table->data.hd < 0);
	else if (LENGTH == 4)
		return (table->data.lld < 0);
	else if (LENGTH == 5)
		return (table->data.jd < 0);
	return (0);
}
