/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:42:15 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 21:41:23 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_null(t_able *table)
{
	return (TYPE == 'c' && !table->data.c);
}

void	ft_put(t_able *table, int *t, int *i, int *num_chars)
{
	if ((TYPE == 'S' || (TYPE == 's' && (LENGTH == 3 || LENGTH == 4))) ||
			(TYPE == 'C' || (TYPE == 'c' && (LENGTH == 3 || LENGTH == 4))))
	{
		*i += ft_strlen(table->format.str);
		++*t;
	}
	else
	{
		ft_putstr(table->output);
		*i += ft_strlen(table->format.str);
		*num_chars += ft_strlen(table->output);
		++*t;
	}
}

void	ft_put_null(t_able *table, int *t, int *i, int *num_chars)
{
	ft_putstr(table[*t].output);
	ft_putchar(0);
	*i += ft_strlen(table[*t].format.str);
	*num_chars += ft_strlen(table[*t].output) + 1;
	++*t;
}

int		print(char *format, t_able *table)
{
	int	num_chars;
	int	i;
	int	t;

	i = 0;
	t = 0;
	num_chars = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			++i;
			++num_chars;
		}
		else if (is_null(&table[t]))
			ft_put_null(&table[t], &t, &i, &num_chars);
		else
			ft_put(&table[t], &t, &i, &num_chars);
	}
	return (num_chars);
}


int		ft_printf(const char *format, ...)
{
	va_list	a_list;
	char	*out;
	t_able	*table;
	int		num;

	out = ft_strdup(format);
	va_start(a_list, format);
	table = generate_table(out, a_list, &num);
	return (print(out, table));
}
/*
int		ft_printf(const char *format, ...)
{
	va_list	a_list;
	char	*out;
	t_able	*table;
	int		num;
	int		i;

	out = ft_strdup(format);
	va_start(a_list, format);
	table = generate_table(out, a_list, &num);
	i = 0;
	while (i < num)
	{
		out = replace(out, table[i].format.str, table[i].output);
		++i;
	}
	num = ft_strlen(out);
	ft_putstrn(out, num);
	return (num);
}*/
