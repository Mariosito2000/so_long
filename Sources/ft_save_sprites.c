/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:52:18 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/11 13:33:32 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates the images and saves them in my sprites structure.
*/

#include "soulong.h"

static void	ft_collect_sprites(t_sprites *sprites, void *mlx, int i);

static void	ft_border_sprites(t_sprites *sprites, void *mlx, int i);

static void	ft_wall_sprites(t_sprites *sprites, void *mlx, int i);

static void	ft_floor_sprites(t_sprites *sprites, void *mlx, int i);

void	ft_save_sprites(char **map, t_sprites *sprites, void *mlx)
{	
	int	i;

	i = 0;
	ft_floor_sprites(sprites, mlx, i);
	ft_wall_sprites(sprites, mlx, i);
	ft_player_sprites(sprites, mlx, i);
	ft_collect_sprites(sprites, mlx, i);
	ft_deco_sprites(sprites, mlx, i);
	ft_door_sprites(sprites, mlx, i);
	ft_border_sprites(sprites, mlx, i);
	ft_extra_sprites(sprites, mlx, i);
	(*sprites).deco_map = ft_build_deco(map);
	(*sprites).floor_map = ft_build_floor((*sprites).deco_map);
	(*sprites).border_map = ft_build_border((*sprites).deco_map);
	return ;
}

static void	ft_floor_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).floor = malloc(sizeof(void *) * 17);
	(*sprites).floor[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_0.xpm", &i, &i);
	(*sprites).floor[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_1.xpm", &i, &i);
	(*sprites).floor[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_2.xpm", &i, &i);
	(*sprites).floor[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_3.xpm", &i, &i);
	(*sprites).floor[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_4.xpm", &i, &i);
	(*sprites).floor[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_5.xpm", &i, &i);
	(*sprites).floor[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_6.xpm", &i, &i);
	(*sprites).floor[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_7.xpm", &i, &i);
	(*sprites).floor[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_8.xpm", &i, &i);
	(*sprites).floor[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_9.xpm", &i, &i);
	(*sprites).floor[10] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_10.xpm", &i, &i);
	(*sprites).floor[11] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Floor/floor_11.xpm", &i, &i);
}

static void	ft_wall_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).wall = malloc(sizeof(void *) * 6);
	(*sprites).wall[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_0.xpm", &i, &i);
	(*sprites).wall[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_1.xpm", &i, &i);
	(*sprites).wall[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_2.xpm", &i, &i);
	(*sprites).wall[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_3.xpm", &i, &i);
	(*sprites).wall[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_4.xpm", &i, &i);
	(*sprites).wall[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_5.xpm", &i, &i);
}

static void	ft_collect_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).collect = malloc(sizeof(void *) * 2);
	(*sprites).collect[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Collect/bag_coins.xpm", &i, &i);
	(*sprites).collect[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Collect/key_silver.xpm", &i, &i);
}

static void	ft_border_sprites(t_sprites *sprites, void *mlx, int i)
{
	(*sprites).border = malloc(sizeof(void *) * 10);
	(*sprites).border[0] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_bottom_inner_left.xpm", &i, &i);
	(*sprites).border[1] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_bottom_inner_right.xpm", &i, &i);
	(*sprites).border[2] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_bottom.xpm", &i, &i);
	(*sprites).border[3] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_inner_left_2.xpm", &i, &i);
	(*sprites).border[4] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_inner_left.xpm", &i, &i);
	(*sprites).border[5] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_inner_right_2.xpm", &i, &i);
	(*sprites).border[6] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_inner_right.xpm", &i, &i);
	(*sprites).border[7] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_left.xpm", &i, &i);
	(*sprites).border[8] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top_right.xpm", &i, &i);
	(*sprites).border[9] = mlx_xpm_file_to_image(mlx, \
	"Sprites/Wall/wall_top.xpm", &i, &i);
}
