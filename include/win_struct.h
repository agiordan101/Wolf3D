/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   win_struct.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 18:39:15 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:05:38 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WIN_STRUCT_H
# define WIN_STRUCT_H
# define N_SURFACE 6

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../libft/libft.h"
# include "../libmath/include/libmath.h"
# include "editor.h"

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
	SDL_Surface		*tab[N_SURFACE];
	SDL_Surface		*tabDev[N_SURFACE];
	SDL_Texture		*ttab[NB_TILES];
	SDL_Texture		*sky;
	SDL_Rect		skyrect;
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

#endif