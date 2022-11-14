/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:39 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/11 13:02:53 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Generar mapa,
generar mapa deco,
pintar mapa (mapa deco),
pintar items, jugador y puerta (mapa),
jugar (mapa)
*/
#include "soulong.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(int argc, char **argv)
{
	int		fd;
	char	**mapa;
	char	**deco;
	char	**floor;
/*
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*relative_path = "Sprites/Floor/floor_3.xpm";
	int		img_width;
	int		img_height;
	int		map_h = 0;
	int		map_w;
*/
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	mapa = ft_gen_map(fd);
	deco = ft_build_deco(mapa);
	ft_print_map(deco);
	floor = ft_build_floor(deco);
	ft_print_map(floor);
	/*
	while (mapa[map_h])
		map_h++;
	map_w = ft_strlen(mapa[0]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (map_w * 32) + 16, (map_h * 32) + 32, "PREBAS");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (map_h-- > 1)
	{
		map_w = ft_strlen(mapa[0]) - 1;
		while (map_w-- > 1)
			mlx_put_image_to_window(mlx, mlx_win, img, (map_w * 32), (map_h * 32));
	}
	map_h = 0;
	while (mapa[map_h])
		map_h++;
	map_w = ft_strlen(mapa[0]);
	img = mlx_xpm_file_to_image(mlx, "Sprites/Wall/table_2.xpm", &img_width, &img_height);
	while (map_h-- > 1)
	{
		map_w = ft_strlen(mapa[0]) - 1;
		while (map_w-- > 1)
			if (map_w % 4 == 1 && map_h % 2)
				mlx_put_image_to_window(mlx, mlx_win, img, (map_w * 32), (map_h * 32) + 16);
	}
	mlx_loop(mlx);
	*/
}

/*int	main(int argc, char **argv)
{
	int		fd;
	char	**mapa;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	mapa = ft_gen_map(fd);
}
*/


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

