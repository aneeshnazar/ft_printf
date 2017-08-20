/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:29:22 by anazar            #+#    #+#             */
/*   Updated: 2017/08/13 23:58:07 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_plus(t_able *table)
{
	if (table->format.f_plus)
		if (ft_is_in(table->format.type, "di"))
			if (table->data.d >= 0)
				return (1);
	return (0);
}