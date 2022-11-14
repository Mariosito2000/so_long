/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:05:18 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/09 13:30:50 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Check dimensions to ensure the map is a rectangle.

2. Checks that all the chars in the map are correct (1, 0, P, C, E), it also 
checks there is only one player, one exit and at least one colectable item.

3. Checks the borders of the map to checks they are all build of wall chars(1).
*/

#include "soulong.h"

static int	ft_check_dim(char **map);

static int	ft_check_char(char **map);

static int	ft_check_borders(char **map);

int	ft_check_map(char **map)
{
	if (ft_check_dim(map))
		return (-1);
	if (ft_check_char(map))
		return (-2);
	return (0);
}

static int	ft_check_dim(char **map)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i + 1] == 0)
		{
			if (len != ft_strlen(map[i]) + 1)
				return (-1);
		}
		else if (len != ft_strlen(map[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check_char(char **map)
{
	int		j;
	int		i;
	int		control[3];

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i])
		{
			if (ft_strchr_mod("10CEP", map[j][i]) == -1)
				return (-1);
			if (map[j][i] == 'P')
				control[0]++;
			if (map[j][i] == 'E')
				control[1]++;
			if (map[j][i] == 'C')
				control[2]++;
			i++;
		}
		j++;
	}
	if (control[0] != 1 || control[1] != 1 || control[2] == 0)
		return (-1);
	return (ft_check_borders(map));
}

static int	ft_check_borders(char **map)
{
	size_t	hlen;
	size_t	vlen;
	size_t	i;

	i = 0;
	hlen = ft_strlen(map[0]) - 1;
	vlen = 0;
	while (map[vlen])
		vlen++;
	while (i++ < hlen)
		if (map[0][i - 1] != '1')
			return (-1);
	i = 0;
	while (i++ < hlen)
		if (map[vlen - 1][i - 1] != '1')
			return (-1);
	i = 0;
	while (i++ < vlen)
		if (map[i - 1][0] != '1')
			return (-1);
	i = 0;
	while (i++ < vlen)
		if (map[i - 1][hlen - 1] != '1')
			return (-1);
	return (0);
}
