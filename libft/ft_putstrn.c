/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:14:21 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 15:46:54 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrn(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		++i;
	}
}