/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_minimap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 17:08:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 16:06:57 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void draw_tile(t_win *win, int i, int j, int unit)
{
	//printf("i = %d, j = %d\n", i, j);
	if (win->map.tab[i][j] != 0)
	{
		if (win->map.tab[i][j] == 1)
			SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
		else if (win->map.tab[i][j] == 2)
			SDL_SetRenderDrawColor(win->rend, 255, 0, 0, 255);
		draw_rect(win,
			  j * unit - (int)(win->pos.x),
			  i * unit - (int)(win->pos.y),
			  unit, unit);
		//printf("x = %d, y = %d\n", j * unit - (int)(win->pos.x), i * unit - (int)(win->pos.y));
	}
}

int put_minimap(t_win *win)
{
	int 	imax;
	int 	jmax;
	int 	i;
	int 	j;
	double	unit;

	unit = 10;

	i = (win->player.pos.y - win->map.minimap.height / 2) / unit;
	if (i < 0)
		i = 0;
	j = (win->player.pos.x - win->map.minimap.width / 2) / unit;
	imax = i + 1 + win->map.minimap.height / unit;
	jmax = j + win->map.minimap.width / unit;
	//printf("unit = %f, i = %d, j = %d | im = %d, jm = %d\n", unit, i, j, imax, jmax);
	while (i < imax && i < win->map.len_y)
	{
		j = win->pos.x / unit;
		if (j < 0)
			j = 0;
		while (j < jmax && j < win->map.len_x[i])
		{
			draw_tile(win, i, j, unit);
			j++;
		}
		i++;
	}
	return (1);
}