/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_editor.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 10:00:12 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 15:27:42 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# include <stdio.h>
# include <stdlib.h>
# include "../../SDL/include/SDL2/SDL.h"
# include "../../libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;

}					t_point;

typedef struct		s_map
{
	int				**tab;
	int				*len_x;
	int				len_y;
	int				width;
	int				height;
	int				unit;
}					t_map;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	t_point			pos;
	t_map			map;
	int				width;
	int				height;
}					t_win;

int			parser(int const fd, t_map *map);
int			parser_error(int error);
int			open_window(SDL_Window **win_ptr, SDL_Renderer **rend);
int			window_loop(t_win *win);
int			quit(t_win *win);

int			put_map(t_win *win);
void		line_put(t_point p1, t_point p2, SDL_Renderer *rend);
void		draw_rect(int x, int y, int width, int height, SDL_Renderer *rend);

#endif