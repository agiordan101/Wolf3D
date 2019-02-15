 **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/16 17:11:58 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/15 14:28:17 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

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
LIB1_PATH = libft
LIB1 = $(LIB1_PATH)/$(LIB1_PATH).a

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB1_PATH)
		$(CC) $(FLAGS) $(LIB1) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) $(PPFLAGS) -c $< -o $@

clean:
		make clean -C $(LIB1_PATH)
		@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C $(LIB1_PATH)
		rm -f $(NAME)

re: fclean all

norme:
		@norminette $(LIB1_PATH)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re
