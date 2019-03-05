/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:12:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/05 15:43:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define VEL 0.05
# define WALL_R 0x50
# define WALL_G 0xAA
# define WALL_B 0x50
# define BACK_R 100
# define BACK_G 100
# define BACK_B 100

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
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
	t_dot_2d 		box;
}					t_player;

typedef struct		s_calculs
{
	double			angle;
	t_vector_2d		vectors;
	double			a;
	double			b;
	double			*dist;
	double			*xray;
	int				i;
}					t_calculs;

typedef struct 		s_minimap
{
	int 			x;
	int				y;
	int				width;
	int 			height;
	int				x_unit;
	int				y_unit;
	int				static_map;
}					t_minimap;

typedef struct		s_texture
{
	SDL_Surface		*mur;
}					t_texture;

typedef struct		s_map
{
	int				**tab;
	int				len_x;
	int				len_y;
	int				unit;
	int				tile;
	t_minimap		minimap;
}					t_map;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	TTF_Font		*police;
	SDL_Surface		*texte;
	t_map			map;
	t_texture		textures;
	t_player		player;
	char			*name;
	int				choice;
	int				fd;
	int				width;
	int				height;
	t_dot_2d		pos;
	t_calculs		calculs;
}					t_win;


void				draw_rect(t_win *win, t_dot_2d pos, int width, int height);
void				draw_empty_rect(t_win *win, t_dot_2d pos, int width, int height);
void				draw_line(t_win *win, t_dot_2d p1, t_dot_2d p2, SDL_Renderer *image);
void				draw_txt(t_win *win, char *txt, SDL_Color color, SDL_Rect rect);
void				draw(t_win *win, t_calculs *calculs);
void				draw_compass(t_win *win);
void				calcul_compass(t_win *win);

int					ed_add_tile(int	x, int y, t_win *win, int tile);
int 				ed_export(t_map map);
int					ed_is_in_map(int x, int y, t_win *win);
void				ed_put_grid(t_win *win);
int 				ed_put_map(t_win *win);
int					ed_window_loop(t_win *win);
int					pevent(t_win *win, SDL_Event event);
void				ed_keyboard_event(t_win *win);
void				ed_mouse_event(t_win *win);

int					parser(int const fd, t_map *map, t_player *player);
int					params(t_win *win, int ac, char **av);
int					map_editor(int fd);

int					open_window(t_win *win);
int					window_loop(t_win *win);
void				keyboard_state(t_player *player, t_win *win);
int					keyboard_event(t_win *win, SDL_Event event);

int 				put_minimap(t_win *win);
int					error(int error, char *error_source);
int					wolf3d_exit(t_win *win);
int					quit(t_win *win);

void				raycasting(t_win *win, t_map *map, t_player *player, t_calculs *calculs);
double				calcul_dist(t_map *map, t_player *player, t_calculs *calculs, t_vector_2d vector);
int					collision(t_map *map, t_player *player);

#endif
