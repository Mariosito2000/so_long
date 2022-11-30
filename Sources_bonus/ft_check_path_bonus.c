/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:48:02 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/30 13:15:47 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks that all the collectable items and the exit are accesible recursively.
*/

#include "soulong_bonus.h"

int				*ft_locate_obj(char obj, char **map);

int				ft_count_obj(char **map);

static void		ft_recursive_path(int j, int i, char **map, int *objs);

static void		ft_aux_recursive_path(int j, int i, char **map, int *objs);

int	ft_check_path(char **map)
{
	char	**copy;
	int		*coords;
	int		objs;

	copy = ft_copy_map(map);
	objs = ft_count_obj(map);
	coords = ft_locate_obj('P', map);
	ft_recursive_path(coords[0], coords[1], copy, &objs);
	ft_free_map(copy);
	free(coords);
	if (objs)
		ft_exit(1);
	return (0);
}

static void	ft_recursive_path(int j, int i, char **map, int *objs)
{
	if (!(*objs))
		return ;
	if (map[j - 1][i] != '1' && map[j - 1][i] != '+')
	{
		if (map[j - 1][i] == 'E' || map[j - 1][i] == 'C')
			(*objs)--;
		map[j - 1][i] = '+';
		ft_recursive_path(j - 1, i, map, objs);
	}
	if (map[j + 1][i] != '1' && map[j + 1][i] != '+')
	{
		if (map[j + 1][i] == 'E' || map[j + 1][i] == 'C')
			(*objs)--;
		map[j + 1][i] = '+';
		ft_recursive_path(j + 1, i, map, objs);
	}
	ft_aux_recursive_path(j, i, map, objs);
}

static void	ft_aux_recursive_path(int j, int i, char **map, int *objs)
{
	if (map[j][i - 1] != '1' && map[j][i - 1] != '+')
	{
		if (map[j][i - 1] == 'E' || map[j][i - 1] == 'C')
			(*objs)--;
		map[j][i - 1] = '+';
		ft_recursive_path(j, i - 1, map, objs);
	}
	if (map[j][i + 1] != '1' && map[j][i + 1] != '+')
	{
		if (map[j][i + 1] == 'E' || map[j][i + 1] == 'C')
			(*objs)--;
		map[j][i + 1] = '+';
		ft_recursive_path(j, i + 1, map, objs);
	}
}

int	ft_count_obj(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	*ft_locate_obj(char obj, char **map)
{
	int		*coords;
	int		i;
	int		j;

	j = 0;
	coords = malloc(sizeof(int) * 2);
	if (!coords)
		ft_exit(2);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == obj)
			{
				coords[0] = j;
				coords[1] = i;
				return (coords);
			}
			i++;
		}
		j++;
	}
	free(coords);
	return (0);
}
