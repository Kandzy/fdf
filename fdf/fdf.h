/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:14:42 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 16:35:34 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# define WIDTH 1300
# define HEIGHT 1400
# define LIMITD 9223372036854775807
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/includes/libft.h"

typedef struct		s_win
{
	void	*mlx;
	void	*win;
}					t_win;

typedef struct		s_point
{
	int		px;
	int		py;
	int		pz;
	int		color;
	double	npx;
	double	npy;
}					t_point;

typedef struct		s_data
{
	short	nx;
	short	ny;
	short	center[2];
	double	dx;
	double	dy;
	double	k;
	double	b;
	double	scale;
	double	phi;
	double	psi;
	double	gam;
}					t_data;

typedef struct		s_structs
{
	t_data			dat;
	t_point			*vec;
	t_win			w_cr;
}					t_structs;

void				drow_line(t_win w_cr, t_data dat,
	t_point vec1, t_point vec2);
void				drow_map(t_win w_cr, t_data dat,
	t_point *vec);
void				error(int ac, int err);
int					validate_map(char *map, t_data *dat);
char				*read_map(char *path);
void				set_coordinates(t_data dat, char *map);
int					ft_atoi_base(const char *str, int str_base);
void				win_controller(t_data dat, t_point *vec);
void				rot_axis(t_data dat, t_point *vec);
void				rot_x_axis(int keycode, t_data *dat);
void				rot_y_axis(int keycode, t_data *dat);
void				rot_z_axis(int keycode, t_data *dat);
void				zooming(int keycode, t_data *dat);
void				m_rot_x_axis(int button, t_data *dat);
void				m_rot_y_axis(int button, t_data *dat);
void				m_center(int button, int x, int y, t_data *dat);
void				del_double_arr(char ***str, int	size);
void				re_drow_map(t_structs *s);
void				set_init_cond(t_data *dat);

#endif
