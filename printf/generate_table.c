/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 19:40:38 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 21:38:36 by anazar           ###   ########.fr       */
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
	ft_putchar('\n');
	ft_putstr("Width:\t\t");
	ft_putnbr(format.width);
	ft_putchar('\n');
	ft_putstr("Precision:\t");
	ft_putnbr(format.precision);
	ft_putchar('\n');
	ft_putstr("Length:\t\t");
	ft_putnbr(format.length);
	ft_putchar('\n');
	ft_putstr("String:\t\t");
	ft_putstr(format.str);
	ft_putchar('\n');
	ft_putstr("Type:\t\t");
	ft_putchar(format.type);
	ft_putchar('\n');
	ft_putstr("Good:\t\t");
	ft_putnbr(format.is_good);
	ft_putchar('\n');
	ft_putchar('\n');
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
	//	print_format(out[i].format);
		set_data(&out[i], a_list);
		if ((out[i].format.type == 'S' || (out[i].format.type == 's' &&
			(out[i].format.length == 3 || out[i].format.length == 4))) ||
			(out[i].format.type == 'C' || (out[i].format.type == 'c' &&
			(out[i].format.length == 3 || out[i].format.length == 4))))
			;
		else
			set_output(&out[i]);
		++i;
	}
	return (out);
}
