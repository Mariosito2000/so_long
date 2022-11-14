/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soulong.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:08:28 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/11 13:34:05 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void			ft_print_map(char **map);
*/
#ifndef SOULONG_H
# define SOULONG_H

# include <math.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../Libft/miniLibft/libft.h"
# include "../Libft/get_next_line/get_next_line.h"
# include "../Libft/ft_printf/ft_printf.h"

typedef struct s_sprites {
	char	**floor_map;
	char	**deco_map;
	char	**border_map;
	void	**floor;
	void	**wall;
	void	**door;
	void	**player;
	void	**deco;
	void	**collect;
	void	**border;
}				t_sprites;

typedef struct s_thing {
	char	*sprite_path;
	int		frame;
	int		x;
	int		y;
}				t_thing;

/*
Map generator
*/
char		**ft_gen_map(int fd);
char		**ft_copy_map(char **map);
char		**ft_update_map(char **map, char *temp, size_t size);
/*
Map checkers
*/
int			ft_check_map(char **map);
int			ft_check_path(char **map);
/*
Secondary maps generators
*/
char		**ft_build_deco(char **map);
char		**ft_build_floor(char **map);
//char		**ft_build_border(char **map);
/*
Image generators (Sprites)
*/
void		ft_save_sprites(char **map, t_sprites *sprites, void *mlx);
void		ft_door_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_extra_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_player_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_deco_sprites(t_sprites *sprites, void *mlx, int i);
/*
Printing function (Illegal)
*/
void		ft_print_map(char **map);

#endif
