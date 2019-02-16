/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:12:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:38:55 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libmath/include/libmath.h"

typedef struct		s_player
{
	double			x;
	double			y;
	t_vector_2d		vel_x;
	t_vector_2d		vel_y;
}					t_player;

typedef struct	s_calculs
{
	vector_2d		vectors;
	double			*dist;
}					t_calculs;

typedef struct		s_map
{
	int				*tab;
	int				*len_x;
	int				width;
	int				height;
}					t_map;

typedef struct		s_win
{
	t_map			map;
	t_calculs		calculs;
}					t_win;

int					parser(int const fd, t_map *map);
int					parser_error(int error);

void				calcul_dist(t_map *map, t_calculs *calculs);

#endif
