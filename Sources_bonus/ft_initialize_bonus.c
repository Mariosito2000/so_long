/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:20 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:35:46 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong_bonus.h"

void	ft_initialize_player(t_player *player, char **map)
{
	int	*coords;

	player->collect = (int)ft_count_obj(map) - 1;
	coords = ft_locate_obj('P', map);
	player->y = coords[0];
	player->x = coords[1];
	player->dir = 0;
	player->door = 0;
	player->frame = 0;
	player->state = 0;
	free(coords);
	coords = ft_locate_obj('E', map);
	player->door_y = coords[0];
	player->door_x = coords[1];
	player->steps = 0;
	player->run = 0;
	free(coords);
}

void	ft_initialize_torch(char **map, t_list **torch)
{
	int		j;
	int		i;
	t_torch	*new;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i])
		{
			if (map[j][i] == 'L')
			{
				new = malloc(sizeof(t_torch));
				if (!new)
					ft_exit(2);
				new->x = i;
				new->y = j;
				new->frame = arc4random() % 6;
				new->wall = arc4random() % 6;
				if (!*torch)
					*torch = ft_lstnew(new);
				else
					ft_lstadd_back(torch, ft_lstnew(new));
			}
			i++;
		}
		j++;
	}
}

void	ft_initialize_enemies(char **map, t_list **enemies)
{
	int		j;
	int		i;
	t_enemies *new;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\n' && map[j][i])
		{
			if (map[j][i] == 'L')
			{
				new = malloc(sizeof(t_torch));
				if (!new)
					ft_exit(2);
				new->x = i;
				new->y = j;
				new->frame = arc4random() % 6;
				new->wall = arc4random() % 6;
				if (!*torch)
					*torch = ft_lstnew(new);
				else
					ft_lstadd_back(torch, ft_lstnew(new));
			}
			i++;
		}
		j++;
	}
}