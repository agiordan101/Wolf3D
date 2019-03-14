/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:12:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 17:49:36 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define VEL 0.05
# define HEIGHT_WALL 500
# define WALL_R 0x50
# define WALL_G 0xAA
# define WALL_B 0x50
# define BACK_R 100
# define BACK_G 100
# define BACK_B 100
# define ED_TDRAG 0
# define ED_RDRAG 1
# define ED_BDRAG 2
# define ED_LDRAG 3
# define NB_MAP_UI 4
# define ED_TILES 10
# define ED_TILE1 11
# define ED_TILE2 12
# define ED_TILE3 13
# define ED_TILE4 14
# define ED_TILE5 15
# define ED_TILE6 16
# define ED_TILE7 17
# define ED_TILE8 18
# define NB_TILES 8
# define NB_UI 9
# define COLOR_OFF 0x00000088
# define COLOR_ON 0x000000AA

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../libft/libft.h"
# include "../libmath/include/libmath.h"
# include "2d_struct.h"

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
	t_vector_2d		vector;
	double			a;
	double			b;
	double			*dist;
	double			*xray;
	int				*orientation;
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

typedef struct 		s_textures
{
	SDL_Surface		*current;
	SDL_Surface		**tab;
	SDL_Surface		**tabDev;
	SDL_Texture		*ttab[NB_TILES];
	SDL_Surface		*sky;
}					t_textures;

typedef struct		s_map
{
	int				**tab;
	int				len_x;
	int				len_y;
	int				unit;
	int				tile;
	t_minimap		minimap;
}					t_map;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				width;
	int 			height;
}					t_rect;

typedef struct 		s_ui
{
	t_rect			rect;
	int				flag;
}					t_ui;

typedef struct		s_editor
{
	t_dot_2d		pos;
	int				drag;
	t_ui			ui[NB_UI];
	Uint32			ui_color[NB_UI];
	t_ui			map_ui[NB_MAP_UI];
	Uint32			map_ui_color[NB_MAP_UI];
	int				mouse_ui;
	int				selected_tile;
	t_vector_2d		vel;
}					t_editor;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	SDL_Surface		*texte;
	TTF_Font		*police;
	t_map			map;
	t_textures		textures;
	t_player		player;
	t_calculs		calculs;
	t_editor		editor;
	char			*name;
	int				choice;
	int				textures_mode;
	int				fd;
	int				width;
	int				height;
	t_dot_2d		mouse;
}					t_win;


void				draw_rect(t_win *win, t_rect rect);
void				draw_empty_rect(t_win *win, t_dot_2d pos, int width, int height);
void				draw_line(t_win *win, t_dot_2d p1, t_dot_2d p2, SDL_Renderer *image);
void				draw_txt(t_win *win, char *txt, SDL_Color color, SDL_Rect rect);
void				draw(t_win *win, t_calculs *calculs, t_textures *textures);
void				draw_compass(t_win *win);
void				calcul_compass(t_win *win);
SDL_Texture     	*create_t_from_s(SDL_Surface *surface, SDL_Renderer *rend);

int					ed_add_tile(int	x, int y, t_win *win, int tile);
int 				ed_export(t_map map);
int					ed_is_in_map(int x, int y, t_win *win);
void				ed_put_grid(t_win *win);
int 				ed_put_map(t_win *win);
int					ed_window_loop(t_win *win);
void 				ed_move(t_win *win);
int					mouse_motion(t_win *win, SDL_Event event);
int					pevent(t_win *win, SDL_Event event);
void				ed_keyboard_event(t_win *win);
void				ed_mouse_event(t_win *win);
void				ed_zoom(t_map *map, t_dot_2d *pos, int zoom);

int					ed_init_ui(t_win *win);
t_ui				*ed_add_ui(t_editor *editor, t_ui new_ui);
t_ui				ed_new_ui(t_rect rect, int flag);
int					ed_get_ui(t_dot_2d mpos, t_ui *ui, int	mouse_ui);
void    			ed_draw_ui(t_win *win, Uint32 *ui_color, t_ui *ui, SDL_Texture **texture);
int					ed_update_ui(t_ui *ui);
void				ed_update_ui_color(Uint32 *ui_color, int flag);

int					ed_init_map_ui(t_win win, t_ui *map_ui, Uint32 *map_ui_color);
int					ed_update_map_ui(t_win *win, t_editor *editor, t_dot_2d shift);
void				ed_update_map_ui_color(Uint32 *map_ui_color, int flag);
t_ui				ed_new_map_ui(t_rect rect, int flag);
int					ed_get_map_ui(t_dot_2d mpos, t_win *win, t_ui *map_ui);
void    			ed_draw_map_ui(t_win *win, Uint32 *map_ui_color, t_ui *map_ui);
int					ed_drag_x_shift(int x, int end, int unit);
int					ed_drag_y_shift(int y, int end, int unit);
int					**ed_resize_x(int **tab, int x_shift, t_len len, int drag_flag);
void				ed_scroll_resize_x(t_dot_2d *pos, int unit, int x_shift, int drag_flag);
int					**ed_resize_y(int **tab, int y_shift, t_len len, int drag_flag);
void				ed_scroll_resize_y(t_dot_2d *pos, int unit, int y_shift, int drag_flag);

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

void				raycasting(t_win *win, t_player *player, t_calculs *calculs);
double				calcul_dist(t_win *win, t_player *player, t_calculs *calculs);
int					collision(t_map *map, t_player *player);

#endif
