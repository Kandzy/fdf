/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:21:50 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/22 16:21:54 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <pthread.h>

static void	print_commands(t_win w)
{
	int		g;

	g = 0x5555FF;
	mlx_string_put(w.mlx, w.win, 20, 10, g, "Scroll the mouse wheel to rotate \
	the shape;");
	mlx_string_put(w.mlx, w.win, 20, 25, g, "Click left mouse button to \
	move the shape;");
	mlx_string_put(w.mlx, w.win, 20, 41, g, "Press button 4 to rotate left;");
	mlx_string_put(w.mlx, w.win, 20, 56, g, "Press button 6 to rotate right;");
	mlx_string_put(w.mlx, w.win, 20, 71, g, "Press button 8 to rotate up;");
	mlx_string_put(w.mlx, w.win, 20, 86, g, "Press button 2 to rorate down;");
	mlx_string_put(w.mlx, w.win, 20, 101, g, "Press button 7 to rotate \
	counterclockwise;");
	mlx_string_put(w.mlx, w.win, 20, 116, g, "Press button 8 to rotate \
	clockwise;");
	mlx_string_put(w.mlx, w.win, 20, 131, g, "Press button +/- for zooming;");
	mlx_string_put(w.mlx, w.win, 20, 146, g, "Click right mouse button \
	to reset the parameters;");
}

void		drow_map(t_win w_cr, t_data dat, t_point *vec)
{
	int		i;

	mlx_clear_window(w_cr.mlx, w_cr.win);
	print_commands(w_cr);
	rot_axis(dat, vec);
	i = 0;
	while (i < dat.nx * dat.ny - 1)
	{
		if ((i + 1) % dat.nx == 0)
			drow_line(w_cr, dat, vec[i], vec[i + dat.nx]);
		else
			drow_line(w_cr, dat, vec[i], vec[i + 1]);
		if ((i + dat.nx) < (dat.nx * dat.ny))
			drow_line(w_cr, dat, vec[i], vec[i + dat.nx]);
		i++;
	}
}

static void	*drow_1(void *a)
{
	int			i;
	t_structs	*s;

	s = (t_structs*)a;
	i = 0;
	while (i < s->dat.nx * s->dat.ny - 1)
	{
		if ((i + 1) % s->dat.nx == 0)
			drow_line(s->w_cr, s->dat, s->vec[i], s->vec[i + s->dat.nx]);
		else
			drow_line(s->w_cr, s->dat, s->vec[i], s->vec[i + 1]);
		i++;
	}
	return (0);
}

static void	*drow_2(void *a)
{
	int			i;
	t_structs	*s;

	s = (t_structs*)a;
	i = 0;
	while (i < s->dat.nx * s->dat.ny - 1)
	{
		if ((i + s->dat.nx) < (s->dat.nx * s->dat.ny))
			drow_line(s->w_cr, s->dat, s->vec[i], s->vec[i + s->dat.nx]);
		i++;
	}
	return (0);
}

void		re_drow_map(t_structs *s)
{
	pthread_t	thread[2];
	int			status[2];
	int			status_addr[2];
	int			g;

	g = 0x00FF00;
	mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
	print_commands(s->w_cr);
	rot_axis(s->dat, s->vec);
	status[0] = pthread_create(&thread[0], NULL, &drow_1, s);
	status[0] = pthread_join(thread[0], (void**)&status_addr[0]);
	status[1] = pthread_create(&thread[1], NULL, &drow_2, s);
	status[1] = pthread_join(thread[1], (void**)&status_addr[1]);
}
