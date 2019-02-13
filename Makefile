# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/16 17:11:58 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/13 18:48:20 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = srcs
SRC_FILES = main.c \
			parser.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_PATH = obj
OBJ_NAME = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
PPFLAGS = -Iinclude

INCLUDE_PATH = include
LIB = libft/libft.a
LIB1 = libft

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB1)
		$(CC) $(FLAGS) $(LIB) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) $(PPFLAGS) -c $< -o $@

clean:
		make clean -C $(LIB1)
		@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C $(LIB1)
		make fclean -C $(LIB2)
		rm -f $(NAME)
		rm -f launcher

re: fclean all

norme:
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re
