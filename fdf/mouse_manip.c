/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:27:05 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/22 19:27:06 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	m_rot_x_axis(int button, t_data *dat)
{
	if (button == 4)
	{
		dat->phi -= 0.015;
	}
	if (button == 5)
	{
		dat->phi += 0.015;
	}
}

void	m_rot_y_axis(int button, t_data *dat)
{
	if (button == 6)
	{
		dat->psi -= 0.015;
	}
	if (button == 7)
	{
		dat->psi += 0.015;
	}
}

void	m_center(int button, int x, int y, t_data *dat)
{
	if (button == 1)
	{
		dat->center[0] = x;
		dat->center[1] = y;
	}
}
