/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:54:13 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 13:54:26 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_good(t_able *table)
{
	if ((TYPE == 'S' || (TYPE == 's' && LENGTH == 4)) ||
		(TYPE == 'C' || (TYPE == 'c' && LENGTH == 4)))
		return (0);
	else if (ft_is_in(TYPE, "spdDioOuUxXc%"))
		return (1);
	else
		return (0);
}
