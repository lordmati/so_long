# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 20:50:59 by misaguir          #+#    #+#              #
#    Updated: 2024/04/29 18:26:06 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER = misaguir

NAME = so_long

CC = gcc

CFLAGS = -Wextra -Wall -Werror -g

MLX42 = ./MLX42

LIBFT = ./Libft

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main check_errors utils_sl read_map so_long init_game #poner archivos

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists

MAKEFLAGS += -s

all: $(NAME)

$(NAME):    $(OBJ)
			@make all bonus printf gnl -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -frf $(OBJ_DIR)
			@make clean -C $(MLX42)
			@make -C $(LIBFT) clean

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -f $(NAME)
			@make fclean -C $(MLX42)
			@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re