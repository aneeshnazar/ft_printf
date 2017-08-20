/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:34:33 by anazar            #+#    #+#             */
/*   Updated: 2017/08/13 23:50:23 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_copy_until(char *str, int start)
{
	char	*out;
	int		i;

	i = 0;
	if (!(out = ft_strnew(100)))
		return (NULL);
	while (str[start])
	{
		out[i] = str[start];
		++start;
		if (ft_is_in(out[i], "sSpdDioOuUxXcC") || (out[i] == '%' && i >= 1))
			break ;
		++i;
	}
	return (out);
}

char	**get_f_strs(char *format, int *size)
{
	int		i;
	int		out_it;
	char	**out;

	i = 0;
	out_it = 0;
	*size = ft_countif(format, '%');
	out = (char **)ft_memalloc(sizeof(char *) * *size);
	while (format[i])
	{
		if (format[i] == '%')
		{
			out[out_it] = ft_copy_until(format, i);
			++out_it;
		}
		++i;
	}
	return (out);
}
