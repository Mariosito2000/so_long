/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:09:26 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/15 13:24:19 by marias-e         ###   ########.fr       */
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
			if (ft_strchr_mod("0PECBYMTt", floor[j][i]) != -1)
				floor[j][i] = (arc4random() % 17) + 'a';
			i++;
		}
		j++;
	}
	return (floor);
}
