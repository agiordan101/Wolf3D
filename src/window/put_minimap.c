/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_minimap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 17:08:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 18:38:48 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void 	draw_tile(t_win *win, int i, int j, int unit)
{
	if (win->map.tab[i][j] != 0)
	{
		if (win->map.tab[i][j] == 1)
		{
			SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
			draw_rect(win, (t_dot_2d){
				j * unit - win->player.pos.x * unit + win->map.minimap.width / 2,
				i * unit - win->player.pos.y * unit + win->map.minimap.height / 2},
				unit, unit);
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
	i = (int)win->player.pos.y - 4;
	if (i < 0)
		i = 0;
	j = (int)win->player.pos.x - 4;
	imax = (int)win->player.pos.y + 4;
	jmax = (int)win->player.pos.x + 4;
	while (i < imax && i < win->map.len_y)
	{
		j = (int)win->player.pos.x - 4;;
		if (j < 0)
			j = 0;
		while (j < jmax && j < win->map.len_x)
		{
			draw_tile(win, i, j, unit);
			j++;
		}
		i++;
	}
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	draw_empty_rect(win, (t_dot_2d){win->map.minimap.x, win->map.minimap.y},
									win->map.minimap.width, win->map.minimap.height);
	draw_player(win, unit);
	return (1);
}