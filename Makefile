#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 15:23:05 by kprytkov          #+#    #+#              #
#    Updated: 2018/05/22 15:23:06 by kprytkov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc
FLAG = -Wall -Werror -Wextra

SRC = fdf.c error_manager.c bresenham_line.c actions.c \
	ft_atoi_base.c ft_split.c get_next_line.c next_drawing.c \
	reader.c transformations.c

INCLUDE = ./includes

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) -I$(INCLUDE) $(SRC) -lmlx -framework OpenGL -framework Appkit ./libft/libft.a -o $(NAME)
	# ar rc $(NAME) $(SRO)

%.o: %.c ./includes/fdf.h
	$(CC) $(FLAG) -c -Wextra -Wall -Werror -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all

	