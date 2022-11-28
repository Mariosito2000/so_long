/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:39 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:48 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Generar mapa,
generar mapa deco,
pintar mapa (mapa deco),
pintar items, jugador y puerta (mapa),
jugar (mapa)
*/
#include "soulong_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_exit(3);
	ft_check_ber(argv[1]);
	game.sprites.torch = 0;
	game.sprites.base_map = ft_gen_map(open(argv[1], O_RDONLY));
	ft_check_map(game.sprites.base_map);
	ft_check_path(game.sprites.base_map);
	ft_save_sprites(&game.sprites, &game.mlx);
	ft_initialize_player(&game.player, game.sprites.base_map);
	ft_initialize_torch(game.sprites.deco_map, &game.sprites.torch);
	ft_create_window(game.sprites.base_map, &game.mlx);
	ft_paint_base(game.sprites.deco_map, game.mlx, game.sprites);
	ft_paint_deco(game.sprites.deco_map, game.mlx, game.sprites);
	ft_paint_borders(game.mlx, game.sprites);
	ft_paint_collectibles(game.sprites.deco_map, game);
	mlx_loop_hook(game.mlx.mlx, ft_render_game, &game);
	mlx_loop(&game.mlx.mlx);
}

/*
void	ft_print_map(char **map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			write(1, &map[j][i], 1);
			i++;
		}
		j++;
	}
	write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 20);
	usleep(40000);
}
*/
