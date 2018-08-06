/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:15:40 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/22 16:15:41 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_axis(t_data dat, t_point *vec)
{
	int		i;

	i = 0;
	while (i < (dat.nx * dat.ny))
	{
		vec[i].npx = vec[i].px * cos(dat.psi) * cos(dat.gam) +
		vec[i].pz * sin(dat.psi) - vec[i].py * cos(dat.psi) * sin(dat.gam);
		vec[i].npy = -vec[i].pz * cos(dat.psi) * sin(dat.phi) +
		vec[i].px * (cos(dat.gam) * sin(dat.phi) * sin(dat.psi) +
		cos(dat.phi) * sin(dat.gam)) +
		vec[i].py * (cos(dat.phi) * cos(dat.gam) -
		sin(dat.phi) * sin(dat.psi) * sin(dat.gam));
		vec[i].npx = vec[i].npx * dat.scale + dat.center[0];
		vec[i].npy = vec[i].npy * dat.scale + dat.center[1];
		i++;
	}
}
