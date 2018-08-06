/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:14:50 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 16:32:29 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	char	*map;
	t_data	dat;

	if (ac != 2)
	{
		ft_putendl_fd("Argument != 2", 2);
		return (0);
	}
	map = read_map(av[1]);
	if (map && !map[0])
	{
		ft_putendl_fd("Map executing error.", 2);
		return (0);
	}
	
	if (validate_map(map, &dat) == -1)
	{
		ft_putendl_fd("Map validation error.", 2);
		return (0);
	}
	set_coordinates(dat, map);
	return (0);
}
