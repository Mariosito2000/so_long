/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_save_sprites2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:30:06 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/24 15:39:29 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soulong.h"

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
