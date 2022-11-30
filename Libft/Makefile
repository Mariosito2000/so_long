# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 10:17:43 by marias-e          #+#    #+#              #
#    Updated: 2022/11/30 17:45:59 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf/ft_printf.c \
ft_printf/ft_strlen.c \
ft_printf/ft_write_c.c \
ft_printf/ft_write_di.c \
ft_printf/ft_write_p.c \
ft_printf/ft_write_s.c \
ft_printf/ft_write_u.c \
ft_printf/ft_write_upx.c \
ft_printf/ft_write_x.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
miniLibft/ft_atoi.c \
miniLibft/ft_bzero.c \
miniLibft/ft_calloc.c \
miniLibft/ft_isalnum.c \
miniLibft/ft_isalpha.c \
miniLibft/ft_isascii.c \
miniLibft/ft_isdigit.c \
miniLibft/ft_isprint.c \
miniLibft/ft_itoa.c \
miniLibft/ft_lstadd_back_bonus.c \
miniLibft/ft_lstadd_front_bonus.c \
miniLibft/ft_lstclear_bonus.c \
miniLibft/ft_lstdelone_bonus.c \
miniLibft/ft_lstiter_bonus.c \
miniLibft/ft_lstlast_bonus.c \
miniLibft/ft_lstmap_bonus.c \
miniLibft/ft_lstnew_bonus.c \
miniLibft/ft_lstsize_bonus.c \
miniLibft/ft_memchr.c \
miniLibft/ft_memcmp.c \
miniLibft/ft_memcpy.c \
miniLibft/ft_memmove.c \
miniLibft/ft_memset.c \
miniLibft/ft_putchar_fd.c \
miniLibft/ft_putendl_fd.c \
miniLibft/ft_putnbr_fd.c \
miniLibft/ft_putstr_fd.c \
miniLibft/ft_split.c \
miniLibft/ft_strchr.c \
miniLibft/ft_strdup.c \
miniLibft/ft_striteri.c \
miniLibft/ft_strjoin.c \
miniLibft/ft_strlcat.c \
miniLibft/ft_strlcpy.c \
miniLibft/ft_strlen.c \
miniLibft/ft_strmapi.c \
miniLibft/ft_strncmp.c \
miniLibft/ft_strnstr.c \
miniLibft/ft_strrchr.c \
miniLibft/ft_strtrim.c \
miniLibft/ft_substr.c \
miniLibft/ft_tolower.c \
miniLibft/ft_toupper.c \

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
		rm -rf ${O_DIR}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
