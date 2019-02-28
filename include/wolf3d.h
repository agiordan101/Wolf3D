/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:12:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 22:32:16 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define VEL 0.05
# define WALL_R 16
# define WALL_G 144
# define WALL_B 16
# define BACK_R 100
# define BACK_G 100
# define BACK_B 100

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../SDL/include/SDL2/SDL.h"
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
	double			const_vel;
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
	int				unit;
	int				tile;
}					t_map;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	t_map			map;
	t_player		player;
	int				width;
	int				height;
	t_dot_2d		pos;
	t_calculs		calculs;
}					t_win;

int					collision(t_player *player, t_map map);
void				draw(t_win *win, t_calculs *calculs);
void				draw_rect(t_win *win, int x, int y, int width, int height);
int					error(int error, char *error_source);
int					ed_add_tile(int	x, int y, t_win *win, int tile);
int 				ed_export(t_map map);
int					ed_is_in_map(int x, int y, t_win *win);
void				ed_put_grid(t_win *win);
int 				ed_put_map(t_win *win);
int					ed_window_loop(t_win *win);
void				line_put(t_win *win, t_dot_2d p1, t_dot_2d p2);
int					map_editor(int fd);
int					open_window(t_win *win);
int					parser(int const fd, t_map *map);
int					quit(t_win *win);
void				raycasting(t_win *win, t_map *map, t_player *player, t_calculs *calculs);
int					sum_x(t_map *map, int ilen);
int					window_loop(t_win *win);
int					wolf3d_exit(t_win *win);

#endif
