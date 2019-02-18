# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/06 19:11:00 by gmonacho     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 18:54:58 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3d

SRCS_PATH = src
SRCS_PATH_1 = parsing
SRCS_PATH_2 = window
SRCS_PATH_3 = map_editor
SRCS_PATH_4 = physics

SRCS_FILES =	main.c \
				$(SRCS_PATH_1)/parser.c \
				$(SRCS_PATH_1)/parser_error.c \
				$(SRCS_PATH_2)/open_window.c \
				$(SRCS_PATH_2)/window_loop.c \
				$(SRCS_PATH_2)/draw.c \
				$(SRCS_PATH_2)/draw_rect.c \
				$(SRCS_PATH_2)/line_put.c \
				$(SRCS_PATH_2)/quit.c \
				$(SRCS_PATH_3)/map_editor.c \
				$(SRCS_PATH_4)/collision.c \
				$(SRCS_PATH_4)/raycasting.c \
				$(SRCS_PATH_4)/sum_x.c 
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS))

OBJS_PATH = obj
OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDE_PATH = include
PPFLAGS = -I./$(INCLUDE_PATH)

LIB1 = libft
LIB2 = libmath
LIBSDL2 = `sdl2-config --cflags --libs`
LIBRARIES = $(LIB1)/$(LIB1).a $(LIB2)/$(LIB2).a $(LIBSDL2)


all: $(NAME)

$(NAME): $(LIB1) $(LIB2) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) $(LIBRARIES) -o $(NAME)

$(LIB1):
	make -C $@

$(LIB2):
	make -C $@

$(OBJ_PATH)/$(SRCS_PATH_1)/%.o : $(SRCS_PATH)/$(SRCS_PATH_1)/%.c
		@mkdir $(OBJ_PATH)/$(SRCS_PATH_1) 2> /dev/null || true
		$(CC) $(FLAGS) $(PPFLAGS) -c $< -o $@

clean:
		make clean -C $(LIB1)
		make clean -C $(LIB2)
		@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C $(LIB1)
		make fclean -C $(LIB2)
		rm -f $(NAME)

re: fclean all

norme:
		@norminette $(LIB1)
		@norminette $(LIB2)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re