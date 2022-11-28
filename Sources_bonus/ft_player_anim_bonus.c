/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_anim_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:51:39 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:48 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong_bonus.h"

void	ft_anim_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x + 1]) - 97], (game->player.x + 1 + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.player[game->player.run + (game->player.dir * 12) + 6], \
	(game->player.x + 1 + 1) * 32 - (game->player.run / (float)6) * 32,
		(game->player.y + 2) * 32);
	if (game->player.run == 5)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.floor[(game->sprites.floor_map[game->player.y]
			[game->player.x + 1]) - 97], (game->player.x + 1 + 1) * 32,
			(game->player.y + 2) * 32);
	game->player.run++;
}

void	ft_anim_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x - 1]) - 97], (game->player.x - 1 + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.player[game->player.run + (game->player.dir * 12) + 6], \
	(game->player.x - 1 + 1) * 32 + (game->player.run / (float)6) * 32,
		(game->player.y + 2) * 32);
	if (game->player.run == 5)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.floor[(game->sprites.floor_map[game->player.y]
			[game->player.x - 1]) - 97], (game->player.x - 1 + 1) * 32,
			(game->player.y + 2) * 32);
	game->player.run++;
}

void	ft_anim_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y - 1]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y - 1 + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.player[game->player.run + (game->player.dir * 12) + 6], \
	(game->player.x + 1) * 32,
		(game->player.y - 1 + 2) * 32 + (game->player.run / (float)6) * 32);
	if (game->player.run == 5)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.floor[(game->sprites.floor_map[game->player.y - 1]
			[game->player.x]) - 97], (game->player.x + 1) * 32,
			(game->player.y - 1 + 2) * 32);
	game->player.run++;
}

void	ft_anim_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y + 1]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 1 + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.player[game->player.run + (game->player.dir * 12) + 6], \
	(game->player.x + 1) * 32,
		(game->player.y + 1 + 2) * 32 - (game->player.run / (float)6) * 32);
	if (game->player.run == 5)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.floor[(game->sprites.floor_map[game->player.y + 1]
			[game->player.x]) - 97], (game->player.x + 1) * 32,
			(game->player.y + 1 + 2) * 32);
	game->player.run++;
}

void	ft_player_anim(t_game *game)
{
	if (game->player.state == 1)
		ft_anim_left(game);
	else if (game->player.state == 2)
		ft_anim_right(game);
	else if (game->player.state == 3)
		ft_anim_down(game);
	else if (game->player.state == 4)
		ft_anim_up(game);
	if (game->player.run == 6)
	{
		game->player.run = 0;
		game->player.state = 0;
	}
}
