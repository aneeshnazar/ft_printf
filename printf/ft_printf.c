/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 12:42:15 by anazar            #+#    #+#             */
/*   Updated: 2017/08/20 14:26:02 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_null(t_able *table)
{
	return (TYPE == 'c' && !table->data.c);
}

void	ft_put(t_able *table, int *t, int *i, int *num_chars)
{
	if (is_good(table))
	{
		ft_putstr(table->output);
		*i += ft_strlen(table->format.str);
		*num_chars += ft_strlen(table->output);
		++*t;
		free(table->format.str);
		free(table->output);
	}
	else
	{
		*i += ft_strlen(table->format.str);
		++*t;
		free(table->format.str);
	}
}

void	ft_put_null(t_able *table, int *t, int *i, int *num_chars)
{
	ft_putstr(table->output);
	ft_putchar(0);
	*i += ft_strlen(table->format.str);
	*num_chars += ft_strlen(table->output) + 1;
	free(table->format.str);
	free(table->output);
	++*t;
}

int		print(char *format, t_able *table, int num)
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
			ft_putchar(format[i++]);
			++num_chars;
		}
		else if (t < num)
		{
			if (is_null(&table[t]))
				ft_put_null(&table[t], &t, &i, &num_chars);
			else
				ft_put(&table[t], &t, &i, &num_chars);
		}
		else
			++i;
	}
	return (num_chars);
}

int		ft_printf(const char *format, ...)
{
	va_list	a_list;
	char	*out;
	t_able	*table;
	int		num;
	int		n_chars;

	out = ft_strdup(format);
	va_start(a_list, format);
	table = generate_table(out, a_list, &num);
	n_chars = print(out, table, num);
	free(table);
	ft_strdel(&out);
	return (n_chars);
}
