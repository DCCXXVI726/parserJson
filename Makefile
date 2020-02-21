# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deladia <deladia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 20:57:04 by deladia           #+#    #+#              #
#    Updated: 2020/02/21 16:33:18 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtojson.a
HEADERS = includes/to_json.h
INC = -I ./includes \
	  -I $(LIB_DIR)/includes
SRC = ft_is_smth.c check_value.c helps.c realloc_key_value.c get_smth.c \
	  get_smth2.c parse_json.c tree.c ft_error.c make_smth.c parser.c \
	  ft_return.c creation_token_list.c
LIB = -L $(LIB_DIR)/ -lft

SRC_DIR = src
OBJ_DIR = object
LIB_DIR	= libft

FLAG = -Wall -Wextra -Werror
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

.PHONY : all clean fclean lib_ft re test

$(NAME): $(OBJ_DIR) $(OBJ) 
		@make lib_ft
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32m"Libtojson ready

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
		@$(CC) $(FLAG) $(INC) -c $< -o $@

lib_ft:
		@make -C $(LIB_DIR)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@make -C $(LIB_DIR)/ clean
		@rm -rf $(OBJ_DIR)
		@echo "\033[32m"Clear
		
fclean: clean
		@rm -f $(OBJ)
		@make -C $(LIB_DIR)/ fclean
		@rm -f $(NAME)
		@echo "\033[32m"All Clear

re: fclean all

test:
	gcc $(FLAG) main.c $(INC) $(LIB) -L ./ -ltojson -o test.out
