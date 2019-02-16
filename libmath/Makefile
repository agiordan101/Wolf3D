# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/16 17:11:58 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/15 20:05:40 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libmath

SRC_PATH = srcs
SRC_FILES = add_vector_2d.c \
			add_vector_3d.c \
			del_dot_2d.c \
			del_dot_3d.c \
			del_vector_2d.c \
			del_vector_3d.c \
			dist_dot_2d.c \
			dist_dot_3d.c \
			dist_origin_dot_2d.c \
			dist_origin_dot_3d.c \
			ft__abs.c \
			ft__sqrt.c \
			ft_divmod.c \
			ft_dtoi_low.c \
			ft_dtoi_up.c \
			ft_dtorad.c \
			ft_exp.c \
			ft_factorial.c \
			ft_modulo.c \
			ft_power.c \
			ft_radtod.c \
			ft_square.c \
			mag_vector_2d.c \
			mag_vector_3d.c \
			new_dot_2d.c \
			new_dot_3d.c \
			new_vector_2d.c \
			new_vector_3d.c \
			normalize_vector_2d.c \
			normalize_vector_3d.c \
			rand_dot_2d.c \
			rand_dot_3d.c \
			rand_vector_2d.c \
			rand_vector_3d.c \
			scalar_product_2d.c \
			scalar_product_3d.c \
			set_mag_vector_2d.c \
			set_mag_vector_3d.c \
			sub_vector_2d.c \
			sub_vector_3d.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_PATH = obj
OBJ_NAME = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

CC = gcc
INCLUDE_PATH = include
PPFLAGS = -I ./$(INCLUDE_PATH)
FLAGS = -Wall -Werror -Wextra $(PPFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME).a $(OBJ)
		ranlib $(NAME).a

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
		rm -f $(NAME).a

re: fclean all

norme:
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re, norme
