/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 19:00:01 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 16:13:13 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_precision(t_able *table)
{
	char	*str;

	if (table->format.precision > (int)ft_strlen(table->tmp))
	{
		str = zero_str(table->format.precision - ft_strlen(table->tmp));
		table->tmp = ft_strjoinfree(str, table->tmp);
		return (table->format.precision);
	}
	else if (TINT == 0 && !(ft_is_in(TYPE, "oO") && F_HASH))
		return (0);
	else
		return (ft_strlen(table->tmp));
}

static int	get_precision(t_able *table)
{
	if (table->format.precision != -1)
	{
		if (ft_is_in(table->format.type, "dDioOuUxX"))
			return (get_num_precision(table));
		else if (ft_is_in(TYPE, "c%"))
			return (1);
		else
		{
			if (table->format.precision < (int)ft_strlen(table->tmp))
				return (table->format.precision);
			else
				return (ft_strlen(table->tmp));
		}
	}
	else
		return (ft_strlen(table->tmp));
}

void		get_width(t_able *table, int *width, int *precision)
{
	if (table->format.width != -1)
		*width = ft_max(table->format.width, ft_strlen(table->tmp));
	else
		*width = get_precision(table) + is_sign(table);
	*precision = get_precision(table);
	if (*width < *precision)
		*width = *precision;
}
