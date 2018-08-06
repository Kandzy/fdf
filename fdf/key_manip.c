/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:09:47 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/22 14:09:48 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x_axis(int keycode, t_data *dat)
{
	if (keycode == 84)
	{
		dat->phi -= 0.05;
	}
	if (keycode == 91)
	{
		dat->phi += 0.05;
	}
}

void	rot_y_axis(int keycode, t_data *dat)
{
	if (keycode == 88)
	{
		dat->psi -= 0.05;
	}
	if (keycode == 86)
	{
		dat->psi += 0.05;
	}
}

void	rot_z_axis(int keycode, t_data *dat)
{
	if (keycode == 89)
	{
		dat->gam -= 0.05;
	}
	if (keycode == 92)
	{
		dat->gam += 0.05;
	}
}

void	zooming(int keycode, t_data *dat)
{
	if (keycode == 69)
	{
		dat->scale += 1;
	}
	if (keycode == 78)
	{
		if (dat->scale - 1 > 0)
			dat->scale -= 1;
	}
}
