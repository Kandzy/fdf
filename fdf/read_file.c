/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:33:58 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 16:32:14 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strjoin_mod(char *a, char *b)
{
	char	*str;

	str = ft_strjoin(a, b);
	ft_strdel(&a);
	return (str);
}

char		*read_map(char *path)
{
	int		fd;
	char	*line;
	char	*map;

	map = ft_strnew(0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);

	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin_mod(line, "*");
		map = ft_strconcat(map, line);
	}
	ft_strdel(&line);
	return (map);
}
