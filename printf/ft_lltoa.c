/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:08 by anazar            #+#    #+#             */
/*   Updated: 2017/08/19 18:53:31 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long n)
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

static void	help(char *buffer, long long num, int index)
{
	if (num >= 10 || num <= -10)
	{
		help(buffer, num / 10, index - 1);
		help(buffer, num % 10, index);
	}
	else
	{
		if (num >= 0)
			buffer[index] = (num + '0');
		else
			buffer[index] = (-num + '0');
	}
}

char		*ft_lltoa(long long n)
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
