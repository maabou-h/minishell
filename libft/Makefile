# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 18:42:02 by maabou-h          #+#    #+#              #
#    Updated: 2019/02/24 19:04:40 by maabou-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
		   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
		   ft_memset.c ft_power.c ft_putchar.c ft_putchar_fd.c ft_putendl.c\
		   ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
		   ft_putstr_fd.c ft_snbrlen.c ft_sqrt.c ft_strcat.c ft_strchr.c\
		   ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
		   ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
		   ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
		   ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
		   ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c\
		   ft_strtrim.c ft_tolower.c ft_toupper.c ft_unbrlen.c get_next_line.c\
		   ft_free_arr.c ft_splitwhitespaces.c
NAME = libft.a
CC = clang
CFLAGS = -Iincludes -g3 -Werror -Wall -Wextra
OBJ_PATH = .obj
ARG ?= $N

OBJ_NAME = $(SRC_NAME:%.c=%.o)
	SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rfv $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
