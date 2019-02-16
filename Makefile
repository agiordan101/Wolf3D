# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/16 22:58:37 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

SRC_PATH = srcs
SRC_FILES = main.c \
			parser.c \
			raycasting.c \
			get_y.c \
			collision.c
SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_PATH = obj
OBJ_NAME = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
PPFLAGS = -Iinclude

INCLUDE_PATH = include
LIB1_PATH = libft
LIB2_PATH = libmath
LIBRARIES = $(LIB1_PATH)/$(LIB1_PATH).a $(LIB2_PATH)/$(LIB2_PATH).a 

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB1_PATH)
		make -C $(LIB2_PATH)
		$(CC) $(FLAGS) $(LIBRARIES) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) $(PPFLAGS) -c $< -o $@

clean:
		make clean -C $(LIB1_PATH)
		make clean -C $(LIB2_PATH)
		@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C $(LIB1_PATH)
		make fclean -C $(LIB2_PATH)
		rm -f $(NAME)

re: fclean all

norme:
		@norminette $(LIB1_PATH)
		@norminette $(LIB2_PATH)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re
