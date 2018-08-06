# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 18:14:32 by dkliukin          #+#    #+#              #
#    Updated: 2017/12/07 18:14:35 by dkliukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c drow_line.c validate.c del_double_arr.c set_begin.c\
drow_map.c ft_atoi_base.c key_manip.c mouse_manip.c read_file.c\
rotate.c window_draw.c

OBJ = $(SRC:%.c=%.o)
INC = fdf.h
NAME = fdf
CFLAG = -Werror -Wextra -Wall
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
LIBDIR = ./libft
CC = gcc

%.o: %.c $(INC)
		@$(CC) $(CFLAG) -c -Ofast $< -I $(LIBDIR)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBDIR)
		@$(CC) $(CFLAG) -Ofast -o $(NAME) $(OBJ) $(LIBDIR)/libft.a $(FRAMEWORK)

clean:
		@make clean -C $(LIBDIR)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)

re: fclean all