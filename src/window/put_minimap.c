/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_minimap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 17:08:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 19:16:34 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_player(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 255, 0, 0, 255);
	draw_rect(win, (t_rect){
		win->map.minimap.x + win->map.minimap.width / 2
							- win->map.minimap.x_unit / 4,
		win->map.minimap.y + win->map.minimap.height / 2
							- win->map.minimap.y_unit / 4,
		win->map.minimap.x_unit / 2,
		win->map.minimap.y_unit / 2});
}

static void		static_draw_player(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 255, 0, 0, 255);
	draw_rect(win, (t_rect){
		win->map.minimap.x + win->player.pos.x * win->map.minimap.x_unit
					- win->map.minimap.x_unit / 4,
		win->map.minimap.y + win->player.pos.y * win->map.minimap.y_unit
					- win->map.minimap.x_unit / 4,
		win->map.minimap.x_unit / 2,
		win->map.minimap.y_unit / 2});
}

static void		static_draw_tile(t_win *win, int i, int j)
{
	int		x;
	int		y;
	int		x_unit;
	int		y_unit;

	x_unit = win->map.minimap.x_unit;
	y_unit = win->map.minimap.y_unit;
	if (win->map.tab[i][j] != 0)
	{
		if (win->map.tab[i][j] != 0 && win->map.tab[i][j] != PLAYER_TILE)
		{
			x = win->map.minimap.x + j * x_unit;
			y = win->map.minimap.y + i * y_unit;
			if (x_unit < 0)
				x_unit = 0;
			if (y_unit < 0)
				y_unit = 0;
			SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
			draw_rect(win, (t_rect){
				x,
				y,
				x_unit, y_unit});
		}
	}
}

void			put_minimap_norme(t_win *win, int i, int j, t_dot_2d max)
{
	while (i < max.y && i < win->map.len_y)
	{
		j = (!win->map.minimap.static_map) ? (int)win->player.pos.x
		- (int)(win->map.minimap.width / 2 / win->map.minimap.x_unit) : 0;
		if (j < 0)
			j = 0;
		while (j < max.x && j < win->map.len_x)
		{
			if (win->map.minimap.static_map)
				static_draw_tile(win, i, j++);
			else
				static_draw_tile(win, i, j++);
		}
		i++;
	}
}

int				put_minimap(t_win *win)
{
	t_dot_2d	max;
	int			i;
	int			j;

	i = (!win->map.minimap.static_map) ? (int)win->player.pos.y
	- ((int)(win->map.minimap.height / 2 / win->map.minimap.y_unit) + 1) : 0;
	if (i < 0)
		i = 0;
	j = (!win->map.minimap.static_map) ? (int)win->player.pos.x
		- (int)(win->map.minimap.width / 2 / win->map.minimap.x_unit) : 0;
	max.y = (!win->map.minimap.static_map) ? (int)win->player.pos.y
	+ ((int)(win->map.minimap.height / 2 /
	win->map.minimap.y_unit) + 2) : win->map.len_y;
	max.x = (!win->map.minimap.static_map) ? (int)win->player.pos.x
	+ (int)(win->map.minimap.width / 2 /
	win->map.minimap.x_unit) + 1 : win->map.len_x;
	put_minimap_norme(win, i, j, max);
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	draw_empty_rect(win, (t_dot_2d){win->map.minimap.x, win->map.minimap.y},
	win->map.minimap.width, win->map.minimap.height);
	if (win->map.minimap.static_map)
		static_draw_player(win);
	else
		draw_player(win);
	return (1);
}
