/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 11:24:44 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:08:05 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "map_editor.h"

int		put_map(t_win *win)
{
	int		imax;
	int		jmax;
	int		i;
	int		j;

	i = win->pos.y / win->map.unit;
	if (i < 0)
		i = 0;
	j = win->pos.x / win->map.unit;
	imax = i + 1 + win->height / win->map.unit;
	jmax = j + win->width / win->map.unit;
	while (i < imax && i < win->map.len_y)
	{
		j = win->pos.x / win->map.unit;
		if (j < 0)
			j = 0;
		while (j < jmax && j < win->map.len_x[i])
		{
			if (win->map.tab[i][j] == 1)
			{
				SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
				draw_rect(j * win->map.unit / 2 - win->pos.x, i * win->map.unit - win->pos.y, win->map.unit, win->map.unit, win->rend);
			}
			if (win->map.tab[i][j] == 2)
			{
				SDL_SetRenderDrawColor(win->rend, 255, 0, 0, 255);
				draw_rect(j * win->map.unit / 2 - win->pos.x, i * win->map.unit - win->pos.y, win->map.unit, win->map.unit, win->rend);
			}
			j++;
		}
		i++;
	}
	return (1);
}