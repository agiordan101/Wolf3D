# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/06 19:11:00 by gmonacho     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 17:57:55 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

SRC = ./src/main.c \
	  ./src/window/close_window.c \
	  ./src/window/open_window.c \
	  ./src/window/window_loop.c \
	  ./src/window/refresh_window.c \
	  ./src/window/line_put.c \
	  ./src/window/draw_square.c \
	  ./src/event/key_press.c \
	  ./src/event/key_release.c \
	  ./src/event/key_event.c \
	  ./src/event/mouse_move.c \
	  ./src/event/mouse_press.c \
	  ./src/event/mouse_release.c \
	  ./src/event/mouse_drag.c \
	  ./src/event/mouse_event.c \
	  ./src/fractal/put_fractal.c \
	  ./src/fractal/set_julia.c \
	  ./src/fractal/set_mandelbrot.c \
	  ./src/fractal/put_square.c \
	  ./src/user_interface/key_info.c \
	  ./src/create_point.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

LIBFT = ./lib/libft/libft.a

LIBMATH = ./lib/libmath/libmath.a

LIBSDL2 = `sdl2-config --cflags --libs`

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) $(LIBFT) $(LIBMATH) $(LIBSDL2) -o $(NAME)

$(LIBFT):
	make -C ./lib/libft/

$(LIBMATH):
	make -C ./lib/libmath/

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C minilibx_macos

re: fclean all

.PHONY: all clean fclean re