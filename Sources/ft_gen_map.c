/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:00:28 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 13:08:34 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Generates a 2D array from the text file the program receives.
*/

#include "soulong.h"

char	**ft_gen_map(int fd)
{
	size_t	i;
	char	**map;
	char	*temp;
	char	*sfree;

	map = 0;
	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map = ft_update_map(map, temp, i);
		sfree = temp;
		temp = get_next_line(fd);
		free(sfree);
		i++;
	}
	free(temp);
	map = ft_update_map(map, "", i);
	return (map);
}

char	**ft_update_map(char **map, char *temp, size_t size)
{
	char	**new;
	size_t	j;

	j = 0;
	new = (char **) malloc(sizeof(char *) * (size + 1));
	if (!new)
		ft_exit(2);
	if (map)
	{
		while (j < size)
		{
			new[j] = ft_strdup(map[j]);
			if (map[j])
				free(map[j]);
			j++;
		}
		free(map);
	}
	if (!ft_strlen(temp))
	{
		new[j] = 0;
	}
	else
		new[j] = ft_strdup(temp);
	return (new);
}
