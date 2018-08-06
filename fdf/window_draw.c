/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:44:00 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 18:44:02 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		exit_x(void)
{
	exit(1);
}

static int		key_manip(int kc, t_structs *s)
{
	if (kc == 86 || kc == 88 || kc == 84 || kc == 91 || kc == 89 || kc == 92
	|| kc == 69 || kc == 78)
		mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
	if (kc == 86 || kc == 88)
		rot_y_axis(kc, &(s->dat));
	if (kc == 84 || kc == 91)
		rot_x_axis(kc, &(s->dat));
	if (kc == 89 || kc == 92)
		rot_z_axis(kc, &(s->dat));
	if (kc == 69 || kc == 78)
		zooming(kc, &(s->dat));
	if (kc == 86 || kc == 88 || kc == 84 || kc == 91 || kc == 89 || kc == 92
	|| kc == 69 || kc == 78)
		re_drow_map(s);
	if (kc == 53)
		exit(1);
	return (0);
}

static int		mouse_manip(int button, int x, int y, t_structs *s)
{
	if (button == 7 || button == 6)
	{
		mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
		m_rot_y_axis(button, &(s->dat));
		re_drow_map(s);
	}
	if (button == 4 || button == 5)
	{
		mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
		m_rot_x_axis(button, &(s->dat));
		re_drow_map(s);
	}
	if (button == 1)
	{
		mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
		m_center(button, x, y, &(s->dat));
		re_drow_map(s);
	}
	if (button == 2)
	{
		mlx_clear_window(s->w_cr.mlx, s->w_cr.win);
		set_init_cond(&(s->dat));
		re_drow_map(s);
	}
	return (0);
}

static int		key_manip_hook(t_structs *s)
{
	mlx_key_hook(s->w_cr.win, key_manip, s);
	mlx_mouse_hook(s->w_cr.win, mouse_manip, s);
	return (0);
}

void			win_controller(t_data dat, t_point *vec)
{
	t_win		w_cr;
	t_structs	stru;

	stru.dat = dat;
	stru.vec = vec;
	w_cr.mlx = mlx_init();
	w_cr.win = mlx_new_window(w_cr.mlx, HEIGHT, WIDTH, "fdf");
	stru.w_cr = w_cr;
	drow_map(w_cr, dat, vec);
	mlx_hook(w_cr.win, 17, 1L << 17, exit_x, &w_cr);
	mlx_expose_hook(w_cr.win, key_manip_hook, &stru);
	mlx_loop(w_cr.mlx);
}
