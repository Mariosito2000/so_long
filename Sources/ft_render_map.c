/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:12:03 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/24 12:41:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong.h"

void	ft_render_torch(t_game *game)
{
	t_torch	*torch;
	t_list	*start;

	start = game->sprites.torch;
	while (start)
	{
		torch = start->content;
		torch->frame += 1;
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.deco[14], ((torch->x + 1) * 32),
			((torch->y + 2) * 32));
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
		game->sprites.deco[torch->frame % 6], ((torch->x + 1) * 32),
			((torch->y + 2) * 32));
		start = start->next;
	}
}

void	ft_render_player(t_game *game)
{
	game->player.frame++;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.floor[(game->sprites.floor_map[game->player.y]
		[game->player.x]) - 97], (game->player.x + 1) * 32,
		(game->player.y + 2) * 32);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
	game->sprites.player[(game->player.frame % 6) + game->player.dir * 12], \
		(game->player.x + 1) * 32, (game->player.y + 2) * 32);
}

int	ft_inputs_press(int key, t_game *game)
{
	if ((key == 0 || key == 123) && game->player.state == 0)
		ft_move_left(game);
	else if ((key == 1 || key == 125) && game->player.state == 0)
		ft_move_down(game);
	else if ((key == 2 || key == 124) && game->player.state == 0)
		ft_move_right(game);
	else if ((key == 13 || key == 126) && game->player.state == 0)
		ft_move_up(game);
	else if (key == 53)
		exit(0);
	return (0);
}

int	ft_render_game(t_game *game)
{
	static int	frame;

	frame++;
	if (frame == 600 && game->player.collect == 0 && game->player.door < 16)
		ft_open_door(game);
	if (frame % 400 == 0 && game->player.state)
		ft_player_anim(game);
	if (frame == 1200)
		ft_render_torch(game);
	if (frame == 1200 && game->player.state == 0)
		ft_render_player(game);
	frame = frame % 1200;
	if (game->sprites.base_map[game->player.y][game->player.x] == 'C')
		ft_loot(game);
	if (game->sprites.base_map[game->player.y][game->player.x] == 'E'\
		&& game->player.door == 16)
	{
		ft_printf("\n*** GANASTE MI NINIO ***\n\n");
		exit(0);
	}
	mlx_hook(game->mlx.mlx_win, 2, 0, ft_inputs_press, game);
	mlx_hook(game->mlx.mlx_win, 17, 0, ft_exit, game);
	return (0);
}
