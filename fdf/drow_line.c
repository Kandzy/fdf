/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:15:03 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/07 18:15:05 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_hori(t_win w_cr, t_data dat, t_point vec1, t_point vec2)
{
	int		x;
	double	y;

	x = vec1.npx;
	if (vec1.npx < vec2.npx)
	{
		while (x <= vec2.npx)
		{
			y = dat.k * x + dat.b;
			y = ((y - (int)y) > 0.5) ? y + 1 : y;
			mlx_pixel_put(w_cr.mlx, w_cr.win, x, y, vec1.color);
			x++;
		}
	}
	else
	{
		while (x >= vec2.npx)
		{
			y = dat.k * x + dat.b;
			y = ((y - (int)y) > 0.5) ? y + 1 : y;
			mlx_pixel_put(w_cr.mlx, w_cr.win, x, y, vec1.color);
			x--;
		}
	}
}

static void	print_vert(t_win w_cr, t_data dat, t_point vec1, t_point vec2)
{
	int		y;
	double	x;

	y = vec1.npy;
	if (vec1.npy < vec2.npy)
	{
		while (y <= vec2.npy)
		{
			x = (y - dat.b) / dat.k;
			x = ((x - (int)x) > 0.5) ? x + 1 : x;
			mlx_pixel_put(w_cr.mlx, w_cr.win, x, y, vec1.color);
			y++;
		}
	}
	else
	{
		while (y >= vec2.npy)
		{
			x = (y - dat.b) / dat.k;
			x = ((x - (int)x) > 0.5) ? x + 1 : x;
			mlx_pixel_put(w_cr.mlx, w_cr.win, x, y, vec1.color);
			y--;
		}
	}
}

void		drow_line(t_win w_cr, t_data dat, t_point vec1, t_point vec2)
{
	dat.dx = vec2.npx - vec1.npx;
	dat.dy = vec2.npy - vec1.npy;
	dat.k = dat.dy / dat.dx;
	if (dat.dx == 0)
		dat.k = LIMITD;
	dat.b = vec1.npy - dat.k * vec1.npx;
	if (vec1.color == 0)
		vec1.color = 0xFFFFFF;
	if (ABS(dat.dx) < ABS(dat.dy))
	{
		print_vert(w_cr, dat, vec1, vec2);
	}
	if (ABS(dat.dx) >= ABS(dat.dy))
	{
		print_hori(w_cr, dat, vec1, vec2);
	}
}
