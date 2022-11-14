/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_deco.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:01:51 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/10 15:34:23 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Selects the best places for the decoration depending on the surrounding squares.
Decorations[] :
 
1. ('L') Torch (put over a wall, cant have any hanging decoration in a wall near,
1 floor under);

2. ('F') Flag (put over a wall, cant have any hanging decoration in a wall near,
1 floor under);

3. ('K') Prisoner (put over a wall, cant have any hanging decoration in a wall
near, 1 floor under);

4. ('M') Table (Replaces 1 wall );

5. ('Y') Chest;

6. ('B') Barrel;

7. ('S') Bookshelf; 

8. ('T') Big_table (Replaces 2 walls has 2 floor under )
*/

#include "soulong.h"

static void	ft_decorate_map(char **deco, int j, int i, int random);

char	**ft_build_deco(char **map)
{
	char	**deco;
	int		i;
	int		j;

	j = 1;
	deco = ft_copy_map(map);
	while (deco[j + 1])
	{
		i = 1;
		while (deco[j][i + 1] != '\n' && deco[j][i])
		{
			if (deco[j][i] == '1')
				ft_decorate_map(deco, j, i, arc4random() % 8);
			i++;
		}
		j++;
	}
	return (deco);
}

static void	ft_decorate_map(char **deco, int j, int i, int random)
{
	if (deco[j + 1][i] != '1' && deco[j - 1][i] != '1'
		&& deco[j][i - 1] != '1' && deco[j][i + 1] != '1')
		deco[j][i] = 'B';
	if (deco[j + 1][i] != '1' && deco[j][i] != 'B')
	{
		if (deco[j][i - 1] != '1' && deco[j][i + 1] != '1')
			deco[j][i] = 'M';
		if (random == 0)
			deco[j][i] = 'K';
		else if (random == 1)
			deco[j][i] = 'F';
		else if (random == 2)
			deco[j][i] = 'S';
		else if (random == 3)
			deco[j][i] = 'L';
		else if (random == 4)
			deco[j][i] = 'Y';
		else if (deco[j + 1][i] != '1' && deco[j - 1][i] == '1'
			&& deco[j][i - 1] != '1' && deco[j - 1][i + 1] == '1' &&
			deco[j + 1][i + 1] != '1' && random > 4)
		{
			deco[j][i] = 'T';
			deco[j][i + 1] = 'T';
		}
	}
}

char	**ft_copy_map(char **map)
{
	char	**deco;
	int		i;

	deco = 0;
	i = 0;
	while (map[i])
	{
		deco = ft_update_map(deco, map[i], i);
		i++;
	}
	deco = ft_update_map(deco, "", i);
	deco[i] = 0;
	return (deco);
}
