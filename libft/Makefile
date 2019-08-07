# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/03 19:59:32 by ykopiika          #+#    #+#              #
#    Updated: 2018/11/28 14:32:25 by ykopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SOURCE = ft_atoi.c\
		 ft_bzero.c\
		 ft_check_sp.c\
		 ft_isalnum.c\
		 ft_isalpha.c\
		 ft_isascii.c\
		 ft_isdigit.c\
		 ft_isprint.c\
		 ft_itoa.c\
		 ft_lstnew.c\
		 ft_lstdelone.c\
		 ft_lstdel.c\
		 ft_lstadd.c\
		 ft_lstiter.c\
		 ft_lstmap.c\
		 ft_len_int.c\
		 ft_lstmapone.c\
		 ft_memset.c\
		 ft_memcpy.c\
		 ft_memccpy.c\
		 ft_memmove.c\
		 ft_memchr.c\
		 ft_memcmp.c\
		 ft_memalloc.c\
		 ft_memdel.c\
		 ft_putchar.c\
		 ft_putstr.c\
		 ft_putendl.c\
		 ft_putnbr.c\
		 ft_putchar_fd.c\
		 ft_putstr_fd.c\
		 ft_putendl_fd.c\
		 ft_putnbr_fd.c\
		 ft_sp_beg.c\
		 ft_sp_end.c\
		 ft_strlen.c\
		 ft_strcpy.c\
		 ft_strncpy.c\
		 ft_strcat.c\
		 ft_strncat.c\
		 ft_strlcat.c\
		 ft_strchr.c\
		 ft_strrchr.c\
		 ft_strstr.c\
		 ft_strnstr.c\
		 ft_strcmp.c\
		 ft_strncmp.c\
		 ft_strdup.c\
		 ft_strnew.c\
		 ft_strdel.c\
		 ft_strclr.c\
		 ft_striter.c\
		 ft_striteri.c\
		 ft_strmap.c\
		 ft_strmapi.c\
		 ft_strequ.c\
		 ft_strnequ.c\
		 ft_strsub.c\
		 ft_strsplit.c\
		 ft_strjoin.c\
		 ft_strtrim.c\
		 ft_toupper.c\
		 ft_tolower.c\
		 get_next_line.c\

OBJ = $(SOURCE:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
