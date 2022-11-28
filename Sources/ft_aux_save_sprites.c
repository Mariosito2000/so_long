/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_save_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:57:05 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/24 15:38:39 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Auxiliary function for ft_save_sprites().
*/

#include "soulong.h"

void	ft_door_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).door = malloc(sizeof(void *) * 16);
	if (!(*sprites).door)
		ft_exit(2);
	(*sprites).door[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f0.xpm", &i, &i);
	(*sprites).door[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f1.xpm", &i, &i);
	(*sprites).door[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f2.xpm", &i, &i);
	(*sprites).door[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f3.xpm", &i, &i);
	(*sprites).door[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f4.xpm", &i, &i);
	(*sprites).door[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f5.xpm", &i, &i);
	(*sprites).door[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f6.xpm", &i, &i);
	(*sprites).door[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f7.xpm", &i, &i);
	(*sprites).door[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f8.xpm", &i, &i);
	(*sprites).door[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f9.xpm", &i, &i);
	(*sprites).door[10] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f10.xpm", &i, &i);
}

void	ft_extra_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).door[12] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f12.xpm", &i, &i);
	(*sprites).door[13] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_anim_opening_f13.xpm", &i, &i);
	(*sprites).door[14] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/door_fullyopen.xpm", &i, &i);
	(*sprites).door[15] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Door/stair.xpm", &i, &i);
	(*sprites).deco[12] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/table_2.xpm", &i, &i);
	(*sprites).deco[13] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/bookshelf.xpm", &i, &i);
	(*sprites).deco[14] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_2.xpm", &i, &i);
	(*sprites).floor[12] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_12.xpm", &i, &i);
	(*sprites).floor[13] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_13.xpm", &i, &i);
	(*sprites).floor[14] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_14.xpm", &i, &i);
	(*sprites).floor[15] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_15.xpm", &i, &i);
	(*sprites).floor[16] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_16.xpm", &i, &i);
}

void	ft_player_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).player = malloc(sizeof(void *) * 24);
	if (!(*sprites).player)
		ft_exit(2);
	(*sprites).player[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f0.xpm", &i, &i);
	(*sprites).player[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f1.xpm", &i, &i);
	(*sprites).player[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f2.xpm", &i, &i);
	(*sprites).player[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f3.xpm", &i, &i);
	(*sprites).player[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f4.xpm", &i, &i);
	(*sprites).player[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_idle_anim_f5.xpm", &i, &i);
	(*sprites).player[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f0.xpm", &i, &i);
	(*sprites).player[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f1.xpm", &i, &i);
	(*sprites).player[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f2.xpm", &i, &i);
	(*sprites).player[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f3.xpm", &i, &i);
	(*sprites).player[10] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_run_anim_f4.xpm", &i, &i);
}

void	ft_player_rev_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).player[12] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f0.xpm", &i, &i);
	(*sprites).player[13] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f1.xpm", &i, &i);
	(*sprites).player[14] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f2.xpm", &i, &i);
	(*sprites).player[15] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f3.xpm", &i, &i);
	(*sprites).player[16] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f4.xpm", &i, &i);
	(*sprites).player[17] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_idle_anim_f5.xpm", &i, &i);
	(*sprites).player[18] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f0.xpm", &i, &i);
	(*sprites).player[19] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f1.xpm", &i, &i);
	(*sprites).player[20] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f2.xpm", &i, &i);
	(*sprites).player[21] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f3.xpm", &i, &i);
	(*sprites).player[22] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f4.xpm", &i, &i);
	(*sprites).player[23] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Knight/knight_rev_run_anim_f5.xpm", &i, &i);
}

void	ft_deco_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).deco = malloc(sizeof(void *) * 15);
	if (!(*sprites).deco)
		ft_exit(2);
	(*sprites).deco[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f0.xpm", &i, &i);
	(*sprites).deco[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f1.xpm", &i, &i);
	(*sprites).deco[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f2.xpm", &i, &i);
	(*sprites).deco[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f3.xpm", &i, &i);
	(*sprites).deco[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f4.xpm", &i, &i);
	(*sprites).deco[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/torch_anim_f5.xpm", &i, &i);
	(*sprites).deco[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/flag_green.xpm", &i, &i);
	(*sprites).deco[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/flag_red.xpm", &i, &i);
	(*sprites).deco[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/prisoner.xpm", &i, &i);
	(*sprites).deco[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/chest.xpm", &i, &i);
	(*sprites).deco[10] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Deco/barrel.xpm", &i, &i);
}
