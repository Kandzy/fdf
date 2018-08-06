/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:31:15 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 16:31:20 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_color(char *sx, int i)
{
	int		min;

	i++;
	if (sx[i] != '0')
		return (-1);
	if (sx[i + 1] != 'x')
		return (-1);
	i += 2;
	min = i;
	while ((sx[i] >= '0' && sx[i] <= '9') || (sx[i] >= 'A' && sx[i] <= 'F') ||
	(sx[i] >= 'a' && sx[i] <= 'f'))
	{
		i++;
		if ((i - min) > 6)
			return (-1);
		if (sx[i] == '\0')
			break ;
	}
	if (sx[i] != '\0' || (i - min) < 1)
		return (-1);
	return (0);
}

static int		count_x(char *sy, t_data *dat)
{
	char	**sx;
	int		i;

	sx = ft_strsplit(sy, ' ');
	dat->nx = 0;
	while (sx[dat->nx] != NULL)
	{
		i = 0;
		while (sx[dat->nx][i] != '\0')
		{
			if (sx[dat->nx][i] == ',')
			{
				if (check_color(sx[dat->nx], i) == -1)
					return (-1);
				break ;
			}
			if (sx[dat->nx][i] < '0' || sx[dat->nx][i] > '9')
				if((i == 0 && sx[dat->nx][i] != '-') || i != 0)
					return (-1);
			i++;
		}
		dat->nx++;
	}
	del_double_arr(&sx, dat->nx);
	return (0);
}

static int		ad_norm(char *sy)
{
	char	**sx;
	int		i;

	sx = ft_strsplit(sy, ' ');
	i = 0;
	while (sx[i] != NULL)
		i++;
	del_double_arr(&sx, i);
	return (i);
}

int				validate_map(char *map, t_data *dat)
{
	char	**sy;
	int		norm;

	sy = ft_strsplit(map, '*');
	dat->ny = 0;
	norm = ad_norm(sy[0]);
	while (sy[dat->ny] != NULL)
	{
		if (count_x(sy[dat->ny], dat) == -1)
			return (-1);
		if (norm != dat->nx)
			return (-1);
		dat->ny++;
	}
	dat->scale = WIDTH / (2 * dat->nx);
	del_double_arr(&sy, dat->ny);
	return (0);
}
