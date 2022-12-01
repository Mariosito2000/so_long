# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 11:34:57 by marias-e          #+#    #+#              #
#    Updated: 2022/12/01 11:43:05 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Sources/ft_aux_save_sprites.c \
Sources/ft_aux_save_sprites2.c \
Sources/ft_build_deco.c \
Sources/ft_build_floor.c \
Sources/ft_check_ber.c \
Sources/ft_check_map.c \
Sources/ft_check_path.c \
Sources/ft_gen_map.c \
Sources/ft_initialize.c \
Sources/ft_inputs.c \
Sources/ft_manage_collect.c \
Sources/ft_paint.c \
Sources/ft_paint_2.c \
Sources/ft_player_anim.c \
Sources/ft_render_map.c \
Sources/ft_save_sprites.c \
Sources/main.c

SRCS_BONUS	=	Sources_bonus/ft_aux_save_sprites2_bonus.c \
Sources_bonus/ft_aux_save_sprites_bonus.c \
Sources_bonus/ft_build_deco_bonus.c \
Sources_bonus/ft_build_floor_bonus.c \
Sources_bonus/ft_check_ber_bonus.c \
Sources_bonus/ft_check_map_bonus.c \
Sources_bonus/ft_check_path_bonus.c \
Sources_bonus/ft_gen_map_bonus.c \
Sources_bonus/ft_initialize_bonus.c \
Sources_bonus/ft_inputs_bonus.c \
Sources_bonus/ft_manage_collect_bonus.c \
Sources_bonus/ft_paint_2_bonus.c \
Sources_bonus/ft_paint_bonus.c \
Sources_bonus/ft_player_anim_bonus.c \
Sources_bonus/ft_render_map_bonus.c \
Sources_bonus/ft_save_sprites_bonus.c \
Sources_bonus/main_bonus.c

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(O_DIR)/, $(SRCS_BONUS:.c=.o))

O_DIR	=	Objs

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	so_long

NAME_BONUS	=	so_long_bonus

L_DIR	=	Libft/

LIBFT	=	$(addprefix $(L_DIR), libft.a)

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/${<:.c=.o} -I

all:		$(LIBFT) ${NAME}

bonus:		$(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@make -C $(L_DIR)

${NAME}:	${OBJS}
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(NAME_BONUS):	$(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(LIBFT)

clean:
		rm -rf ${O_DIR} && cd $(L_DIR) && $(MAKE) clean

fclean:		clean
		rm -rf ${O_DIR} && cd $(L_DIR) && $(MAKE) fclean

re:		fclean all

run:	all
		./so_long "mapa.ber"

.PHONY:	all clean fclean re run bonus
