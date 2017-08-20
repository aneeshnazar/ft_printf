/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:43:08 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 23:46:40 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_space(t_able *table)
{
	if (table->format.f_space && !table->format.f_plus)
		if (ft_is_in(table->format.type, "di"))
			if (table->data.d > 0)
				return (1);
	return (0);
}
