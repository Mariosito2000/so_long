/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:10:08 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/30 16:55:51 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_exit() filters the reason why the process is terminated, freeing all the
allocated memory.

0. Clean close

1. Map error

2. Memory allocation failed

ft_move_*() manages the player position and direction when an input is received
*/

#include "soulong_bonus.h"

int	ft_exit(int reason)
{
	if (reason == 0)
		exit(0);
	else if (reason == 1)
	{
		printf("\nError\nMap error\n\n");
		exit(0);
	}
	else if (reason == 2)
	{
		printf("\nError\nMemory allocation failed\n\n");
		exit(0);
	}
	else if (reason == 3)
	{
		printf("\nError\nInvalid number of arguments\n\n");
		exit(0);
	}
	else if (reason == 4)
	{
		printf("\nError\nInvalid type of file\n\n");
		exit(0);
	}
	exit(0);
}

void	ft_move_left(t_game *game)
{
	char	*temp;

	temp = 0;
	if (game->sprites.base_map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.state = 1;
		game->player.dir = 1;
		game->player.x--;
		game->player.steps++;
		ft_paint_black(game);
		temp = ft_itoa(game->player.steps);
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 14, 10, \
			0x679CAB, "STEPS:");
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 80, 10, \
			0xE3E34D, temp);
	}
	free(temp);
}

void	ft_move_right(t_game *game)
{
	char	*temp;

	temp = 0;
	if (game->sprites.base_map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.state = 2;
		game->player.dir = 0;
		game->player.x++;
		game->player.steps++;
		ft_paint_black(game);
		temp = ft_itoa(game->player.steps);
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 14, 10, \
			0x679CAB, "STEPS:");
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 80, 10, \
			0xE3E34D, temp);
	}
	free(temp);
}

void	ft_move_down(t_game *game)
{
	char	*temp;

	temp = 0;
	if (game->sprites.base_map[game->player.y + 1][game->player.x] != '1')
	{
		game->player.state = 3;
		game->player.y++;
		game->player.steps++;
		ft_paint_black(game);
		temp = ft_itoa(game->player.steps);
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 14, 10, \
			0x679CAB, "STEPS:");
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 80, 10, \
			0xE3E34D, temp);
	}
	free(temp);
}

void	ft_move_up(t_game *game)
{
	char	*temp;

	temp = 0;
	if (game->sprites.base_map[game->player.y - 1][game->player.x] != '1')
	{
		game->player.state = 4;
		game->player.y--;
		game->player.steps++;
		ft_paint_black(game);
		temp = ft_itoa(game->player.steps);
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 14, 10, \
			0x679CAB, "STEPS:");
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 80, 10, \
			0xE3E34D, temp);
	}
	free(temp);
}
