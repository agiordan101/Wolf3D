# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/03/14 17:49:11 by gmonacho    ###    #+. /#+    ###.fr      #
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
				error.c \
				$(SRCS_PATH_1)/parser.c \
				$(SRCS_PATH_1)/flags.c \
				$(SRCS_PATH_2)/collision.c \
				$(SRCS_PATH_2)/raycasting.c \
				$(SRCS_PATH_3)/open_window.c \
				$(SRCS_PATH_3)/window_loop.c \
				$(SRCS_PATH_3)/events.c \
				$(SRCS_PATH_3)/draw.c \
				$(SRCS_PATH_3)/draw_shapes.c \
				$(SRCS_PATH_3)/put_minimap.c \
				$(SRCS_PATH_3)/quit.c \
				$(SRCS_PATH_3)/compass.c \
				$(SRCS_PATH_3)/surface.c \
				$(SRCS_PATH_4)/map_editor.c \
				$(SRCS_PATH_4)/ed_window_loop.c \
				$(SRCS_PATH_4)/ed_put_map.c \
				$(SRCS_PATH_4)/ed_add_tile.c \
				$(SRCS_PATH_4)/ed_is_in_map.c \
				$(SRCS_PATH_4)/ed_export.c \
				$(SRCS_PATH_4)/ed_put_grid.c \
				$(SRCS_PATH_4)/ed_draw.c \
				$(SRCS_PATH_4)/ed_ui.c \
				$(SRCS_PATH_4)/ed_map_ui.c \
				$(SRCS_PATH_4)/ed_drag.c \
				$(SRCS_PATH_4)/ed_resize_x.c \
				$(SRCS_PATH_4)/ed_resize_y.c \
				$(SRCS_PATH_4)/ed_zoom.c \
				$(SRCS_PATH_4)/ed_pevent.c \
				$(SRCS_PATH_4)/ed_update_map_ui.c \
				$(SRCS_PATH_4)/ed_events.c
				#$(SRCS_PATH_4)/ui.c

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJS_PATH = obj
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))

INCLUDES_PATH = include
FW_PATH = ./frameworks
CC = gcc
CFLAGS += -Wall -Wextra -Werror -g -fsanitize=address -O3 -I./$(INCLUDES_PATH)\
			-I$(FW_PATH)/SDL2_image.framework/Headers/\
			-I$(FW_PATH)/SDL2_ttf.framework/Headers/\
			-I$(FW_PATH)/SDL2.framework/Headers/

LIBFT = libft
LIBMATH = libmath
LIBSDL2 = -framework SDL2 -F $(FW_PATH) -framework SDL2_image -framework SDL2_ttf -rpath $(FW_PATH)
LIBRARIES = $(LIBFT)/$(LIBFT).a $(LIBMATH)/$(LIBMATH).a $(LIBSDL2)

all:	directory $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		make -C $(LIBMATH)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/$(SRCS_PATH_1)/%.o : $(SRCS_PATH)/$(SRCS_PATH_1)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/$(SRCS_PATH_2)/%.o : $(SRCS_PATH)/$(SRCS_PATH_2)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/$(SRCS_PATH_3)/%.o : $(SRCS_PATH)/$(SRCS_PATH_3)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH)/$(SRCS_PATH_4)/%.o : $(SRCS_PATH)/$(SRCS_PATH_4)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

directory:
				@mkdir $(OBJS_PATH) 2> /dev/null || true
				@mkdir $(OBJS_PATH)/$(SRCS_PATH_1) 2> /dev/null || true
				@mkdir $(OBJS_PATH)/$(SRCS_PATH_2) 2> /dev/null || true
				@mkdir $(OBJS_PATH)/$(SRCS_PATH_3) 2> /dev/null || true
				@mkdir $(OBJS_PATH)/$(SRCS_PATH_4) 2> /dev/null || true

clean:
	rm -rf $(OBJS_PATH)
	make clean -C $(LIBFT)
	make clean -C $(LIBMATH)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMATH)

re:	fclean all

norme:
		@norminette $(LIBFT)
		@norminette $(LIBMATH)
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDES_PATH)

.PHONY: all, clean, fclean, re, directory, norme
