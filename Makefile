# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:29:39 by qdequele          #+#    #+#              #
#    Updated: 2018/02/14 15:19:20 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NM_NAME		=	ft_nm
OTOOL_NAME	=	ft_otool

_SRC		=	sort.c \
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

NM_SRC		=	$(addprefix src/,$(_SRC)) src/ft_nm.c
OTOOL_SRC	=	$(addprefix src/,$(_SRC)) src/ft_otool.c
INC			=	$(addprefix include/,$(_INC))

LIB			=	./libft/libft.a

NM_OBJ		=	$(NM_SRC:.c=.o)
OTOOL_OBJ	=	$(OTOOL_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ./include/ -I./libft/

%.o: %.c
	@echo -n .
	@$gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NM_NAME) $(OTOOL_NAME)

$(NM_NAME): $(NM_OBJ)
	@make -C ./libft/
	@gcc $(CFLAGS) $(NM_OBJ) $(LIB) -o $(NM_NAME)
	@echo $(NM_NAME) " - compiled"

$(OTOOL_NAME): $(OTOOL_OBJ)
	@make -C ./libft/
	@gcc $(CFLAGS) $(OTOOL_OBJ) $(LIB) -o $(OTOOL_NAME)
	@echo $(OTOOL_NAME) " - compiled"

clean:
	@/bin/rm -rf $(NM_OBJ) $(OTOOL_OBJ)
	@make clean -C libft
	@echo $(NM_NAME) " - Clean all .o files"

fclean: clean
	@/bin/rm -rf $(NM_NAME) $(OTOOL_NAME)
	@make fclean -C libft
	@echo $(NM_NAME) " " $(OTOOL_NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re
