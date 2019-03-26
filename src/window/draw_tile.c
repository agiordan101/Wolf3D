/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_tile.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 20:39:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:52:48 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_norme_bis(t_win *win, t_dot_2d pos, t_dot_2d unit)
{
	if (pos.y < win->map.minimap.y)
	{
		unit.y -= win->map.minimap.y - pos.y;
		pos.y = win->map.minimap.y;
	}
	else if (pos.y + unit.y > win->map.minimap.y + win->map.minimap.height)
	{
		unit.y -= pos.y + unit.y - (win->map.minimap.y
				+ win->map.minimap.height);
	}
	if (unit.y < 0)
		unit.y = 0;
	SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
	draw_rect(win, (t_rect){
		pos.x,
		pos.y,
		unit.x, unit.y});
}

static void		draw_norme(t_win *win, t_dot_2d index, t_dot_2d unit)
{
	t_dot_2d	pos;

	pos.x = win->map.minimap.x + index.x * unit.x
			- win->player.pos.x * unit.x + win->map.minimap.width / 2;
	pos.y = win->map.minimap.y + index.y * unit.y
			- win->player.pos.y * unit.y + win->map.minimap.height / 2;
	if (pos.x < win->map.minimap.x)
	{
		unit.x -= win->map.minimap.x - pos.x;
		pos.x = win->map.minimap.x;
	}
	else if (pos.x + unit.x > win->map.minimap.x + win->map.minimap.width)
		unit.x -= pos.x + unit.x - (win->map.minimap.x
					+ win->map.minimap.width);
	if (unit.x < 0)
		unit.x = 0;
	draw_norme_bis(win, pos, unit);
}

void			draw_tile(t_win *win, int i, int j)
{
	t_dot_2d	unit;
	t_dot_2d	index;

	index.x = j;
	index.y = i;
	unit.x = win->map.minimap.x_unit;
	unit.y = win->map.minimap.y_unit;
	if (win->map.tab[i][j] != 0)
	{
		if (win->map.tab[i][j] != 0 && win->map.tab[i][j] != PLAYER_TILE)
		{
			draw_norme(win, index, unit);
		}
	}
}
