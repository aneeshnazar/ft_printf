/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:54:13 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:11:36 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_good(t_able *table)
{
	if ((TYPE == 'S' || (TYPE == 's' && LENGTH == L_LONG)) ||
		(TYPE == 'C' || (TYPE == 'c' && LENGTH == L_LONG)))
		return (0);
	else
		return (ft_is_in(TYPE, "spdDioOuUxXc%")) ? 1 : 0;
	//else if (ft_is_in(TYPE, "spdDioOuUxXc%"))
	//	return (1);
	//else
	//	return (0);
}
