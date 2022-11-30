/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_collect_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:44:58 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/30 13:15:32 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_loot() : substracts a calloctable item from the player count, if it reaches 1,
the last item changes it sprite to a key, (ft_open_door()) when the key is
looted, the door starts to open.
*/

#include "soulong_bonus.h"

void	ft_loot(t_game *game)
{
	int	*coords;

	coords = 0;
	game->player.collect--;
	game->sprites.base_map[game->player.y][game->player.x] = '0';
	if (game->player.collect == 1)
	{
		coords = ft_locate_obj('C', game->sprites.base_map);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.floor[(game->sprites.floor_map[coords[0]]
			[coords[1]]) - 97], (coords[1] + 1) * 32,
			(coords[0] + 2) * 32);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.collect[1], (coords[1] + 1) * 32,
			(coords[0] + 2) * 32);
	}
	if (game->player.collect == 0)
		game->sprites.base_map[game->player.door_y][game->player.door_x] = '1';
	free(coords);
}

void	ft_open_door(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.door_y]
		[game->player.door_x]) - 97], (game->player.door_x + 1) * 32,
		(game->player.door_y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.door[game->player.door], (game->player.door_x + 1) * 32,
		(game->player.door_y + 2) * 32);
		game->player.door++;
	if (game->player.door == 16)
		game->sprites.base_map[game->player.door_y][game->player.door_x] = 'E';
}
