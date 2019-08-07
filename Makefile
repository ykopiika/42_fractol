# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:10:54 by ykopiika          #+#    #+#              #
#    Updated: 2019/04/26 16:29:22 by ykopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

MLX_FL = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./inc/

LIB_DIR = ./libft/

SRC = main.c\
	  f_error.c\
	  f_hook.c\
	  f_fractals_a.c\
	  f_fractals_b.c\
	  f_key_press.c\
	  f_print_frtl.c\
	  f_value_frtl.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft $(MLX_FL)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)%.o: %.c
	@gcc -c $(FLAGS) $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft/ clean

fclean: clean	
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

vpath %.c $(SRC_DIR)
