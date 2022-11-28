/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:22:16 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:48 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong_bonus.h"

void	ft_aux_paint_deco(char	**map, int	*yx, t_mlx mlx, t_sprites sprites);

void	ft_create_window(char	**map, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->map_w = ft_strlen(map[0]) - 1;
	mlx->map_h = 0;
	while (map[mlx->map_h])
		mlx->map_h++;
	mlx->mlx_win = mlx_new_window(mlx->mlx, ((*mlx).map_w + 2) * 32, \
		((*mlx).map_h + 3) * 32, "viedoyogo");
}

void	ft_paint_base(char	**map, t_mlx mlx, t_sprites sprites)
{
	int	yx[2];

	yx[0] = 0;
	while (yx[0] < mlx.map_h)
	{
		yx[1] = 0;
		while (yx[1] < mlx.map_w)
		{
			if (ft_strchr_mod("1FK", map[yx[0]][yx[1]]) != -1)
			{
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.wall[arc4random() % 6], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
				if (map[yx[0]][yx[1]] == 'F')
					mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
sprites.deco[(arc4random() % 2) + 6], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
				if (map[yx[0]][yx[1]] == 'K')
					mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[8], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
			}
			else if (ft_strchr_mod("0PCEMTBYt", map[yx[0]][yx[1]]) != -1)
				ft_paint_floor(yx, mlx, sprites);
			yx[1]++;
		}
		yx[0]++;
	}
}

void	ft_paint_deco(char	**map, t_mlx mlx, t_sprites sprites)
{
	int	yx[2];

	yx[0] = 0;
	while (yx[0] < mlx.map_h)
	{
		yx[1] = 0;
		while (yx[1] < mlx.map_w)
		{
			ft_aux_paint_deco(map, yx, mlx, sprites);
			yx[1]++;
		}
		yx[0]++;
	}
}

void	ft_paint_floor(int	*yx, t_mlx mlx, t_sprites sprites)
{
	int	floor;

	floor = sprites.floor_map[yx[0]][yx[1]] - 'a';
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.floor[floor], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
}

void	ft_aux_paint_deco(char	**map, int	*yx, t_mlx mlx, t_sprites sprites)
{
	if (map[yx[0]][yx[1]] == 'B')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[10], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
	if (map[yx[0]][yx[1]] == 'M')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[11], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
	if (map[yx[0]][yx[1]] == 'T')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[12], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
	if (map[yx[0]][yx[1]] == 'Y')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[9], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
	if (map[yx[0]][yx[1]] == 'S')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	sprites.deco[13], ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
}
