/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:31:35 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 16:31:37 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_init_cond(t_data *dat)
{
	dat->center[0] = WIDTH / 2;
	dat->center[1] = HEIGHT / 2;
	dat->phi = 3.14 + 0.9;
	dat->psi = 3.14;
	dat->gam = 3.14 + 0.8;
	dat->scale = (WIDTH / 2) / (dat->nx);
}

static void	set_pnt(t_point *vec, char *pntx, short x, short y)
{
	int		pos;
	int		len;
	char	*color;

	pos = 0;
	len = ft_strlen(pntx);
	vec->px = x;
	vec->py = y;
	vec->pz = ft_atoi(pntx);
	while (pntx[pos] != 'x' && pos < len)
		pos++;
	color = ft_strsub(pntx, pos + 1, ft_strlen(pntx));
	vec->color = ft_atoi_base(color, 16);
	ft_strdel(&color);
}

static void	set_points(t_data dat, t_point *vec, char *map)
{
	short	x;
	short	y;
	int		i;
	char	**pntx;
	char	**pnty;

	y = 0;
	i = 0;
	pnty = ft_strsplit(map, '*');
	while (pnty[y] != NULL)
	{
		x = 0;
		pntx = ft_strsplit(pnty[y], ' ');
		while (pntx[x] != NULL)
		{
			set_pnt(&vec[i], pntx[x], x - dat.nx / 2, y - dat.ny / 2);
			x++;
			i++;
		}
		del_double_arr(&pntx, x);
		y++;
	}
	del_double_arr(&pnty, y);
}

void		set_coordinates(t_data dat, char *map)
{
	t_point vec[dat.nx * dat.ny];

	set_init_cond(&dat);
	set_points(dat, vec, map);
	ft_strdel(&map);
	win_controller(dat, vec);
}
