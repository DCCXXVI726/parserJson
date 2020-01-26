# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deladia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 14:55:00 by deladia           #+#    #+#              #
#    Updated: 2019/11/09 19:00:51 by deladia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./includes
INC_FILE = ./includes/libft.h ./includes/get_next_line.h
SRC_DIR = src
OBJ_DIR = object

SRC = ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
	ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
	ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c \
	ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c \
	ft_isalnum.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c ft_isalpha.c \
	ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c \
	ft_strcat.c ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c \
	ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c ft_strlen.c \
	ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_iterative_power.c ft_sqrt.c ft_is_negative.c ft_iterative_factorial.c \
	ft_range.c get_next_line.c ft_atof.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILE)
		@mkdir -p $(OBJ_DIR)
		$(CC) $(FLAG) $(INC) -c $< -o $@

clean:
		@/bin/rm -rf $(OBJ_DIR)
		
fclean: clean
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(NAME)

re: fclean $(NAME)
