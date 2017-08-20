/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 19:40:38 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 14:14:13 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(t_format format)
{
	ft_putstr("Flags:\t\t");
	ft_putnbr(format.f_minus);
	ft_putnbr(format.f_plus);
	ft_putnbr(format.f_space);
	ft_putnbr(format.f_zero);
	ft_putnbr(format.f_hash);
	ft_putstr("\nWidth:\t\t");
	ft_putnbr(format.width);
	ft_putstr("\nPrecision:\t");
	ft_putnbr(format.precision);
	ft_putstr("\nLength:\t\t");
	ft_putnbr(format.length);
	ft_putstr("\nString:\t\t");
	ft_putstr(format.str);
	ft_putstr("\nType:\t\t");
	ft_putchar(format.type);
	ft_putstr("\nGood:\t\t");
	ft_putnbr(format.is_good);
	ft_putstr("\n\n");
}

t_able	*generate_table(char *format, va_list a_list, int *num)
{
	t_format	*formats;
	t_able		*out;
	int			i;

	i = 0;
	formats = get_format(format, num);
	out = (t_able *)ft_memalloc(sizeof(t_able) * (*num + 1));
	while (i < *num)
	{
		out[i].format = formats[i];
		set_data(&out[i], a_list);
		if (is_good(&out[i]))
			set_output(&out[i]);
		++i;
	}
	return (out);
}
