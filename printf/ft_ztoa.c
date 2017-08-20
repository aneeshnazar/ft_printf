/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ztoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:08 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 20:27:24 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(size_t n)
{
	int		i;

	i = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static void	help(char *buffer, size_t num, int index)
{
	if (num >= 10)
	{
		help(buffer, num / 10, index - 1);
		help(buffer, num % 10, index);
	}
	else
	{
		buffer[index] = (num + '0');
	}
}

char		*ft_ztoa(size_t n)
{
	int		len;
	char	*buffer;

	len = ft_intlen(n);
	if (!(buffer = ft_strnew(len)))
		return (NULL);
	--len;
	help(buffer, n, len);
	return (buffer);
}
