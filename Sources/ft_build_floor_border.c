/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_floor_border.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:36:09 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/11 13:38:09 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates the floor tiles map with random sprites.
*/

#include "soulong.h"

char	**ft_build_floor(char	**map)
{
	char	**floor;
	int		i;
	int		j;

	j = 1;
	floor = ft_copy_map(map);
	while (floor[j + 1])
	{
		i = 1;
		while (floor[j][i + 1] != '\n' && floor[j][i])
		{
			if (ft_strchr_mod("0PECBYMT", floor[j][i]) != -1)
				floor[j][i] = (arc4random() % 17) + 97;
			i++;
		}
		j++;
	}
	return (floor);
}

char	**ft_build_border(char	**map)
{
	char	**border;
	int		i;
	int		j;

	j = 1;
	border = ft_copy_map(map);
	while (border[j + 1])
	{
		i = 1;
		while (border[j][i + 1] != '\n' && border[j][i])
		{
			
			i++;
		}
		j++;
	}
	return (border);
}
