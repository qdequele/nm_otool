# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:29:39 by qdequele          #+#    #+#              #
#    Updated: 2018/02/12 14:00:41 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		=	ft_nm

_SRC		=	ft_nm.c \
				sort.c \
				convert.c \
				parsing/archives.c \
				parsing/fat.c \
				parsing/header.c \
				parsing/load_command.c \
				parsing/nlist.c \
				parsing/section_command.c \
				parsing/symbol_type.c \
				types/env.c \
				types/file.c \
				types/group.c \
				types/section.c \
				types/symbol.c

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
