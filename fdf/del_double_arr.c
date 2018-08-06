/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_double_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 10:22:39 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/24 10:22:44 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_double_arr(char ***str, int size)
{
	int		i;

	i = 0;
	if (str && *str && **str)
	{
		while (i < size)
		{
			ft_strdel(&str[0][i]);
			i++;
		}
		free(*str);
		*str = NULL;
	}
}
