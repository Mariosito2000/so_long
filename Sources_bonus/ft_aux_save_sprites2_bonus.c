/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_save_sprites2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:30:06 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:21:22 by marias-e         ###   ########.fr       */
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
	(*sprites).enemy[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f5.xpm", &i, &i);
}

void	ft_enemy_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).enemy = malloc(sizeof(void *) * 12);
	if (!(*sprites).enemy)
		ft_exit(2);
	(*sprites).enemy[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f0.xpm", &i, &i);
	(*sprites).enemy[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f1.xpm", &i, &i);
	(*sprites).enemy[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f2.xpm", &i, &i);
	(*sprites).enemy[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f3.xpm", &i, &i);
	(*sprites).enemy[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f4.xpm", &i, &i);
	(*sprites).enemy[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Goblin/goblin_idle_anim_f5.xpm", &i, &i);
	(*sprites).enemy[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f0.xpm", &i, &i);
	(*sprites).enemy[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f1.xpm", &i, &i);
	(*sprites).enemy[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f2.xpm", &i, &i);
	(*sprites).enemy[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f3.xpm", &i, &i);
	(*sprites).enemy[10] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Enemy/Slime/slime_idle_anim_f4.xpm", &i, &i);
}
