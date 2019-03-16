# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 18:42:02 by maabou-h          #+#    #+#              #
#    Updated: 2019/03/16 16:22:07 by maabou-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = ft_getenv.c main.c msh_builtins.c msh_env.c msh_utils.c 

NAME = minishell

LDFLAGS = -Llibft

LDLIBS = -lft

CC = clang

CFLAGS = -Iincludes -Werror -Wall -Wextra

OBJ_PATH = .obj

ARG ?= $N

OBJ_NAME = $(SRC_NAME:%.c=%.o)
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
	SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ): includes/minishell.h

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	rm -rfv $(OBJ_PATH)

fclean: clean
	make fclean -C libft
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
