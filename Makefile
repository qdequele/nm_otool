# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:29:39 by qdequele          #+#    #+#              #
#    Updated: 2018/01/25 13:39:45 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	ft_nm

_SRC		=	archi.c \
				env.c \
				file.c \
				ft_nm.c \
				lc_32.c \
				lc_64.c \
				symbol.c

_INC		=	ft_nm.h

SRC			=	$(addprefix src/,$(_SRC))
INC			=	$(addprefix include/,$(_INC))

LIB			=	./libft/libft.a
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./include/ -I./libft/

%.o: %.c
	@echo -n .
	@$gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo $(NAME) " - compiled"

clean:
	@/bin/rm -rf $(OBJ)
	@make clean -C libft
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@/bin/rm -rf $(NAME)
	@make fclean -C libft
	@echo $(NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re
