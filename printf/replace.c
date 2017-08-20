/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 22:21:12 by anazar            #+#    #+#             */
/*   Updated: 2017/08/10 22:53:51 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*free_replace(char *str, char *tf, char *tr, int pos)
{
	char	*tmp;
	char	*buf;

	if (!(buf = ft_strnew(ft_strlen(str) - ft_strlen(tf) + ft_strlen(tr))))
		return (NULL);
	tmp = ft_strsub(str, 0, pos);
	ft_strcat(buf, tmp);
	ft_strcat(buf, tr);
	free(tmp);
	tmp = ft_strsub(str, pos + ft_strlen(tf), ft_strlen(str));
	ft_strcat(buf, tmp);
	free(tmp);
	ft_strdel(&str);
	str = buf;
	return (buf);
}

char		*replace(char *str, char *tf, char *tr)
{
	char	*buf;
	int		pos;

	if ((pos = ft_find(str, tf)) == -1)
	{
		buf = ft_strdup(str);
		ft_strdel(&str);
		str = buf;
		return (buf);
	}
	else
		return (free_replace(str, tf, tr, pos));
}
