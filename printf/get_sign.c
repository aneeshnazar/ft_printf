/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 23:03:27 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 14:36:03 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(t_able *table)
{
	if (ft_is_in(table->format.type, "dDi"))
	{
		if (is_neg(table))
			return ('-');
		else
		{
			if (check_plus(table))
				return ('+');
			else if (check_space(table))
				return (' ');
		}
	}
	return (0);
}
