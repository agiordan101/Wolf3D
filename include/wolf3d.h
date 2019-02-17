/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:12:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/17 05:22:09 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define VEL 0.05

# include <stdio.h>
# include <stdlib.h>
//# include <SDL.h>
# include "../libft/libft.h"
# include "../libmath/include/libmath.h"

/*
**	dir: Direction de la camera en radian
**	fov: Angle de vision du personnage en radian
*/

typedef struct		s_player
{
	t_dot_2d		pos;
	t_vector_2d		vel;
	double			dir;
	double			fov;
}					t_player;

typedef struct		s_calculs
{
	t_vector_2d		vectors;
	double			a;
	double			b;
	double			*dist;
	int				i;
}					t_calculs;

typedef struct		s_map
{
	int				**tab;
	int				*len_x;
	int				len_y;
	int				width;
	int				height;
}					t_map;

typedef struct		s_win
{
	t_map			map;
	t_calculs		calculs;
	t_player		player;
}					t_win;

int					parser(int const fd, t_map *map);
int					parser_error(int error);
int					sum_x(t_map *map, int ilen);
int					collision(t_player *player, t_map map);
int					open_window();
		
void				raycasting(t_map *map, t_player *player, t_calculs *calculs);

#endif
