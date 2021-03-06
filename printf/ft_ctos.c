/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:29:04 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 14:23:43 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctos(char c)
{
	char	*out;

	if (!(out = ft_strnew(1)))
		return (NULL);
	out[0] = c;
	return (out);
}
