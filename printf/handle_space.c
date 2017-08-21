/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:28:40 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 16:14:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_space(t_able *table)
{
	if (check_space(table) && OUTPUT[0] != ' ')
		OUTPUT = ft_strjoinfree(ft_strdup(" "), OUTPUT);
}
