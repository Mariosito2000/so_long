/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soulong.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:08:28 by marias-e          #+#    #+#             */
/*   Updated: 2022/12/01 11:44:32 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../Libft/miniLibft_sl/libft.h"
# include "../Libft/get_next_line_sl/get_next_line.h"
# include "../Libft/ft_printf_sl/ft_printf.h"

typedef struct s_torch {
	int				y;
	int				x;
	int				wall;
	int				frame;
}				t_torch;

typedef struct s_sprites {
	t_list	*torch;
	char	**base_map;
	char	**floor_map;
	char	**deco_map;
	void	**floor;
	void	**wall;
	void	**door;
	void	**player;
	void	**deco;
	void	**collect;
	void	**border;
}				t_sprites;

typedef struct s_mlx {
	int		map_w;
	int		map_h;
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_player{
	int		y;
	int		x;
	int		frame;
	int		dir;
	int		run;
	int		state;
	int		collect;
	int		steps;
	int		door;
	int		door_y;
	int		door_x;
}				t_player;

typedef struct s_game{
	t_player	player;
	t_mlx		mlx;
	t_sprites	sprites;
}				t_game;

/*
Map generator
*/
char		**ft_gen_map(int fd);
char		**ft_copy_map(char **map);
char		**ft_update_map(char **map, char *temp, size_t size);
void		ft_free_map(char **map);
/*
Map checkers
*/
void		ft_check_ber(char *str);
int			ft_check_map(char **map);
int			ft_check_path(char **map);
/*
Secondary maps generators
*/
char		**ft_build_deco(char **map);
char		**ft_build_floor(char **map);
/*
Initialize;
*/
void		ft_initialize_player(t_player *player, char	**map);
int			ft_count_obj(char **map);
int			*ft_locate_obj(char obj, char **map);
void		ft_initialize_torch(char **map, t_list **torch);
/*
Image generators (Sprites)
*/
void		ft_save_sprites(t_sprites *sprites, void *mlx);
void		ft_door_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_extra_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_extra_sprites2(t_sprites *sprites, void *mlx, int i);
void		ft_player_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_player_rev_sprites(t_sprites *sprites, void *mlx, int i);
void		ft_deco_sprites(t_sprites *sprites, void *mlx, int i);
/*
MLX
*/
void		ft_create_window(char	**map, t_mlx *mlx);
void		ft_paint_base(char	**map, t_mlx mlx, t_sprites sprites);
void		ft_paint_deco(char	**map, t_mlx mlx, t_sprites sprites);
void		ft_paint_floor(int	*yx, t_mlx mlx, t_sprites sprites);
void		ft_paint_borders(t_mlx mlx, t_sprites sprites);
void		ft_paint_collectibles(char **map, t_game game);
void		ft_paint_key(t_game game);
int			ft_render_game(t_game *game);
/*
Inputs
*/
int			ft_exit(int reason);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_up(t_game *game);
/*
Game manager
*/
void		ft_loot(t_game *game);
void		ft_open_door(t_game *game);
void		ft_player_anim(t_game *game);
/*
Printing function (Illegal)
*/
/*
void		ft_print_map(char **map);
*/

#endif
