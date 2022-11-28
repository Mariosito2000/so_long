# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 11:34:57 by marias-e          #+#    #+#              #
#    Updated: 2022/11/24 12:37:15 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard Sources/*.c)

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

O_DIR	=	Objs

CC	=	gcc -Wall -Wextra -Werror -g

NAME 	=	so_long

L_DIR	=	Libft

LIBFT	=	libft.a

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/${<:.c=.o} -I

${NAME}:	${OBJS}
		@make -C $(L_DIR)
		@$(CC) $(L_DIR)/$(LIBFT) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
all:		${NAME}

clean:
		rm -f ${OBJS} && cd $(L_DIR) && $(MAKE) clean

fclean:		clean
		rm -f ${NAME} && cd $(L_DIR) && $(MAKE) fclean

re:		fclean all

run:	all
		./so_long "mapa.ber"

.PHONY:	all clean fclean re run
