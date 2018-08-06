/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:02:09 by dkliukin          #+#    #+#             */
/*   Updated: 2017/12/21 17:02:11 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	minus_ch(const char *str, int *minus, int *i, int *len)
{
	if (str[*i] == '-')
	{
		*i = *i + 1;
		*len = *len - 1;
		*minus = -1;
	}
}

int		ft_atoi_base(const char *str, int str_base)
{
	int			res;
	int			len;
	int			i;
	int			cti;
	int			minus;

	i = 0;
	len = ft_strlen(str);
	res = 0;
	minus = 1;
	minus_ch(str, &minus, &i, &len);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			cti = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			cti = str[i] - 'A' + 10;
		else if (str[i] >= '0' && str[i] <= '9')
			cti = str[i] - '0';
		res += ft_qpow(str_base, len - 1) * cti;
		len--;
		i++;
	}
	return (res * minus);
}
