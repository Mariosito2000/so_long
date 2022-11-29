# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 10:17:43 by marias-e          #+#    #+#              #
#    Updated: 2022/11/29 10:39:34 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard */*.c)

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

O_DIR	=	Objs

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	libft.a

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $(O_DIR)/${<:.c=.o} -I.

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
