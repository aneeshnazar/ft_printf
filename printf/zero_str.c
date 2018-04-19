/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 15:19:58 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 19:20:06 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*zero_str(int num)
{
	char	*str;

	if (!(str = (char *)malloc(num + 1)))
		return (NULL);
	ft_memset(str, '0', num);
	str[num] = 0;
	return (str);
}
