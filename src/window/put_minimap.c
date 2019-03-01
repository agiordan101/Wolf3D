/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_minimap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 17:08:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 22:38:00 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void 	draw_tile(t_win *win, int i, int j, int unit)
{
	int 	x;
	int		y;
	int		x_unit;
	int		y_unit;

	x_unit = unit;
	y_unit = unit;
	if (win->map.tab[i][j] != 0)
	{
		if (win->map.tab[i][j] == 1)
		{
			x = win->map.minimap.x + j * unit - win->player.pos.x * unit + win->map.minimap.width / 2;
			y = win->map.minimap.y + i * unit - win->player.pos.y * unit + win->map.minimap.height / 2;
			if (x < win->map.minimap.x)
			{
				x_unit -= win->map.minimap.x - x;
				x = win->map.minimap.x;
			}
			else if (x + x_unit > win->map.minimap.x + win->map.minimap.width)
			{
				x_unit -= x + unit - (win->map.minimap.x + win->map.minimap.width);
			}
			if (x_unit < 0)
				x_unit = 0;
			if (y < win->map.minimap.y)
			{
				y_unit -= win->map.minimap.y - y;
				y = win->map.minimap.y;
			}
			else if (y + y_unit > win->map.minimap.y + win->map.minimap.height)
			{
				y_unit -= y + unit - (win->map.minimap.y + win->map.minimap.height);
			}
			if (y_unit < 0)
				y_unit = 0;
			SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
			draw_rect(win, (t_dot_2d){
				x,
				y},
				x_unit, y_unit);
		}
	}
}

static void		draw_player(t_win *win, int unit)
{
	SDL_SetRenderDrawColor(win->rend, 255, 0, 0, 255);
	draw_rect(win, (t_dot_2d){
		win->map.minimap.x + win->map.minimap.width / 2 - unit / 4,
		win->map.minimap.y + win->map.minimap.height / 2 - unit / 4},
		unit / 2,
		unit / 2);
}

int				put_minimap(t_win *win)
{
	int 	imax;
	int 	jmax;
	int 	i;
	int 	j;
	double	unit;
	
	unit = win->map.minimap.width / 8;
	i = (int)win->player.pos.y - ((int)(win->map.minimap.height / 2 / unit) + 1);
	if (i < 0)
		i = 0;
	j = (int)win->player.pos.x - (int)(win->map.minimap.width / 2 / unit);
	imax = (int)win->player.pos.y + ((int)(win->map.minimap.height / 2 / unit) + 2);
	jmax = (int)win->player.pos.x + (int)(win->map.minimap.width / 2 / unit) + 1;
	while (i < imax && i < win->map.len_y)
	{
		j = (int)win->player.pos.x - (int)(win->map.minimap.width / 2 / unit);
		if (j < 0)
			j = 0;
		while (j < jmax && j < win->map.len_x)
			draw_tile(win, i, j++, unit);
		i++;
	}
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	draw_empty_rect(win, (t_dot_2d){win->map.minimap.x, win->map.minimap.y},
									win->map.minimap.width, win->map.minimap.height);
	draw_player(win, unit);
	return (1);
}