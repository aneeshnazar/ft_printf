/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_neg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:35:28 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 15:31:27 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_neg(t_able *table)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D')
		return (table->data.ld < 0);
	else if (!LENGTH)
		return (table->data.d < 0);
	else if (LENGTH == L_SHORT)
		return (table->data.hhd < 0);
	else if (LENGTH == L_SCHAR)
		return (table->data.hd < 0);
	else if (LENGTH == L_LLONG)
		return (table->data.lld < 0);
	else if (LENGTH == L_INTMAX)
		return (table->data.jd < 0);
	return (0);
}
