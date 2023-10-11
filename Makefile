# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbach <bbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 16:59:07 by bbach             #+#    #+#              #
#    Updated: 2023/10/11 19:03:02 by bbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = minishell

LIB = ./includes/libft_Bbach/libft/libft.a

CC = gcc 

CFLAGS = -Wall -Werror -Wextra -g

all: ${LIB} $(NAME)

${LIB} : 
	make -s -C ./includes/libft_Bbach/ all

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) ${LIB}
	@${CC} ${CFLAGS} $(OBJS) -L./includes/libft_Bbach -lft -lreadline -o $(NAME)
	@echo "\033[32mCompilation done !\033[0m"

clean:
		@${RM} ${OBJS}
		@make -s -C ./includes/libft_Bbach/ clean
		@echo "\033[32mObjects deleted !\033[0m"

fclean: clean
		@${RM} ${NAME}
		@make -s -C ./includes/libft_Bbach/ fclean

re : fclean all

.PHONY: all clean fclean re