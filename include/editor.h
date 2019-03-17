/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 16:58:48 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:42:38 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

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

# include "../libmath/include/libmath.h"
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../libft/libft.h"
# include "../libmath/include/libmath.h"

typedef struct		s_ui
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

#endif
