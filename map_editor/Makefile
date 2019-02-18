# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 14:10:53 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = map_editor

SRC_PATH = src
SRC_FILES = main.c \
			parser.c\
			parser_error.c \
			open_window.c \
			window_loop.c \
			quit.c \
			put_map.c \
			line_put.c \
			draw_rect.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_PATH = obj
OBJ_NAME = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
PPFLAGS = -Iinclude

INCLUDE_PATH = include
LIB1_PATH = libft
LIBRARIES = ../$(LIB1_PATH)/$(LIB1_PATH).a `sdl2-config --cflags --libs`

all: $(NAME)

$(NAME): $(OBJ)
		make -C ../$(LIB1_PATH)
		$(CC) $(FLAGS) $(LIBRARIES) $^ -o $@

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) $(PPFLAGS) -c $< -o $@

clean:
		make clean -C ../$(LIB1_PATH)
		@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C ../$(LIB1_PATH)
		rm -f $(NAME)

re: fclean all

norme:
		@norminette ../$(LIB1_PATH)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re
