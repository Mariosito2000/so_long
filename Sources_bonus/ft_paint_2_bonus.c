/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:22:08 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:48 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong_bonus.h"

void	ft_paint_borders(t_mlx mlx, t_sprites sprites)
{
	int	i;

	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.border[2], 0, (32));
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.border[3], ((mlx.map_w + 1) * 32), (32));
	i = mlx.map_w - 1;
	while (i >= 0)
	{
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
		sprites.border[6], ((i + 1) * 32), (32));
		i--;
	}
	while (i < mlx.map_h - 2)
	{
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
		sprites.border[4], 0, ((i + 3) * 32));
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
		sprites.border[5], ((mlx.map_w + 1) * 32), ((i + 3) * 32));
		i++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.border[0], 0, ((i + 3) * 32));
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.border[1], ((mlx.map_w + 1) * 32), ((i + 3) * 32));
}

void	ft_paint_collectibles(char **map, t_game game)
{
	int	yx[2];

	if (game.player.collect == 1)
		ft_paint_key(game);
	else
	{
		yx[0] = 0;
		while (yx[0] < game.mlx.map_h)
		{
			yx[1] = 0;
			while (yx[1] < game.mlx.map_w)
			{
				if (map[yx[0]][yx[1]] == 'C')
					mlx_put_image_to_window(game.mlx.mlx, game.mlx.mlx_win, \
			game.sprites.collect[0], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
				yx[1]++;
			}
			yx[0]++;
		}
	}
}

void	ft_paint_key(t_game game)
{
	int	*coords;

	coords = ft_locate_obj('C', game.sprites.base_map);
	mlx_put_image_to_window(game.mlx.mlx, game.mlx.mlx_win, \
	game.sprites.collect[1], ((coords[1] + 1) * 32), ((coords[0] + 2) * 32));
	free(coords);
}
