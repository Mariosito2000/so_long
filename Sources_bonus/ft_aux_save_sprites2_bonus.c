/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_save_sprites2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:30:06 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/30 17:11:28 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong_bonus.h"

void	ft_extra_sprites2(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).floor[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_11.xpm", &i, &i);
	(*sprites).door[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f11.xpm", &i, &i);
	(*sprites).deco[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/table.xpm", &i, &i);
	(*sprites).player[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f5.xpm", &i, &i);
}

void	ft_put_enemy(int *yx, t_mlx mlx)
{
	void	*sprite;
	int		i;

	i = 0;
	sprite = mlx_xpm_file_to_image(mlx.mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f0.xpm", &i, &i);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
		sprite, ((yx[1] + 1) * 32), ((yx[0] + 2) * 32));
}
