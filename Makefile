# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 20:44:40 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

SRCS_PATH =		src
SRCS_PATH_1 =	parsing
SRCS_PATH_2 =	physics
SRCS_PATH_3 =	window
SRCS_PATH_4 =	map_editor
SRCS_FILES =	main.c \
				$(SRCS_PATH_1)/parser.c \
				$(SRCS_PATH_1)/parser_error.c \
				$(SRCS_PATH_2)/collision.c \
				$(SRCS_PATH_2)/raycasting.c \
				$(SRCS_PATH_2)/sum_x.c \
				$(SRCS_PATH_3)/open_window.c \
				$(SRCS_PATH_3)/window_loop.c \
				$(SRCS_PATH_3)/draw.c \
				$(SRCS_PATH_3)/draw_rect.c \
				$(SRCS_PATH_3)/line_put.c \
				$(SRCS_PATH_3)/quit.c \
				$(SRCS_PATH_4)/map_editor.c \
				$(SRCS_PATH_4)/put_map.c
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJ = $(SRCS:%.c=%.o)

INCLUDE_PATH = include
CC = gcc
CFLAGS += -Wall -Wextra -Werror -I./$(INCLUDE_PATH)

LIB1 = libft
LIB2 = libmath
LIB3 = SDL/lib/LIBSDL2.a SDL/lib/LIBSDL2main.a
LIBSDL2 = `sdl2-config --cflags --libs`

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB1)
	make -C $(LIB2)
	$(CC) $(CFLAGS) $(OBJ) $(LIB1)/$(LIB1).a $(LIB2)/$(LIB2).a $(LIB3) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB1)
	make clean -C $(LIB2)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB1)
	make fclean -C $(LIB2)

re: fclean all

norme:
		@norminette $(LIB1)
		@norminette $(LIB2)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, fclean, re
