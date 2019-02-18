# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 19:52:18 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

SRCS_PATH = src
SRCS_FILES = main.c \
	  window/open_window.c \
	  window/window_loop.c \
	  window/draw.c \
	  window/draw_rect.c \
	  window/line_put.c \
	  window/quit.c \
	  parsing/parser.c \
	  parsing/parser_error.c \
	  map_editor/map_editor.c \
	  physics/collision.c \
	  physics/raycasting.c \
	  physics/sum_x.c

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJ = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -I./include

LIBFT = libft/libft.a
LIBMATH = libmath/libmath.a
LIBSDL2 = `sdl2-config --cflags --libs`

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) $(LIBFT) $(LIBMATH) $(LIBSDL2) -o $(NAME)

$(LIBFT):
	make -C libft/

$(LIBMATH):
	make -C libmath/

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C libmath

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C libft

re: fclean all

.PHONY: all, clean, fclean, re